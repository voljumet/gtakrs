#pragma once

/// Denne klassen er bare for å definere forskjelliger verdier eller filer og kan hentes til alle klasser,
/// greit for å vite hvor man skal legge til nye objekter eller verdier som er globale

///Størrelser
//////////////////////////////////////////////////////////////////////////////////////////
#define SCREEN_WIDTH 1800
#define SCREEN_HEIGHT 1600

///IMPORTANT TO KNOW HOW MANY COLUMNS THERE ARE IN THE MAP FILE!!!!!!
#define WORLD_WIDTH 200
#define WORLD_HEIGHT 400

#define TILE_SIZE 70

#define SPLASH_STATE_SHOW_TIME 1
//////////////////////////////////////////////////////////////////////////////////////////

///Map
//////////////////////////////////////////////////////////////////////////////////////////
#define TILEMAP_PNG_FILEPATH "Resources/res/Tileset_Tileset.png"
#define MAP_FILE "Resources/res/MAP2.map"

//////////////////////////////////////////////////////////////////////////////////////////

///Fonts
//////////////////////////////////////////////////////////////////////////////////////////
#define FONT_ARIAL "Resources/fonts/Arial.ttf"
#define FONT_MARKER_FELT "Resources/fonts/Marker Felt.ttf"
//////////////////////////////////////////////////////////////////////////////////////////

///Sprites
//////////////////////////////////////////////////////////////////////////////////////////
#define PLAYER "Resources/res/Walk_1.png"
#define PLAYER2 "Resources/res/Walk_2.png"
#define PLAYER3 "Resources/res/Walk_3.png"
#define PLAYER4 "Resources/res/Walk_4.png"
#define PLAYER5 "Resources/res/Walk_5.png"

#define DEAD_PLAYER "Resources/res/dead-01.png"
#define CAR_BLUE "Resources/res/carBlue.png"
#define CAR_WHITE "Resources/res/carWhite.png"
#define BOAT "Resources/res/Boat.png"

#define M3_BLUE "Resources/res/Vehicles/model3-01.png"
#define M3_RED "Resources/res/Vehicles/model3-02.png"
#define M3_SILVER "Resources/res/Vehicles/model3-03.png"
#define M3_WHITE "Resources/res/Vehicles/model3-04.png"
#define M3_BLACK "Resources/res/Vehicles/model3-05.png"

//////////////////////////////////////////////////////////////////////////////////////////

///Main menu
//////////////////////////////////////////////////////////////////////////////////////////
#define MAIN_MENU_LOGO_PATH "Resources/res/Menus/Game Title.png"
#define MAIN_MENU_PLAY_BUTTON "Resources/res/Menus/Buttons-01.png"
#define MAIN_MENU_LOAD_BUTTON "Resources/res/Menus/Buttons-02.png"
#define MAIN_MENU_EXIT_BUTTON "Resources/res/Menus/Buttons-03.png"
#define MAIN_MENU_MISSION1_BUTTON "Resources/res/Menus/Buttons-04.png"
#define MAIN_MENU_MISSION2_BUTTON "Resources/res/Menus/Buttons-05.png"
#define MAIN_MENU_DEBUG_BUTTON "Resources/res/Menus/Buttons-06.png"

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Menus/Splash Background.png"
//////////////////////////////////////////////////////////////////////////////////////////

///MISSION 1
//////////////////////////////////////////////////////////////////////////////////////////
#define MISSION_1_SCOPE "Resources/res/mission_1/Mission_1_Scope.png"
#define MISSION_1_BUILDING "Resources/res/mission_1/Mission_1_Building.png"
#define MISSION_1_SPRITE "Resources/res/mission_1/Mission_1_alive.png"
#define MISSION_1_DEADSPRITE "Resources/res/mission_1/Mission_1_dead.png"
//////////////////////////////////////////////////////////////////////////////////////////


///HACKING TEXTURE
#define CRT_SCREEN "Resources/res/mission_2/crtScreen.png"
#define RETRO "Resources/fonts/retro.ttf"
#define COMPUTERSOUNDS "Resources/res/Music/computer_sounds.ogg"


/////AUDIO SAMPLES/////////
//////////////////////////////////////
#define AIRHORN_FILEPATH "Resources/res/Sound/airhorn.ogg"
#define CARDOOR_FILEPATH "Resources/res/Sound/cardoor.ogg"
#define FOOTSTEP_FILEPATH "Resources/res/Sound/footstep.ogg"
#define GUNHSOT_FILEPATH "Resources/res/Sound/gunshot.ogg"
#define BUTTONPRESS "Resources/res/Sound/buttonpress.ogg"
#define SONG "Resources/res/Music/DragonForce - Through The Fire And Flames.ogg"
//////////////////////////////////////////////////////////////////////////////////////////

