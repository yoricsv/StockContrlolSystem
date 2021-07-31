cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

    set (PROJECT_NAME       StockControlSystem             )

    set (OUTPUT_DIRECTORY   "${CMAKE_BINARY_DIR}"          )

    set (MAJOR              "${PROJECT_NAME}_VERSION_MAJOR")
    set (MINOR              "${PROJECT_NAME}_VERSION_MINOR")
    set (PATCH              "${PROJECT_NAME}_VERSION_PATCH")
    set (TWEAK              "${PROJECT_NAME}_VERSION_TWEAK")
    set (VERSION            "${PROJECT_NAME}_VERSION"      )

    # specify version number
    set (${MAJOR}       1)
    set (${MINOR}       0)
    set (${PATCH}       0)
    set (${TWEAK}       0)
    set (${VERSION}
            "${MAJOR}"."${MINOR}"."${PATCH}"."${TWEAK}"
    )

project (
    ${PROJECT_NAME}
    ${VERSION}
    LANGUAGES CXX
)

    set (CMAKE_INCLUDE_CURRENT_DIR   ON)

    set (CMAKE_AUTOUIC               ON)
    set (CMAKE_AUTOMOC               ON)
    set (CMAKE_AUTORCC               ON)

    set (CMAKE_CXX_STANDARD          14)
    set (CMAKE_CXX_STANDARD_REQUIRED ON)

    set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${OUTPUT_DIRECTORY}")
#   set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")

add_definitions (-Wall -O2)

file (GLOB
    CPP_SOURCES "${PROJECT_NAME}/src/*.cpp"
    PRV_HEADERS "${PROJECT_NAME}/inc/private/*.h"
    PUB_HEADERS "${PROJECT_NAME}/inc/*.h"
)

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

find_package (
    QT
    NAMES
        Qt6
        Qt5
    COMPONENTS
        Widgets
    REQUIRED
)
find_package (
    Qt
    ${QT_VERSION_MAJOR}
    COMPONENTS
        Widgets
    REQUIRED
)


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
