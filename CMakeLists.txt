cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

    set (PROJECT_NAME     StockControlSystem)
    set (OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}")
    # setup version number
    set (PROJECT_VERSION_MAJOR 1)
    set (PROJECT_VERSION_MINOR 0)
    set (PROJECT_VERSION_PATCH 0)
    set (PROJECT_VERSION_TWEAK 0)

project (${PROJECT_NAME}  VERSION 1.0.0.0 LANGUAGES CXX)

    set (CMAKE_INCLUDE_CURRENT_DIR   ON)

    set (CMAKE_AUTOUIC               ON)
    set (CMAKE_AUTOMOC               ON)
    set (CMAKE_AUTORCC               ON)

    set (CMAKE_CXX_STANDARD          14)
    set (CMAKE_CXX_STANDARD_REQUIRED ON)

    set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${OUTPUT_DIRECTORY}")
#   set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package (QT NAMES    Qt6 Qt5    COMPONENTS Widgets REQUIRED)
find_package (Qt ${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


set (PROJECT_SOURCES
    src/main.cpp                inc/main.h
    src/warehousecontrol.cpp    inc/warehousecontrol.h    ui/warehousecontrol.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library    (${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable (${PROJECT_NAME}
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
