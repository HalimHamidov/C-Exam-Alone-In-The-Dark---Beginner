#include <unistd.h>

int main (int ac, char **av)
{
	int i = 0;
	int rep;
	char c;
	if (ac == 2)
	{
		while (av[1][i])
		{
			c = av[1][i]; 
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
			{
				if (c >= 'a' && c <= 'z')
					rep = c - 'a';
				if (c >= 'A' && c <= 'Z')
					rep = c - 'A';
				while (rep > 0)
				{
					write (1, &c, 1);
					rep--;
				}
			}
			write (1, &c, 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
