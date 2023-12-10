/*
#include <imguiWidget/imguiWindow.h>
#include <imguiWidget/imguiWidgetButton.h>
#include <imguiWidget/imguiLayout.h>

int main()
{
    imguiWindow window;
    imguiLayout layout(LayoutType::LayoutType_Vertical);
    window.setLayout(layout);

    imguiWidgetButton b1("Button1");
    imguiWidgetButton b2("Button2");

    layout.addWidget(&b1);
    layout.addWidget(&b2);

    return window.draw();
}
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

char buff1[1024] = "";
char buff2[1024] = "";

void display(ImVec2 size)
{
    ImGui::Begin("Title", nullptr, ImGuiWindowFlags_NoMove + ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_NoResize);
    ImGui::SetWindowPos({0,0});
    ImGui::SetWindowSize(size);


    auto style = &ImGui::GetStyle();

    style->WindowPadding = ImVec2(0, 0);
    style->FramePadding = ImVec2(0, 0);
    style->ItemSpacing = ImVec2(0, 0);
    style->FrameBorderSize = 0.0f;

    int n = 2;

    auto flags1 = ImGuiInputTextFlags_None;
    ImGui::InputTextMultiline("##InputText1", buff1, IM_ARRAYSIZE(buff1), {(float)size.x, (float)size.y/n},flags1);

    auto flags2 = ImGuiInputTextFlags_None;
    ImGui::InputTextMultiline("##InputText2", buff2, IM_ARRAYSIZE(buff2), {(float)size.x, (float)size.y/n},flags2);

    ImGui::End();
}

int main()
{
    auto window_ = sf::RenderWindow(sf::VideoMode(800, 480), "Window");
    window_.setFramerateLimit(100);

    if(ImGui::SFML::Init(window_))
    {
        ImGuiIO& io = ImGui::GetIO();
        ImFont* customFont = io.Fonts->AddFontFromFileTTF("font.ttf", 100.0f);
        if (!ImGui::SFML::UpdateFontTexture())
        {
            return 1;
        }

        sf::Clock deltaClock;
        while (window_.isOpen())
        {
            sf::Event event{};
            while (window_.pollEvent(event))
            {
                ImGui::SFML::ProcessEvent(window_, event);
                if (event.type == sf::Event::Closed)
                {
                    window_.close();
                }
            }
            ImGui::SFML::Update(window_, deltaClock.restart());
            ImGui::PushFont(customFont);


            display({(float)window_.getSize().x, (float)window_.getSize().y});

            ImGui::PopFont();
            window_.clear();
            ImGui::SFML::Render(window_);
            window_.display();
        }
        ImGui::SFML::Shutdown();
    }
}