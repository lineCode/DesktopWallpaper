cmake_minimum_required(VERSION 3.1)

project(DesktopWallpaper)

add_executable(DesktopWallpaper
    BasisScherm.cpp
    Button.cpp
    CommonControl.cpp
    Control.cpp
    CustomControl.cpp
    LeftPanel.cpp
    List.cpp
    Main.cpp
    MainPanel.cpp
    SystrayIcon.cpp
    resource.rc
    )

target_compile_features(DesktopWallpaper
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_include_directories(DesktopWallpaper
    PRIVATE system.io/include
    PRIVATE stb
    )
