
#include "t_point.h"
void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c;	// Символ начала
	c = tab[begin.y][begin.x]; // Сохраняем символ начала

	tab[begin.y][begin.x] = 'F'; // Присваиваем начальной координате заполнения
	begin.y++; // Смещаемся на строку вниз
	if (begin.y < size.y && tab[begin.y][begin.x] == c) // when the position + 1 in Y Direction is the given character
		flood_fill(tab, size, begin);
	begin.y--; // Смещаемся на две строки вверх
	begin.y--;
	if (begin.y >= 0 && tab[begin.y][begin.x] == c) // when the position - 1 in Y Direction is the given character
		flood_fill(tab, size, begin);
	begin.y++;
	begin.x++;
	if (begin.x < size.x && tab[begin.y][begin.x] == c) //when the position +1 in X Direction is the given character;
		flood_fill(tab, size, begin);
	begin.x--;
	begin.x--;
	if (begin.x >= 0 && tab[begin.y][begin.x] == c) // when the position - 1 in X Direction is the given character;
		flood_fill(tab, size, begin);
}

//Assignment name  : flood_fill
//Expected files   : *.c, *.h
//Allowed functions: -
//--------------------------------------------------------------------------------
//
//Write a function that takes a char ** as a 2-dimensional array of char, a
//t_point as the dimensions of this array and a t_point as the starting point.
//
//Starting from the given 'begin' t_point, this function 'colors' an entire zone
//by replacing characters inside by the character 'F'. A zone is an ensemble of
//the same character delimitated horizontally and vertically by other characters.
//
//The flood_fill function won't 'color' in diagonal.
//
//The flood_fill function will be prototyped like this:
//void  flood_fill(char **tab, t_point size, t_point begin);
//
//The t_point structure is available inside the "t_point.h" file attached to this
//assignment. We will use our "t_point.h" for graduation.
//
//Example :
//
//$> cat test_main.c
//#include "test_functions.h"
//#include "flood_fill.h"
//
//int main(void)
//{
//    char **area;
//    t_point size = { 8, 5 };
//    t_point begin = { 2, 2 };
//    char *zone[] = {
//        "11111111",
//        "10001001",
//        "10010001",
//        "10110001",
//        "11100001"
//    };
//    
//    area = make_area(zone);
//    print_tab(area);
//    flood_fill(area, size, begin);
//    putc('\n');
//    print_tab(area);
//    return (0);
//}
//
//$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill ; ./flood_fill
//1 1 1 1 1 1 1 1
//1 0 0 0 1 0 0 1
//1 0 0 1 0 0 0 1
//1 0 1 1 0 0 0 1
//1 1 1 0 0 0 0 1
//
//1 1 1 1 1 1 1 1
//1 F F F 1 0 0 1
//1 F F 1 0 0 0 1
//1 F 1 1 0 0 0 1
//1 1 1 0 0 0 0 1
//$>



//
//#include "t_point.h"
//#include <stdio.h>
//#include <stdlib.h>
//char **make_area(char **zone, int _x, int _y)
//{
//    char **area;
//    area = (char **)malloc(sizeof(char *) * _y);
//    for (int i = 0; i < _y; ++i)
//    {
//        area[i] = (char *)malloc(sizeof(char) * _x);
//        for (int j = 0; j < _x; ++j)
//            area[i][j] = zone[i][2 * j];
//    }
//    return (area);
//}
//int main(void)
//{
//    char *zone[] = {
//        "1 1 1 1 1 1 1 1",
//        "1 0 0 0 1 0 0 1",
//        "1 0 0 1 0 0 0 1",
//        "1 0 1 0 0 0 0 1",
//        "1 1 0 0 0 0 0 0",
//    };
//    t_point size  = {8, 5};
//    t_point begin = {0, 0};
//    char **area = make_area(zone, size.x, size.y);
//    flood_fill(area, size, begin);
//    for (int y = 0; y < size.y; y++)
//    {
//        for (int x = 0; x < size.x; x++)
//        {
//            if (x != 0)
//                printf(" ");
//            printf("%c", area[y][x]);
//        }
//        printf("\n");
//    }
//    free(area);
//    return (0);
//}
//
//
//
//#ifndef T_POINT_FLOOD_FILL
//# define T_POINT_FLOOD_FILL
//
//typedef struct     s_point {
//    int         x;                // x : Width  | x-axis
//    int         y;                // y : Height | y-axis
//}                 t_point;
//
//void  flood_fill(char **tab, t_point size, t_point begin);
//#endif

