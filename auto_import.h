#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

bool isApplicationInProduction;


//menu
#include "menu/helpers/menu_helpers.h"
#include "menu/main/main_menu.h"
#include "menu/settingsMenu/settings_menu.h"
#include "menu/user/user_menu.h"
#include "menu/in-game/in_game_menu.h"

//map
#include "map/point_declare/point_declare.h"
#include "map/visual/map_visual.h"
#include "map/point_helper/point_helper.h"



//users
#include "users/define/user_define.h"
#include "users/load_user/load_user.h"


//ship
#include "ship/define/ship_define.h"


//settings
#include "settings/settings.h"


//players
#include "players/define/player_define.h"
#include "players/load/load_player.h"

//ship placement
#include "ship/placement/manual/ship_placement_manual.h"
#include "ship/placement/auto/ship_placement_auto.h"

// modes
#include "modes/multiplayer/multiplayer.h"
#include "modes/singleplayer/singleplayer.h"

//score board
#include "scoreboard/show/show_scoreboard.h"

//save game
#include "game_save/game_log/game_log_define.h"
#include "game_save/save/save_game.h"
#include "game_save/load/load_game.h"