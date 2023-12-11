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
    auto layout = std::make_shared<imguiLayout> (LayoutType::LayoutType_Horizontal);
    window.setLayout(layout.get());

    auto b1 = std::make_shared<imguiWidgetButton> ("Button1");
    auto b2 = std::make_shared<imguiWidgetButton> ("Button2");
    auto b3 = std::make_shared<imguiWidgetButton> ("Button3");

    b2->setSize({100, 300});

    b1->setCallback([](){
        std::cout<<"Hello from b1"<<std::endl;
    });

    b2->setCallback(func1);

    b3->setCallback(func);

    layout->addWidget(b1.get());
    layout->addWidget(b2.get());
    layout->addWidget(b3.get());

    return window.draw();
}