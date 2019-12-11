cmake_minimum_required(VERSION 3.14)
project(GTAKRS)

set(CMAKE_CXX_STANDARD 14)

add_executable(GTAKRS
        main.cpp
        State.h
        StateMachine.cpp StateMachine.h
        AssetManager.cpp AssetManager.h
        InputManager.cpp InputManager.h
        Game.cpp Game.h
        DEFINITIONS.h
        SplashState.cpp SplashState.h
        MainMenuState.cpp MainMenuState.h
        WorldState.cpp WorldState.h
        Mission.cpp Mission.h
        colliderTest.cpp colliderTest.h
        Movement.cpp Movement.h
        Map.cpp Map.h
        SpriteFactory.h Factory.h
        Hacking.h Hacking.cpp
        npc.h npc.cpp
        Collision_Detection.cpp Collision_Detection.h
        Npv.h Npv.cpp
        Player.cpp Player.h
        NPC_NPV.h
        missionPlacement.h missionPlacement.cpp
        Bullet.h
        Shooting.cpp Shooting.h
        Weapon.h Weapon.cpp
        WastedState.h WastedState.cpp
        ControlsState.h ControlsState.cpp
        objectSpawn.cpp objectSpawn.h


        )
file(GLOB INCLUDE_FILES "json/*.h")
install(FILES
        ${INCLUDE_FILES}
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/json)


target_link_libraries (GTAKRS sfml-audio sfml-graphics sfml-window sfml-system)
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(GTAKRS ${SFML_LIBRARIES})
endif()