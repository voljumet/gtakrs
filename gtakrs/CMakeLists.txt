cmake_minimum_required(VERSION 3.14)
project(GTAKRS)

set(CMAKE_CXX_STANDARD 14)

add_executable(GTAKRS main.cpp State.h StateMachine.cpp StateMachine.h AssetManager.cpp AssetManager.h InputManager.cpp InputManager.h Game.cpp Game.h DEFINITIONS.h SplashState.cpp SplashState.h MainMenuState.cpp MainMenuState.h WorldState.cpp WorldState.h TileMap.cpp TileMap.h Mission.cpp Mission.h collisionTest.cpp collisionTest.h colliderTest.cpp colliderTest.h Audio.cpp Audio.h Movement.cpp Movement.h Map.cpp Map.h)

target_link_libraries (GTAKRS sfml-audio sfml-graphics sfml-window sfml-system)
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(GTAKRS ${SFML_LIBRARIES})
endif()