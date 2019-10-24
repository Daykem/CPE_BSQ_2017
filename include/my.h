/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** libmy prototypes
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>

typedef struct	s_max
{
	int o;
	int a;
	int k;
	char stock;
	char stock2;
} t_max;

int	bsq(char *);
int	my_atoi(char *);
void	my_putchar(char);
int	my_getnbr(char *);
int	my_put_nbr(int);
int	my_swap(int*, int*);
int	my_flags(char *, char const *);
int	my_putstr(char const*);
int	my_strlen3(char *);
int	my_strlenn2(char *);
int	gom(char *);
char	check(char, char, char);
int	my_strlen1(char *);
int	my_strlen(char *);
int	my_strlenn(char *);
int	my_putnbr_base(int, char const*);
void	my_printf(char *str, ...);

#endif
