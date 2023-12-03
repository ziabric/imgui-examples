#pragma once

#include <imguiWidget/imguiWidget.h>
#include <imguiWidget/imguiObject.h>

#include <imgui.h>

#include <utility>

class imguiWidgetButton : public imguiWidget
{
public:
    explicit imguiWidgetButton(std::string  text, auto lambda = [](){}) : text_(std::move(text))
    {

    }
    int draw(const imguiObject* parent = nullptr) override
    {
//        if (nullptr == parent)
//        {
//            this->
//        }
        auto size = getSize();
        if (ImGui::Button(text_.c_str(), {(float)size.first, (float)size.second}))
        {

        }
    }
private:
    std::string text_ = "";
};