
#include <stdio.h>
#include <stdlib.h>

int    ft_strlen(char *s)
{
    int i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strnew(size_t size)
{
    return ((char *)malloc(sizeof(char) * (size + 1)));
}

char    *ft_strdup(char *src)
{
    int    i;
    char    *result;
    
    if ((result = ft_strnew(ft_strlen(src))))
    {
        i = 0;
        while (src[i])
        {
            result[i] = src[i];
            i++;
        }
        result[i] = '\0';
    }
    return (result);
}

int main (void)
{
    // Исходная строка
    char str [19]="0123456789abc";
    // Переменная, в которую будет помещен указатель на дубликат строки
    char *newstr;
    // Дублирование строки
    newstr = ft_strdup (str);
    // Вывод дубликата на консоль
    printf ("Дубликат: %s\n", newstr);
    // Очищаем память, выделенную под дубликат
    free (newstr);
    return 0;
}
/*
 strdup – дублирование строк с выделением памяти под новую строку.
 Синтаксис:
 
 #include < string.h >
 char *strdup(const char *str);
 
 Аргументы:
 
 str – указатель на дублируемую строку.
 
 Возвращаемое значение:
 
 NULL – если не удалость выделить память под новую строку или скопировать строку на которую указывает аргумент str.
 Указатель на дублирующую строку.
 
 Описание:
 
 Функция strdup дублирует строку, на которую указывает аргумент str. Память под дубликат строки выделяется с помощью функции malloc, и по окончанию работы с дубликатом должна быть очищена с помощью функции free.
 
 Пример:
 
 В примере строка «0123456789» дублируется с помощью функции strdup и результат выводится на консоль. Перед завершением работы память, выделенная под дубликат строки, очищается.
 
 
 #include < stdio.h >  // Для printf
 #include < string.h > // Для strdup
 #include < stdlib.h > // Для free
 
 int main (void)
 {
 // Исходная строка
 char str [11]=”0123456789”;
 // Переменная, в которую будет помещен указатель на дубликат строки
 char *istr;
 
 // Дублирование строки
 istr = strdup (str);
 
 // Вывод дубликата на консоль
 printf (“Дубликат: %s\n“, istr);
 
 // Очищаем память, выделенную под дубликат
 free (istr);
 
 return 0;
 }
 Результат:
 
 Вывод в консоль:
 Дубликат: 0123456789*/


//Assignment name  : ft_strdup
//Expected files   : ft_strdup.c
//Allowed functions: malloc
//--------------------------------------------------------------------------------
//
//Reproduce the behavior of the function strdup (man strdup).
//
//Your function must be declared as follows:
//
//char    *ft_strdup(char *src);

