cmake_minimum_required(VERSION 3.30.5)

project(rpg-cpp)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.c"
    )

# set(SOURCE_FILES
#     main.cpp
#     abilities.cpp
#     character_classes.cpp
#     game.cpp
#     item_classes.cpp
#     utils.cpp)

# add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_executable(${PROJECT_NAME} ${all_SRCS})