cmake_minimum_required(VERSION 3.13)
project(PSU_navy_2017 C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(lib/my/include)

add_executable(PSU_navy_2017
    include/my.h
    include/navy.h
    include/units.h
    lib/my/include/my.h
    lib/my/src/my_atoi.c
    lib/my/src/my_countwords.c
    lib/my/src/my_freetab.c
    lib/my/src/my_put_nbr.c
    lib/my/src/my_putchar.c
    lib/my/src/my_putstr.c
    lib/my/src/my_str_isnum.c
    lib/my/src/my_strcat.c
    lib/my/src/my_strcmp.c
    lib/my/src/my_strconfigure.c
    lib/my/src/my_strequ.c
    lib/my/src/my_strlen.c
    lib/my/src/my_strtok.c
    src/connector/connector.c
    src/connector/handlers.c
    src/connector/signals.c
    src/game/check_end_game.c
    src/game/check_hit_fail.c
    src/game/game_loop.c
    src/map/error/check_boat_error.c
    src/map/error/check_map_error.c
    src/map/map_add_boat.c
    src/map/map_creation.c
    src/map/map_display.c
    src/map/map_management.c
    src/utilities/data_utils.c
    src/utilities/get_next_line.c
    src/utilities/parsing_utils.c
    src/utilities/std_utils.c
    src/utilities/struct_utils.c
    src/main.c
    src/navy.c
    src/navy_main.c
    tests/navy_arguments_tests.c
    tests/navy_correct_execution_tests.c
    tests/navy_signals_tests.c
    tests/navy_utils_tests.c
    tests/navy_wrong_file_tests.c)
