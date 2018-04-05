cmake_minimum_required(VERSION 3.1)
project(urdf_editor)
find_package(catkin REQUIRED COMPONENTS rviz roscpp qt_property_browser)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

find_package(urdfdom REQUIRED)

if(POLICY CMP0071)
    cmake_policy(SET CMP0071 NEW)
endif()

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 14)

set(DCMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

set(editor_SRCS
#     src/my_rviz.cpp
      src/main.cpp
      src/urdf_editor.cpp
      src/common.cpp
      src/joint_property.cpp
      src/link_property.cpp
      src/urdf_property.cpp
)

set(editor_HDRS
      include/urdf_editor/urdf_editor.h
      include/urdf_editor/joint_property.h
      include/urdf_editor/link_property.h
      include/urdf_editor/urdf_property.h
#     include/urdf_editor/my_rviz.h
)

set(editor_UIS
      include/urdf_editor/industrial_robot_builder.ui
)

set(editor_INCLUDE_DIRECTORIES
      include
      ${CMAKE_CURRENT_BINARY_DIR}
)

catkin_package(
  INCLUDE_DIRS #${editor_INCLUDE_DIRECTORIES}
  LIBRARIES
  CATKIN_DEPENDS roscpp qt_property_browser
  DEPENDS urdfdom
)

qt5_wrap_cpp(editor_MOCS ${editor_HDRS})
qt5_wrap_ui(editor_UIS_H ${editor_UIS})

include_directories(${editor_INCLUDE_DIRECTORIES} ${catkin_INCLUDE_DIRS} ${QT_INCLUDE_DIR} ${urdfdom_INCLUDE_DIR})

add_executable(urdf_editor
                  ${editor_UIS_H}
                  ${editor_MOCS}
                  ${editor_SRCS})

qt5_use_modules(urdf_editor Core Widgets Gui)

target_link_libraries(urdf_editor
                        ${catkin_LIBRARIES}
                        ${urdfdom_LIBRARIES}
                        ${QT_LIBRARIES})

## Install
#install(TARGETS urdf_editor DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
