cmake_minimum_required(VERSION 3.25)
project(BattleBay_tool_v2_0)

set(CMAKE_CXX_STANDARD 23)

#set(CMAKE_AUTOMOC ON) # Automatically process Q_OBJECT macro
#set(CMAKE_AUTORCC ON) # Automatically process Qt resources
#set(CMAKE_AUTOUIC ON) # Automatically process UI files


set(FLTK_DIR "/usr/include/FL")

add_executable(BattleBay_tool_v2_0 main.cpp
)
#find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(FLTK REQUIRED)

include_directories(${FLTK_INCLUDE_DIR})
target_link_libraries(BattleBay_tool_v2_0 ${FLTK_LIBRARIES})
#target_link_libraries(BattleBay_tool_v2_0 Qt5::Widgets)