cmake_minimum_required(VERSION 3.21)
project(c-Gamedev LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Define the source files and header files separately
set(SOURCES
    src/main.cpp 
    src/Player.cpp
    src/Game.cpp
    src/Configuration.cpp
    src/Action.cpp
)

set(HEADERS
    include/Player.hpp
    include/Game.hpp
    include/Configuration.hpp
    include/ResourceManager.hpp
    include/Action.hpp
    include/ActionMap.hpp
    include/ActionTarget.hpp
    include/Player.tpl
    include/ActionMap.tpl
    include/ActionTarget.tpl
    include/World.hpp
)

# Create the executable target and link libraries
add_executable(c-Gamedev ${SOURCES} ${HEADERS})
target_link_libraries(c-Gamedev PRIVATE sfml-graphics)
target_compile_features(c-Gamedev PRIVATE cxx_std_17)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET c-Gamedev POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:c-Gamedev> $<TARGET_FILE_DIR:c-Gamedev> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS c-Gamedev)
