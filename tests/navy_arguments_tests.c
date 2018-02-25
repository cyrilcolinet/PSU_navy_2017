/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** navy_arguments_tests functions
*/

# include "units.h"

Test(arguments, no_arguments, .init = redirect_std)
{
	char *args[1];
	int res = -1;

	args[0] = "./navy";
	res = navy_main(1, args);

	cr_assert_eq(res, 84);
}

Test(arguments, one_invalid_argument, .init = redirect_std)
{
	char *args[2];
	int res = -1;

	args[0] = "./navy";
	args[1] = "13754";
	res = navy_main(2, args);

	cr_assert_eq(res, 84);
}

Test(arguments, two_invalid_arguments, .init = redirect_std)
{
	char *args[3];
	int res = -1;

	args[0] = "./navy";
	args[1] = "maps/pos1";
	args[2] = "maps/pos2";
	res = navy_main(3, args);

	cr_assert_eq(res, 84);
}

Test(arguments, two_arguments_but_first_not_number, .init = redirect_std)
{
	char *args[3];
	int res = -1;

	args[0] = "./navy";
	args[1] = "maps/pos2";
	args[2] = "13754";
	res = navy_main(3, args);

	cr_assert_eq(res, 84);
}

Test(arguments, help_flag, .init = redirect_std)
{
	char *args[2];
	int res = -1;

	args[0] = "./navy";
	args[1] = "-h";
	res = navy_main(2, args);

	cr_assert_eq(res, 0);
}
