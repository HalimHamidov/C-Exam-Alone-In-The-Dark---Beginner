
int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	else
		return ((n & (-n)) == n); // 2's Complement of the number is (-n) and if the AND logic of nbr and it's 2's complement is number itself then its power of 2
}
