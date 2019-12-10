#include <unistd.h>
void biggest_pal(char *str);
void print_pal(char *str, int l, int h);
int main(int argc, char **argv)
{
    if (argc == 2)
        biggest_pal(argv[1]);
    write (1, "\n", 1);
    return (0);
}

void biggest_pal(char *str)
{
    int i = 1;
    int len = 0;
    int ml = 1;
    int s;
    int l;
    int h;
    while (str[len])
        len++;
    while (++i < len)
    {
        l = i - 1;
        h = i;
        while (l >= 0 && h < len && str[l] == str[h])
        {
            if (h-l+1>= ml)
            {
                s = l;
                ml = h-l+1;
            }
            --l;
            ++h;
        }
        l = i - 1;
        h = i + 1;
        while (l >= 0 && h < len && str[l] == str[h])
        {
            if (h-l+1>= ml)
            {
                s = l;
                ml = h-l+1;
            }
            --l;
            ++h;
        }
    }
    print_pal(str, s, s+ml-1);
}
void print_pal(char *str, int l, int h)
{
    while (l <= h)
        write (1, &str[l++], 1);
}

//
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

