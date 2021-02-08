#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//menu
#include "menu/helpers/menu_helpers.h"
#include "menu/main/main_menu.h"
#include "menu/settingsMenu/settings_menu.h"
#include "menu/user/user_menu.h"


//map
#include "map/point_declare/point_declare.h"
#include "map/visual/map_visual.h"
#include "map/point_helper/point_helper.h"

// modes
#include "modes/singleplayer/singleplayer.h"
#include "modes/multiplayer/multiplayer.h"

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
