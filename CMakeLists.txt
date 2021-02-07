cmake_minimum_required(VERSION 3.19)
project(sea_battle C)

set(CMAKE_C_STANDARD 99)

add_executable(
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

        modes/modes.h
        modes/multiplayer/multiplayer.c
        modes/multiplayer/multiplayer.h
        modes/singleplayer/singleplayer.c
        modes/singleplayer/singleplayer.h

        settings/settings.c
        settings/settings.h

        players/player.h
        players/load/load_player.c
        players/load/load_player.h
        players/define/player_define.c
        players/define/player_define.h

        users/users.h
        users/load_user/load_user.c
        users/load_user/load_user.h
        users/define/user_define.c
        users/define/user_define.h

        ship/ship.h
        ship/define/ship_define.c
        ship/define/ship_define.h

        map/map.h
        map/point_declare/point_declare.c
        map/point_declare/point_declare.h

        auto_import.h
)
