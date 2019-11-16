#include <unistd.h>

int main (int argc, char **argv)
{
	if (argc > 0 && argv[0] > 0)
	{
		write (1, "z\n", 2);
	}
	return (0);
}
