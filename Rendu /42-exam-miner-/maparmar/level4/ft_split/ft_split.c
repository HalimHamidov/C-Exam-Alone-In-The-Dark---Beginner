#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int no_words(char *s)
{
	int len = 0;

	while (*s)
	{
		if (ft_isspace(*s))
		{
			s++;
		}
		else
		{
			++len;
			while (*s && !ft_isspace(*s))
			{
				s++;
			}
		}
	}
	return (len);
}

/*

asdf qwerty zxcv

start = 5;
word_len = 0;

res[0] = "asdf";
res[1] = "qwerty";
res[2] = "zxcv";

res[0][1] = 's';
res[1][5] = 'y';
res[2][5] = '\0';

*/

char    **ft_split(char *str)
{
	char **res;
	int word_len = 0;
	int i = 0;
	int start;
	int k;
	int j = 0;
	int words = no_words(str);
	res = (char**)malloc(sizeof(char*) * (words + 1));
	while (str[i] && j < words)
	{
		while (str[i] && ft_isspace(str[i]))
		{
			i++;
		}
		start = i;
		while (str[i] && !ft_isspace(str[i]))
		{
			word_len++;
			i++;
		}
		res[j] = (char*)malloc(sizeof(char) * (word_len + 1));
		k = 0;
		while (word_len)
		{
			res[j][k] = str[start];
			word_len--;
			start++;
			k++;
		}
		res[j][k] = '\0';
		j++;
	}
	res[j] = 0;
	return (res);
}
int main (void)
{
	char** res;
	for (res = ft_split("asdf qwerty zxcv"); *res != '\0'; res++)
		printf("'%s',", *res);
	printf("\n");
	return (0);
}

//Assignment name  : ft_split
//Expected files   : ft_split.c
//Allowed functions: malloc
//--------------------------------------------------------------------------------
//
//Write a function that takes a string, splits it into words, and returns them as
//a NULL-terminated array of strings.
//
//A "word" is defined as a part of a string delimited either by spaces/tabs/new
//lines, or by the start/end of the string.
//
//Your function must be declared as follows:
//
//char    **ft_split(char *str);

