#include <unistd.h>
void print_pal(char* str, int low, int high)
{
    while (low <= high)
        //write(1, &str[low++], 1);
        write(1, &str[high--], 1);
}
void biggest_pal(char *str)
{
    int    i;
    int len;
    int low;
    int high;
    int max_len;
    int start;
    len = 0;
    while (str[len])
        len++;
    i = 1;
    max_len = 1;
    while (++i < len)
    {
        // aeibaabaammaabaalek
        //    |-          -|
        // abcba (нечет) [n = 2k + 1]
        // abccba (чет) [n = 2k]
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 >= max_len)
            {
                start = low; // 4
                max_len = high - low + 1; // 12
            }
            --low;
            ++high;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 >= max_len)
            {
                start = low;
                max_len = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    print_pal(str, start, start + max_len - 1);
}
int main(int argc, char **argv)
{
    if (argc == 2)
        biggest_pal(argv[1]);
    write(1, "\n", 1);
    return 0;
}
//Assignment name  : biggest_pal
//Expected files   : *.c, *.h
//Allowed functions: write
//--------------------------------------------------------------------------------
//
//Write a program named biggest_pal that takes a string as argument and prints the
//biggest palindrome included inside this string, followed by a newline.
//
//This string contains only lowercase characters.
//
//If there is two palindromes of the same length, you have to print the last one.
//
//If there is more or less than 1 argument, your program must print only a newline
//only.
//
//Exemples:
//
//$> biggest_pal "abcba"
//abcba
//$> biggest_pal "aaaaaaaaaabbcbbaaaa"
//aaaabbcbbaaaa
//$> biggest_pal "aooibdaoiwhoihwdoinzeldaisaboyobasiadlezfdsfnslk"
//zeldaisaboyobasiadlez
//$> biggest_pal "aeibaabaammaabaalek"
//aabaammaabaa
//$> biggest_pal abeb qpinqwjobo qkmnwoiq
//
//$> biggest_pal
//
//$>
//
