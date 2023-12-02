//#include <imgui/imgui.h>
//#include <imgui/imgui-SFML.h>
//
//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/System/Clock.hpp>
//#include <SFML/Window/Event.hpp>
//#include <SFML/Network.hpp>
//
//#include <vector>
//#include <string>
//#include <cmath>

#include <imguiWidget/imguiWindow.h>

//void draw_table(std::vector<std::vector<std::string> > &table, const std::string& title = "Table", ImGuiTableFlags flags = ImGuiTableFlags_None)
//{
//    if ( !table.empty() )
//    {
//        if ( table.at(0).empty() ) return;
//    } else return;
//
//    if ( 1 == ImGui::BeginTable(title.c_str(), (int)table.at(0).size(), flags))
//    {
//        for ( std::string &item : table.at(0) )
//        {
//            ImGui::TableSetupColumn(item.c_str());
//        }
//
//        for ( std::vector<std::string> &column : table )
//        {
//            for (std::string &item : column)
//            {
//                ImGui::TableNextColumn();
//                ImGui::Text("%s", item.c_str());
//            }
//        }
//        ImGui::EndTable();
//    }
//}
//
//
//float value_oX = 0;
//float value_oY = 0;
//
//void display(ImVec2 size)
//{
//    ImGui::Begin("Example", nullptr, ImGuiWindowFlags_NoResize + ImGuiWindowFlags_NoTitleBar + ImGuiWindowFlags_NoMove);
//    ImGui::SetWindowPos({0,0});
//    ImGui::SetWindowSize({size.x,size.y});
//
//    auto drawList = ImGui::GetWindowDrawList();
//    int width = 120;
//
//    ImGui::SliderAngle("Slider_oX", &value_oX, -16000, 16000);
//    ImGui::SliderAngle("Slider_oY", &value_oY, -16000, 16000);
//
//    float angle_oX = value_oX * 9 / 1600;
//    float x = (std::sin(angle_oX) * 120);
//    ImVec2 center_oX = {ImGui::GetWindowPos().x + 300,ImGui::GetWindowPos().y + 100};
//    int Y_oX = (int)center_oX.y;
//    drawList->AddLine(center_oX, {center_oX.x + (float)width, (float)Y_oX + x}, ImColor(237, 60, 202), 4);
//    drawList->AddLine(center_oX, {center_oX.x - (float)width, (float)Y_oX - x}, ImColor(237, 60, 202), 4);
//
//    float angle_oY = value_oY * 9 / 1600;
//    float y = (std::sin(angle_oY) * 120);
//    ImVec2 center_oY = {ImGui::GetWindowPos().x + 300,ImGui::GetWindowPos().y + 400};
//    int Y_oY = (int)center_oY.y;
//    drawList->AddLine(center_oY, {center_oY.x + (float)width, (float)Y_oY + y}, ImColor(0, 127, 255), 4);
//    drawList->AddLine(center_oY, {center_oY.x - (float)width, (float)Y_oY - y}, ImColor(0, 127, 255), 4);
//
//
//
//    ImGui::End();
//}

int main()
{
    imguiWindow window;
    return window.run();
}
