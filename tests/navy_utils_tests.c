/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** nav_utils_tests functions
*/

# include "units.h"

void redirect_std(void)
{
	cr_redirect_stderr();
	cr_redirect_stdout();
	cr_redirect_stdin();
}
