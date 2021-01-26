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

        modes/modes.h
        modes/multiplayer/multiplayer.c
        modes/multiplayer/multiplayer.h menu/user/user.c menu/user/user.h modes/singleplayer/singleplayer.c modes/singleplayer/singleplayer.h)