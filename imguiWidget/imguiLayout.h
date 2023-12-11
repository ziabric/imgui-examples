#pragma once

#include <imguiWidget/imguiObject.h>

enum class LayoutType
{
    LayoutType_Horizontal = 0,
    LayoutType_Vertical,
    LayoutType_Table
};

class imguiLayout : public imguiObject
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
        size_ = parent->size_;

        if (objects_.size() == 1)
        {
            objects_.at(0)->draw(this);
        }
        else if (objects_.size() > 1)
        {
            switch (type_)
            {
                case LayoutType::LayoutType_Vertical:

                    int heightOfObject = this->getSize().second / objects_.size();

                    for (auto object : objects_)
                    {
                        object->draw({object->size_.first == -1 ? getSize().first : object->size_.first, object->size_.second == -1 ? heightOfObject : object->size_.second});
                    }
                    break;
            }
        }
        return 0;
    }
private:
    std::vector<imguiObject*> objects_ = {};
    LayoutType type_;
};