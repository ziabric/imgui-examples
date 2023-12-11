#include <imguiWidget/imguiWindow.h>
#include <imguiWidget/imguiWidgetButton.h>
#include <imguiWidget/imguiLayout.h>

#include <memory>

int main()
{
    imguiWindow window;
    auto layout = std::make_shared<imguiLayout> (LayoutType::LayoutType_Vertical);
    window.setLayout(layout.get());

    auto b1 = std::make_shared<imguiWidgetButton> ("Button1");
    auto b2 = std::make_shared<imguiWidgetButton> ("Button2");
    auto b3 = std::make_shared<imguiWidgetButton> ("Button3");

    b2->setSize({100, 300});

    layout->addWidget(b1.get());
    layout->addWidget(b2.get());
    layout->addWidget(b3.get());

    return window.draw();
}