#pragma once

#include <imguiWidget/imguiWidget.h>
#include <imguiWidget/imguiObject.h>

#include <imgui.h>

#include <iostream>
#include <utility>

class imguiWidgetButton : public imguiObject
{
public:
    explicit imguiWidgetButton(std::string  text) : text_(std::move(text))
    {

    }
    int draw(const imguiObject* parent = nullptr) override
    {
        auto size = getSize();
        if (ImGui::Button(text_.c_str(), {(float)size.first, (float)size.second}))
        {
            std::cout<<"Check"<<std::endl;
        }
    }
    int draw(objectSize newSize) override
    {
        if ( ImGui::Button(text_.c_str(), {(float)newSize.first, (float)newSize.second}) )
        {
            std::cout<<newSize.first<<" -- "<<newSize.second<<std::endl;
        }
    }
private:
    std::string text_ = "";
};