/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** Made by daykem
*/

#include "include/my.h"

char	*remp1(char *map, int j, int i, int size)
{
	while (map[j] != '\n' && map[j]) {
		if (map[j] == '.')
			map[j] = '1';
		j++;
	}
	while (map[i]) {
		if (map[i] == 'o') {
			if (map[i + 1] == '.' && map[i + 1])
				map[i + 1] = '1';
			if (map[i + size + 1] == '.' && map[i + size + 1])
				map[i + size + 1] = '1';
		}
		i++;
	}
	return (map);
}

char	*remp2(char *map, int j, int size, t_max t)
{
	if (t.o != 0) {
		while (map[t.k]) {
			if (map[t.k] > t.stock && map[t.k] != 'o') {
				t.stock = map[t.k];
				t.a = t.k;
			}
			t.k++;
		}
		t.stock2 = t.stock;
		while ((t.stock - 49) != 0) {
			map[t.a - (t.stock - 49)] = 'x';
			t.stock--;
		}
		t.stock = t.stock2;
		while ((t.stock  - 49) != 0) {
			map[t.a - (size + 1) * (t.stock - 49)] = 'x';
			t.stock--;
		}
		map[t.a] = 'x';
	}
	while (map[t.a] == 'x') {
		t.stock = t.stock2;
		while ((t.stock - 49) != 0) {
			map[t.a - (size + 1) * (t.stock - 49)] = 'x';
			t.stock--;
		}
		t.a--;
	}
	return (map);
}

char	*remp(char *map)
{
	int j = (my_strlenn2(map) + 1);
	int i = 0;
	int cmp = my_strlenn2(map);
	int size = my_strlenn(map);
	t_max t;

	t.k = my_strlenn2(map) + 1;
	t.o = 0;
	map = remp1(map, j, i, size);
	while (map[j]) {
		if (map[j] == '.') {
			t.o++;
			if (map[j - 1] != 'o' && map[j - size - 1] != 'o'
				&& map[j - size - 2] != 'o'
				&& map[j - 1] != '\n' && map[j - size - 1] != '\n'
				&& map[j - size - 2] != '\n' && map[j - 1]
				&& map[j - size - 1] && map[j - size - 2])
				map[j] = (check(map[j - 1], map[j - size - 1]
						, map[j - size - 2]) + 1);
			else
				map[j] = '1';
		}
		j++;
	}
	map = remp2(map, j, size, t);
	while (map[cmp]) {
		if (map[cmp] != 'o' && map[cmp] != 'x'
			&& map[cmp] != '\n' && map[cmp])
			map[cmp] = '.';
		cmp++;
		}
	return (map);
}

char	**doubles(char *map)
{
	int i = 0;
	int k = 0;
	int cmpt = gom(map);
	char **tmp = malloc(sizeof(char*) * 10011);
	int lentgh = my_strlenn(map);

	if (lentgh == 1)
		lentgh = 0;
	if (tmp == NULL)
		return NULL;
	for (int j = 0; j < my_getnbr(map) + 10; j++) {
		tmp[j] = malloc(sizeof(char) * 10011);
		if (tmp[j] == NULL)
			return NULL;
	}
	map = remp(map);
	while (map[cmpt]) {
		tmp[i][k] = map[cmpt];
		cmpt++;
		k++;
		if (my_getnbr(map) == 1 && tmp[0][0] != 'o'
			|| lentgh == 0 && tmp[0][0] != 'o')
			tmp[0][0] = 'x';
		if (k == lentgh) {
			k = 0;
			i++;
		}
	}
	i = 0;
	k = 0;
	while (tmp[i][k]) {
		write(1, &tmp[i][k], my_strlen(tmp[i]));
		k = k + my_strlen(tmp[i]);
		if (k == lentgh) {
			k = 0;
			i++;
		}
	}
	free(tmp);
}

int	bsq(char *name)
{
	int fd = 0;
	int nb_lines = 0;
	char *map;
	int i = 0;
	struct stat sb;

	fd = open(name, O_RDONLY);
	if (stat(name, &sb) == -1)
		return 84;
	map = malloc(sizeof(char*) * sb.st_size + 1);
	if (map == NULL)
		return 84;
	read(fd, map, sb.st_size + 1);
	map[sb.st_size] = '\0';
	doubles(map);
	free(map);
}
