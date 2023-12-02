cmake_minimum_required(VERSION 3.6)

project(imguiWidget VERSION 1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories( ${PROJECT_SOURCE_DIR}/ )
include_directories( ${PROJECT_SOURCE_DIR}/include )
include_directories( ${PROJECT_SOURCE_DIR}/imgui )

find_package(X11 REQUIRED)
find_package(SFML COMPONENTS system graphics audio network REQUIRED)

set(IMGUI
        imgui/imconfig.h
        imgui/imgui.cpp
        imgui/imgui.h
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_internal.h
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imstb_rectpack.h
        imgui/imstb_textedit.h
        imgui/imstb_truetype.h
        imgui/imconfig-SFML.h
        imgui/imgui-SFML.cpp
        imgui/imgui-SFML.h
        imgui/imgui-SFML_export.h
)

set(SOURCES
        main.cpp
)

set(IMGUIWIDGETS
        imguiWidget/imguiWindow.h
        imguiWidget/imguiObject.h
        imguiWidget/imguiLayout.h
        imguiWidget/imguiWidget.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${IMGUI} ${IMGUIWIDGETS})

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window sfml-network sfml-graphics sfml-system opengl32 websockets)
endif()

if(UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window sfml-network sfml-graphics sfml-system GL websockets X11::X11)
endif()
