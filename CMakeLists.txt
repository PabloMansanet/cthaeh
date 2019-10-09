cmake_minimum_required(VERSION 3.6)
project(cthaeh)
enable_language(C CXX ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(Sources.cmake)

add_library(imgui imgui/imgui.cpp imgui/imgui_widgets.cpp imgui/imgui_draw.cpp)
add_library(imgui-sfml imgui-sfml/imgui-SFML.cpp)
add_executable(tak ${TAK_SOURCES})
add_executable(tests tests/tests.board.cpp)
target_link_libraries(tak imgui imgui-sfml)

set (SFML_LIBRARIES sfml-window sfml-system sfml-graphics)
target_link_libraries(tak ${SFML_LIBRARIES} GL)

set(CMAKE_CXX_STANDARD 14)

if (NOT NO_GNU_FLAGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -g")
endif()

