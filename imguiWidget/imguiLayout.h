#pragma once

#include <imguiWidget/imguiObject.h>

enum class LayoutType
{
    LayoutType_Horizontal = 0,
    LayoutType_Vertical,
    LayoutType_Table
};

class imguiLayout : private imguiObject
{
public:
    imguiLayout(LayoutType type) : type_(type) {}
    ~imguiLayout() = default;
    void addWidget(imguiObject* object)
    {
        objects_.push_back(object);
    }
    void popWidget()
    {
        delete objects_.back();
        objects_.pop_back();
    }
    void clear()
    {
        while (!objects_.empty())
        {
            delete objects_.back();
            objects_.pop_back();
        }
    }
    int draw(const imguiObject* parent) override
    {
        if (objects_.size() == 1)
        {
            objects_.at(0)->draw(this);
        }
        else if (objects_.size() > 1)
        {
            objectPos posNextObject = this->getPos();
            switch (type_)
            {
                case LayoutType::LayoutType_Vertical:

                    int heightOfObject = this->getSize().second / objects_.size();

                    for (auto object : objects_)
                    {
                        object->draw();
                    }
                    break;
            }
        }
        return 0;
    }
private:
    std::vector<imguiObject*> objects_ = {};
    LayoutType type_ = LayoutType::LayoutType_Vertical;
};