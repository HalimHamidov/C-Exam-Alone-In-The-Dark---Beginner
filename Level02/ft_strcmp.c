#include <stdio.h>

int        ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while ((*s1 || *s2) != '\0')
    {
        if (*s1 != *s2)
            return ((*s1) - (*s2));
        s1++;
        s2++;
    }
    return (0);
}

int main(void)
{
    // Сравниваемые строки
    char str1[1024]="12345";
    char str2[1024]="12345";
    
    // Сравниваем две строки
    if (ft_strcmp(str1, str2)==0)
        puts("Строки идентичны");
    else
        puts("Строки отличаются");
    printf("1/%d", ft_strcmp("salut", "salut"));
    printf("\n2/%d", ft_strcmp("test", "testss"));
    printf("\n3/%d", ft_strcmp("testss", "test"));
    printf("\n4/%d", ft_strcmp("test", "tEst"));
    printf("\n5/%d", ft_strcmp("", "test"));
    printf("\n6/%d", ft_strcmp("test", ""));
    printf("\n7/%d", ft_strcmp("test\200", "test\0"));//why the output is   128
}



/*
 strcmp # lexicographically comparaison of s1 and s2. Returns int > < or == 0 according to s1 compared to s2.
 
 strcmp – сравнение строк.
 Синтаксис:
 
 #include < string.h >
 int strcmp (const char *str1, const char *str2);
 
 Аргументы:
 
 str1, str2 – указатели на сравниваемые строки.
 
 Возвращаемое значение:
 
 0 – если сравниваемее строки идентичны.
 
 Положительное число – если строки отличаются и код первого отличающегося символа в строке str1 больше кода символа на той же позиции в строке str2.
 
 Отрицательное число – если строки отличаются и код первого отличающегося символа в строке str1 меньше кода символа на той же позиции в строке str2.
 
 Описание:
 
 Функция побайтно сравнивает коды символов двух строк, на которые указывают аргументы функции. Сравнение продолжается до встречи первого отличающегося символа или пока не будут проверены все символы строк.
 
 Если все символы строк совпали, то возвращается 0.
 
 Если при сравнении встретились отличающиеся символы, то сравнение прекращается и возвращается отрицательное или положительное число, в зависимости от того больше или меньше код символа строки str1, кода символа строки str2 на той же позиции (см. возвращаемые значения).
 
 Если строки разной длины, то возвращается положительное число, если строка str1 длиннее строки str2, или отрицательное число, если строка str2 длиннее строки str1.
 
 Пример:
 
 В примере сравниваются две строки и результат сравнения выводится на экран.
 
 
 #include < stdio.h >  // Для printf
 #include < string.h > // Для strcmp
 int main (void)
 {
 // Сравниваемые строки
 char str1[1024]=”12345”;
 char str2[1024]=”12305”;
 
 // Сравниваем две строки
 if (strcmp (str1, str2)==0)
 puts (“Строки идентичны”);
 else
 puts (“Строки отличаются”);
 
 return 0;
 }
 Результат:
 
 Вывод в консоль:
 Строки отличаются
 
int        ft_strcmp(char *s1, char *s2)
{
    unsigned char    *ptr1;
    unsigned char    *ptr2;
    int            i;
    
    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    i = 0;
    while (ptr1[i] || ptr2[i])
    {
        if (ptr1[i] != ptr2[i])
            return (ptr1[i] - ptr2[i]);
        i++;
    }
    return (0);
}
*/
//Assignment name  : ft_strcmp
//Expected files   : ft_strcmp.c
//Allowed functions:
//--------------------------------------------------------------------------------
//
//Reproduce the behavior of the function strcmp (man strcmp).
//
//Your function must be declared as follows:
//
//int    ft_strcmp(char *s1, char *s2);

