#pragma once

#include <imguiWidget/imguiObject.h>

class imguiWidget : private imguiObject
{
public:
    imguiWidget() = default;
    ~imguiWidget() = default;
    int draw(const imguiObject*) override
    {
        return 0;
    }
private:
};