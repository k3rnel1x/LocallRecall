cmake_minimum_required(VERSION 4.0.0)

project(LocallRecall)

link_libraries(
        X11
)
set(SOURCES main.cpp
    screenshot_system/x11ScreenShotSystem/End.cpp
    screenshot_system/x11ScreenShotSystem/getActiveWindow.cpp
    screenshot_system/x11ScreenShotSystem/Init.cpp
    screenshot_system/x11ScreenShotSystem/takeScreenshot.cpp
    screenshot_system/x11ScreenShotSystem/x11ScreenShotSystem.h
)

add_executable(main ${SOURCES})