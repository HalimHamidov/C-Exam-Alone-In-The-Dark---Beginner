
#include <stdlib.h>
#include <unistd.h>

void	brainfuck(char *str)
{
	int	tab[2048] = {0};
	int	*ptr;
	int	loop_count;

	ptr = tab;
	loop_count = 0;
	while (*str)
	{
		if (*str == '>')
			ptr++; // перемещение по указателю
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			++(*ptr); // Инкременция
		else if (*str == '-')
			--(*ptr);
		else if (*str == '.') // Вывод
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0)
		{
			loop_count = 1;
			while (loop_count != 0)
			{
				str++; // Увеличивается до тех пор: пока нет закрывающейся скобки
				if (*str == ']')
					--loop_count;
				if (*str == '[')
					++loop_count;
			}
		}
		else if (*str == ']' && *ptr != 0)
		{
			loop_count = 1;
			while (loop_count != 0)
			{
				str--; // Уменьшается до тех пор, пока нет открывающейся скобки
				if (*str == '[')
					--loop_count;
				if (*str == ']')
					++loop_count;
			}
		}
		str++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		brainfuck(argv[1]);
	return (0);
}
//
//Assignment name  : brainfuck
//Expected files   : *.c, *.h
//Allowed functions: write, malloc, free
//--------------------------------------------------------------------------------
//
//Write a Brainfuck interpreter program.
//The source code will be given as first parameter.
//The code will always be valid, with no more than 4096 operations.
//Brainfuck is a minimalist language. It consists of an array of bytes
//(in our case, let's say 2048 bytes) initialized to zero,
// and a pointer to its first byte.
// 
// Every operator consists of a single character :
// - '>' increment the pointer ;
// - '<' decrement the pointer ;
// - '+' increment the pointed byte ;
// - '-' decrement the pointed byte ;
// - '.' print the pointed byte on standard output ;
// - '[' go to the matching ']' if the pointed byte is 0 (while start) ;
// - ']' go to the matching '[' if the pointed byte is not 0 (while end).
// 
// Any other character is a comment.
// 
// Examples:
// 
// $>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
// >++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
// Hello World!$
// $>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
// Hi$
// $>./brainfuck | cat -e
// $

