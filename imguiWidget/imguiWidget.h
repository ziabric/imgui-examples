#pragma once

#include <imguiWidget/imguiObject.h>

class imguiWidget : public imguiObject
{
public:
    imguiWidget() = default;
    ~imguiWidget() = default;

    int draw(objectSize newSize) override = 0;

private:
};