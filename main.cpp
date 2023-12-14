#include <imguiWidget/imguiWindow.h>
#include <imguiWidget/imguiWidgetButton.h>
#include <imguiWidget/imguiLayout.h>

#include <memory>

void func()
{
    std::cout<<"Hello from b3"<<std::endl;
}

int func1()
{
    std::cout<<"Hello from b2"<<std::endl;
    return 0;
}

int main()
{
    imguiWindow window;
    auto layout = std::make_shared<imguiLayout> (LayoutType::LayoutType_Vertical);
    auto layout2 = std::make_shared<imguiLayout> (LayoutType::LayoutType_Vertical);
    auto layout3 = std::make_shared<imguiLayout> (LayoutType::LayoutType_Vertical);

    window.setLayout(layout.get());

    auto b1 = std::make_shared<imguiWidgetButton> ("Button1");
    auto b2 = std::make_shared<imguiWidgetButton> ("Button2");
    auto b3 = std::make_shared<imguiWidgetButton> ("Button3");
    auto b4 = std::make_shared<imguiWidgetButton> ("Button4");

    b2->setSize({600, 300}, true);

    b1->setCallback([](){
        std::cout<<"Hello from b1"<<std::endl;
    });

    b2->setCallback(func1);

    b3->setCallback(func);

    layout->addWidget(b1.get());
    layout->addWidget(layout2.get());
    layout2->addWidget(b2.get());
    layout2->addWidget(layout3.get());
    layout3->addWidget(b3.get());
    layout3->addWidget(b4.get());

    return window.draw();
}