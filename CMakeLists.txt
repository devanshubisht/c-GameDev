cmake_minimum_required(VERSION 3.21)
project(c-Gamedev LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(c-Gamedev src/game.cpp src/player.cpp src/game.hpp src/main.cpp src/player.hpp)
target_link_libraries(c-Gamedev PRIVATE sfml-graphics)
target_compile_features(c-Gamedev PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET c-Gamedev POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:c-Gamedev> $<TARGET_FILE_DIR:c-Gamedev> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS c-Gamedev)