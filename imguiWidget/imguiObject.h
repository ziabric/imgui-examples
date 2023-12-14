#pragma once

#include <vector>
#include <string>
#include <memory>
#include <utility>

using objectSize = std::pair<int, int>;

class imguiObject
{
public:
    imguiObject() = default;
    ~imguiObject() = default;
    objectSize getSize() const
    {
        return size_;
    }
    void setSize(const objectSize& size, bool hasCustomSize = false)
    {
        customSize_ = hasCustomSize;
        size_ = size;
    }
    bool getSizeStatus() const { return customSize_;}
    virtual int draw(objectSize newSize) = 0;

private:
    objectSize size_ = {-1,-1};
    bool customSize_ = false;
};
