/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** Made by daykem
*/

#include "include/my.h"


int     gom(char *map)
{
	int nb = my_getnbr(map);

	if (nb < 1)
		return (1);
	if (nb < 10)
		return (2);
	if (nb < 100)
		return (3);
	if (nb < 1000)
		return (4);
	if (nb < 10000)
		return (5);
	if (nb < 100000)
		return (6);
	if (nb < 1000000)
		return (7);
}

int	my_strlenn(char *map)
{
	int cmp = gom(map);

	while (map[cmp] != '\n')
		cmp++;
	return (cmp - gom(map));
}

int	my_strlen1(char *map)
{
	int cmp;

	while (map[cmp] != '\0')
		cmp++;
	return (cmp);
}

int	my_strlenn2(char *map)
{
	int cmp = 0;

	while (map[cmp] != '\n')
		cmp++;
	return (cmp);
}

char	check(char a, char b, char c)
{
	char res;

	if (a <= b && a <= c)
		res = a;
	if (b <= a && b <= c)
		res = b;
	if (c <= b && c <= a)
		res = c;
	return (res);
}
