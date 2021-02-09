cmake_minimum_required(VERSION 3.19)
project(sea_battle C)

set(CMAKE_C_STANDARD 99)

add_executable(
        auto_import.h
        sea_battle
        main.c

        menu/helpers/menu_helpers.c
        menu/helpers/menu_helpers.h
        menu/main/main_menu.c
        menu/main/main_menu.h
        menu/user/user_menu.c
        menu/user/user_menu.h
        menu/settingsMenu/settings_menu.c
        menu/settingsMenu/settings_menu.h

        modes/multiplayer/multiplayer.c
        modes/multiplayer/multiplayer.h
        modes/singleplayer/singleplayer.c
        modes/singleplayer/singleplayer.h

        settings/settings.c
        settings/settings.h

        players/load/load_player.c
        players/load/load_player.h
        players/define/player_define.h

        users/load_user/load_user.c
        users/load_user/load_user.h
        users/define/user_define.h

        ship/define/ship_define.h

        map/point_declare/point_declare.c
        map/point_declare/point_declare.h

        ship/placement/auto/ship_placement_auto.c ship/placement/auto/ship_placement_auto.h ship/placement/manual/ship_placement_manual.c ship/placement/manual/ship_placement_manual.h map/visual/map_visual.c map/visual/map_visual.h map/point_helper/point_helper.c map/point_helper/point_helper.h menu/in-game/in_game_menu.c menu/in-game/in_game_menu.h scoreboard/show/show_scoreboard.c scoreboard/show/show_scoreboard.h game_save/save/save_game.c game_save/save/save_game.h game_save/game_log/game_log_define.h game_save/load/load_game.c game_save/load/load_game.h)
