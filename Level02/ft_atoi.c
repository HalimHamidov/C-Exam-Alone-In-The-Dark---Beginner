#include <stdio.h>

int        ft_atoi(const char *str)
{
    int    n;
    int    sign;
    
    n = 0;
    sign = 1;
    while ((*str == ' ' || *str == '\t' || *str == '\n' ||
           *str == '\r' || *str == '\v' || *str == '\f'))
        str++;
    if ((*str == '-' || *str == '+'))
    {
        if (*str++ == '-')
            sign = -1;
    }
    while (*str >= '0' && *str <= '9') // don't forger to put '' around numbers here
    {
        n = n * 10 + (*str - '0');
        str++;
    }
    return (n * sign);
}

int main (void)
{
    char *Str = "652.23brrt"; //Строка для преобразования
    int Num = 0;                //Переменная для записи результата
    
    //Преобразование строки в число типа int
    Num = ft_atoi(Str);
    //Вывод результата преобразования
    printf ("%d\n", Num);
    //Завершение работы программы
    printf("1/%d\n", ft_atoi("0"));
    printf("2/%d\n", ft_atoi("546:5"));
    printf("3/%d\n", ft_atoi("-4886"));
    printf("4/%d\n", ft_atoi("+548"));
    printf("5/%d\n", ft_atoi("054854"));
    printf("6/%d\n", ft_atoi("000074"));
    printf("7/%d\n", ft_atoi("+-54"));
    printf("8/%d\n", ft_atoi("-+48"));
    printf("9/%d\n", ft_atoi("--47"));
    printf("10/%d\n", ft_atoi("++47"));
    printf("11/%d\n", ft_atoi("+47+5"));
    printf("12/%d\n", ft_atoi("-47-5"));
    printf("13/%d\n", ft_atoi("\e475"));
    printf("14/%d\n", ft_atoi("\t\n\r\v\f  469 \n"));
    printf("15/%d\n", ft_atoi("-2147483648"));
    printf("16/%d\n", ft_atoi("2147483647"));
    printf("17/%d\n", ft_atoi("\t\n\r\v\fd469 \n"));
    printf("18/%d\n", ft_atoi("\n\n\n  -46\b9 \n5d6"));
    printf("19/%d\n", ft_atoi(""));
    return 0;
}
/*
Вывод
652
1/0
2/546
3/-4886
4/548
5/54854
6/74
7/0
8/0
9/0
10/0
11/47
12/-47
13/0
14/469
15/-2147483648
16/2147483647
17/0
18/-46
19/0

 
 atoi – преобразование строки в число типа int
 Синтаксис:
 
 #include < stdlib.h >
 int atoi (const char *str);
 
 Аргументы:
 
 str – указатель на строку, которую необходимо преобразовать в число.
 
 Возвращаемое значение:
 
 Функция возвращает число - результат преобразование строки, если в начале строки содержится число. Если в начале строки стоит символ не являющейся цифрой, то функци возвращает ноль.
 
 Описание:
 
 Функция atoi () преобразует строку, на которую указывает аргумент str, в число типа int. Преобразование заканчивается, когда встречается символ не являющейся цифрой или, когда будет преобразована вся строка. Если первый символ строки не цифра, то функция вернет 0 и завершит работу.
 
 Если число в строке превышает максимальный или минимальный размер числа типа int, то функция возвращает соответственно максимально или минимально допустимое число для типа int. Возвращаемая величина зависит от аппаратной платформы на которой запускается программа.
 
 От функции atol () отличается типом возвращаемого числа и как следствие макимальной длинной преобразуемой строки. Для atoi возвращаемое число имеет тип int, а соответственно разрядность 16 или 32 бита в зависимости от аппаратной платформы, на которой запускается программа. Для atol возвращаемое число имеет тип long int, который всегда 32 разрядный, не зависимо от архитектуры процессора.
 
 Так, на пример, в результате преобразования строки "217bg12" будет получено число 217, а при преобразовании строки "b237пр" будет получено число 0.
 
 Пример:
 
 В примере преобразуется строка "652.23brrt" в число и результат выводится на консоль.
 
 
 #include < stdio.h >   //Для printf()
 #include < stdlib.h >  //Для atoi()
 
 int main (void)
 {
 char *Str = "652.23brrt"; //Строка для преобразования
 int Num=0;                //Переменная для записи результата
 
 //Преобразование строки в число типа int
 Num = atoi (Str);
 
 //Вывод результата преобразования
 printf ("%d\n",Num);
 
 //Завершение работы программы
 return 0;
 }
 
 
 
 Результат:
 
 652
 */

//
//if (n > (long long)9223372036854775807 && sign == 1)
//return (-1);
//if (n > (long long)9223372036854775807 && sign == -1)
//return (0);

//Assignment name  : ft_atoi
//Expected files   : ft_atoi.c
//Allowed functions: None
//--------------------------------------------------------------------------------
//
//Write a function that converts the string argument str to an integer (type int)
//and returns it.
//
//It works much like the standard atoi(const char *str) function, see the man.
//
//Your function must be declared as follows:
//
//int    ft_atoi(const char *str);
//


//int ft_atoi(char *str)
//{
//    int n;
//    int s;
//    
//    n = 0;
//    s = 1;
//    
//    while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' || *str == '\r' || *str == '\f')
//        str++;
//    if (*str == '-' || *str == '+')
//        if (*str++ == '-')
//            s = -1;
//    while (*str >= '0' && *str <= '9')
//    {
//        n = n * 10 + *str++ - '0';
//    }
//    return (n * s);
//}
