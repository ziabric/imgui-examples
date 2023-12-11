#pragma once

#include <imguiWidget/imguiWidget.h>
#include <imguiWidget/imguiObject.h>

#include <imgui.h>

#include <iostream>
#include <utility>

#include <functional>

class imguiWidgetButton : public imguiObject
{
public:
    explicit imguiWidgetButton(std::string  text) : text_(std::move(text))
    {

    }
    void setCallback(std::function<void()> callback)
    {
        callback_ = std::move(callback);
    }

    int draw(const imguiObject* parent = nullptr) override
    {
        auto size = getSize();
        if (ImGui::Button(text_.c_str(), {(float)size.first, (float)size.second}))
        {
            callback_();
        }
    }
    int draw(objectSize newSize) override
    {
        if ( ImGui::Button(text_.c_str(), {(float)newSize.first, (float)newSize.second}) )
        {
            callback_();
        }
    }
private:
    std::string text_ = "";
    std::function<void()> callback_ = [](){};
};