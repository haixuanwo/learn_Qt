cmake_minimum_required(VERSION 3.5)

project(media_player LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8;/execution-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8;/execution-charset:utf-8>")


find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets SerialPort REQUIRED)

if(ANDROID)
  add_library(media_player SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(media_player
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    common.h
    common.cpp
    serial.h
    serial.cpp
  )
endif()

#target_link_libraries(media_player PRIVATE Qt5::Widgets Qt5::Multimedia Qt5::Multimediawidgets)
target_link_libraries(media_player PUBLIC Qt5::Widgets
    Qt5::Multimedia Qt5::MultimediaWidgets
    Qt5::SerialPort
)
