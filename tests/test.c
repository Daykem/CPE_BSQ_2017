/*
** EPITECH PROJECT, 2017
** test.c
** File description:
** Made by devlopers
*/

#include <criterion/criterion.h>
#include "../include/my.h"
#include <string.h>

int	bsq(char *);

char *name = "test";
char *name2;

Test(test1, error1)
{
	cr_assert_eq(bsq(name), 84);
}

Test(test2, error2)
{
	cr_assert_eq(bsq(name2), 84);
}
