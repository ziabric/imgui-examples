#pragma once

#include <vector>
#include <string>
#include <memory>
#include <utility>

using objectSize = std::pair<int, int>;

static objectSize globalWindwSize_ = {0,0};

class imguiObject
{
public:
    imguiObject() = default;
    ~imguiObject() = default;
    objectSize getSize() const
    {
        return size_;
    }
    void setSize(const objectSize& size)
    {
        size_ = size;
    }
    virtual int draw(const imguiObject* parent = nullptr)
    {
        if ( parent == nullptr )
        {
            size_ = globalWindwSize_;
        }
    }
    virtual int draw(objectSize newSize)
    {
        size_ = newSize;
    }

private:
    objectSize size_ = {-1,-1};
};
