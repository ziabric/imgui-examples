#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Network.hpp>

#include <memory>

#include <imguiWidget/imguiObject.h>
#include <imguiWidget/imguiLayout.h>
#include <imguiWidget/imguiWidget.h>


class imguiWindow
{
public:
    imguiWindow()
    {
        window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 480), "Window");
        window_->setFramerateLimit(100);
    }
    ~imguiWindow() = default;

    int draw()
    {
        if(ImGui::SFML::Init(*window_))
        {
            ImGuiIO& io = ImGui::GetIO();
            ImFont* customFont = io.Fonts->AddFontFromFileTTF("font.ttf", 100.0f);
            customFont->Scale = 0.15;
            if (!ImGui::SFML::UpdateFontTexture())
            {
                return 1;
            }

            sf::Clock deltaClock;
            while (window_->isOpen())
            {
                sf::Event event{};
                while (window_->pollEvent(event))
                {
                    ImGui::SFML::ProcessEvent(*window_, event);
                    if (event.type == sf::Event::Closed)
                    {
                        window_->close();
                    }
                }
                ImGui::SFML::Update(*window_, deltaClock.restart());
                ImGui::PushFont(customFont);

                ImGui::Begin("Title", nullptr, ImGuiWindowFlags_NoMove + ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_NoResize);
                ImGui::SetWindowPos({0,0});
                ImGui::SetWindowSize({(float)window_->getSize().x, (float)window_->getSize().y});

                auto style = &ImGui::GetStyle();

                style->WindowPadding = ImVec2(0, 0);
                style->FramePadding = ImVec2(0, 0);
                style->ItemSpacing = ImVec2(0, 0);
                style->FrameBorderSize = 0.0f;

                setSize({window_->getSize().x, window_->getSize().y});

                layout_->draw(getSize());

                ImGui::End();

                ImGui::PopFont();
                window_->clear();
                ImGui::SFML::Render(*window_);
                window_->display();
            }
            ImGui::SFML::Shutdown();
        }
        return 0;
    }

    void setSize(objectSize newSize)
    {
        size_ = newSize;
    }
    objectSize getSize()
    {
        return size_;
    }

    void setLayout(imguiLayout* layout)
    {
        layout_ = layout;
    }

private:
    std::shared_ptr<sf::RenderWindow> window_;
    imguiLayout* layout_{};
    objectSize size_ = {0,0};
};