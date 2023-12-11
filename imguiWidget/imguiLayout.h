#pragma once

#include <imguiWidget/imguiObject.h>

enum class LayoutType
{
    LayoutType_Horizontal = 0,
    LayoutType_Vertical,
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
        this->setSize(parent->getSize());

        if (objects_.size() == 1)
        {
            objects_.at(0)->draw(this);
        }
        else if (objects_.size() > 1)
        {
            int heightOfObject = 0;
            int widthOfObject = 0;
            int countTmp = 0;
            switch (type_)
            {
                case LayoutType::LayoutType_Vertical:
                    for ( auto object : objects_ )
                    {
                        if (object->getSize().second != -1)
                        {
                            countTmp += 1;
                            heightOfObject += object->getSize().second;
                        }
                    }
                    heightOfObject = (getSize().second - heightOfObject) / ((int)objects_.size() - countTmp);

                    for (auto object : objects_)
                    {
                        object->draw({object->getSize().first == -1 ? getSize().first : object->getSize().first, object->getSize().second == -1 ? heightOfObject : object->getSize().second});
                    }
                    break;
                case LayoutType::LayoutType_Horizontal:
                    for ( auto object : objects_ )
                    {
                        if (object->getSize().first != -1)
                        {
                            countTmp += 1;
                            widthOfObject += object->getSize().first;
                        }
                    }
                    widthOfObject = (getSize().first - widthOfObject) / ((int)objects_.size() - countTmp);

                    ImGui::Columns((int)objects_.size(), nullptr, false);
                    for (auto i = 0 ; i < objects_.size(); i += 1)
                    {
                        ImGui::SetColumnWidth(i, (float)(objects_.at(i)->getSize().first == -1 ? widthOfObject : objects_.at(i)->getSize().first));
                        //ImGui::SetColumnOffset(i, 30);
                        objects_.at(i)->draw({objects_.at(i)->getSize().first == -1 ? widthOfObject : objects_.at(i)->getSize().first, objects_.at(i)->getSize().second == -1 ? getSize().second : objects_.at(i)->getSize().second});
                        ImGui::NextColumn();
                    }
                    ImGui::Columns(1);
                    break;
            }
        }
        return 0;
    }
private:
    std::vector<imguiObject*> objects_ = {};
    LayoutType type_;
};