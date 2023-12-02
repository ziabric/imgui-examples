#pragma once

#include <vector>
#include <string>
#include <memory>
#include <utility>

using objectSize = std::pair<int, int>;
using objectPos = std::pair<int, int>;

class imguiObject
{
public:
    imguiObject() = default;
    ~imguiObject() = default;
    objectSize getSize()
    {
        return size_;
    }
    objectPos getPos()
    {
        return pos_;
    }
    void setSize(const objectSize& size)
    {
        size_ = size;
    }
    void setPos(const objectPos& pos)
    {
        pos_ = pos;
    }
    virtual int draw(const imguiObject* parent = nullptr)
    {
        if ( parent == nullptr )
        {
            pos_ = {0,0};
            size_ = globalWindwSize_;
        }
    }
    virtual int draw(objectPos newPos, objectSize newSize)
    {
        pos_ = newPos;
        size_ = newSize;
    }
private:
    objectSize size_ = {0,0};
    objectPos pos_ = {0,0};
    static objectSize globalWindwSize_;
};