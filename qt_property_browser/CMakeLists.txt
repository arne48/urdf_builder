cmake_minimum_required(VERSION 3.1)
project(qt_property_browser)

find_package(catkin REQUIRED)

find_package(Qt5Widgets REQUIRED)

if(POLICY CMP0071)
    cmake_policy(SET CMP0071 NEW)
endif()

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(qtpropertyeditor_INCLUDE_DIRECTORIES
      src)

set(_SRCS
        src/qtbuttonpropertybrowser.cpp
        src/qteditorfactory.cpp
        src/qtgroupboxpropertybrowser.cpp
        src/qtpropertybrowser.cpp
        src/qtpropertybrowserutils.cpp
        src/qtpropertymanager.cpp
        src/qttreepropertybrowser.cpp
        src/qtvariantproperty.cpp
        )

file(GLOB _IMPL_HDRS *.h)
file(GLOB _PUBLIC_HDRS Qt*)

set(_UI_FORMS
        )

set(_RESOURCES
        src/qtpropertybrowser.qrc
        )

QT5_WRAP_UI(_UI_SRCS ${_UI_FORMS})
QT5_ADD_RESOURCES(_QRC_SRCS ${_RESOURCES})

set(TARGET_NAME ${PROJECT_NAME})

catkin_package(
        INCLUDE_DIRS ${qtpropertyeditor_INCLUDE_DIRECTORIES}
        LIBRARIES qt_property_browser
        CATKIN_DEPENDS
        DEPENDS
)

add_library(${TARGET_NAME}
        ${_SRCS}
        ${_UI_SRCS}
        ${_QRC_SRCS}
        ${_IMPL_HDRS}
        )

target_link_libraries(${TARGET_NAME} Qt5::Widgets)

######################### Installation Stuff ###########################
include(GenerateExportHeader)
generate_export_header(${TARGET_NAME})

install(TARGETS qt_property_browser DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
