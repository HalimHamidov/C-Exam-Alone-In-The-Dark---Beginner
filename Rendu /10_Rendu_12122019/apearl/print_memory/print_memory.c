#include <unistd.h>

void    print_char(char c)
{
    if (c >= 32 && c <= 126)
        write (1, &c, 1);
    else
        write (1, ".", 1);
}

void    print_hex(int x)
{
    char *b;
    
    b = "0123456789abcdef";
    write (1, &b[x / 16], 1);
    write (1, &b[x % 16], 1);
}

void    print_memory(const void *addr, size_t size)
{
    size_t i;
    size_t j;
    unsigned char const *p = addr;
    
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j<16 && (i+j)<size)
        {
            print_hex(*(p+i+j));
            if (j%2)
                write (1, " ", 1);
            j++;
        }
        while (j<16)
        {
            write (1, "  ", 2);
            if (j%2)
                write (1, " ", 1);
            j++;
        }
        j = 0;
        while (j<16 && (i+j)<size)
        {
            print_char(*(p+i+j));
            j++;
        }
        write (1, "\n", 1);
        i += 16;
    }
}


/*
 
 Assignment name  : print_memory
 Expected files   : print_memory.c
 Allowed functions: write
 --------------------------------------------------------------------------------
 
 Write a function that takes (const void *addr, size_t size), and displays the
 memory as in the example.
 
 Your function must be declared as follows:
 
 void    print_memory(const void *addr, size_t size);
 
 ---------
 $> cat main.c
 void    print_memory(const void *addr, size_t size);
 
 int    main(void)
 {
 int    tab[10] = {0, 23, 150, 255,
 12, 16,  42, 103};
 
 print_memory(tab, sizeof(tab));
 return (0);
 }
 $> gcc -Wall -Wall -Werror main.c print_memory.c && ./a.out | cat -e
 0000 0000 1700 0000 9600 0000 ff00 0000 ................$
 0c00 0000 1000 0000 2a00 0000 6700 0000 ........*...g...$
 0000 0000 0000 0000                     ........$
 

 
 = Host-specific information ====================================================
 $> hostname; uname -msr
 mi-l3.21-school.ru
 Darwin 16.7.0 x86_64
 $> date
 Thu Dec 12 14:41:58 MSK 2019
 $> gcc --version
 Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
 Apple LLVM version 9.0.0 (clang-900.0.39.2)
 Target: x86_64-apple-darwin16.7.0
 Thread model: posix
 InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
 $> clang --version
 Apple LLVM version 9.0.0 (clang-900.0.39.2)
 Target: x86_64-apple-darwin16.7.0
 Thread model: posix
 InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
 
 = User files collection ========================================================
 Collecting user files from Vogsphere
 Repository URL: auto-exam/2019/c-exam-alone-in-the-dark-beginner/exam_20191212/apearl
 
 = Git history ==================================================================
 $> git -C /var/folders/2l/6nsn_nj17dzghk64807cfjn00000gq/T/tmpDpgQCt/user log --pretty='%H - %an, %ad : %s'
 317cfb4444d091a6536727ab9734334e19f6546c - Exam 42, Thu Dec 12 14:40:08 2019 +0300 : print_memory
 e58fac0165ecd000fd482b9167c220a7f6ceacc0 - Exam 42, Thu Dec 12 14:36:40 2019 +0300 : print_memory
 8e61e1184c9a9e74f3aabbeefb7bd3a8dfb1e7d6 - Exam 42, Thu Dec 12 13:41:28 2019 +0300 : check_mate
 
 = Collected files ==========================================
 $> ls -lAR /var/folders/2l/6nsn_nj17dzghk64807cfjn00000gq/T/tmpDpgQCt/user
 total 24
 -rw-r--r--  1 deepthought  deepthought  6148 Dec 12 14:42 .DS_Store
 -rw-r--r--  1 deepthought  deepthought  1109 Dec 12 14:42 __GIT_HISTORY
 drwxr-xr-x  4 deepthought  deepthought   136 Dec 12 14:42 check_mate
 drwxr-xr-x  4 deepthought  deepthought   136 Dec 12 14:42 print_memory
 
 /var/folders/2l/6nsn_nj17dzghk64807cfjn00000gq/T/tmpDpgQCt/user/check_mate:
 total 24
 -rw-r--r--  1 deepthought  deepthought  6148 Dec 12 14:42 .DS_Store
 -rw-r--r--  1 deepthought  deepthought  1611 Dec 12 14:42 check_mate.c
 
 /var/folders/2l/6nsn_nj17dzghk64807cfjn00000gq/T/tmpDpgQCt/user/print_memory:
 total 24
 -rw-r--r--  1 deepthought  deepthought  6148 Dec 12 14:42 .DS_Store
 -rw-r--r--  1 deepthought  deepthought   937 Dec 12 14:42 print_memory.c
 
 = print_memory =================================================================
 $> gcc -Wextra -Wall -Werror print_memory.c main.c -o user_exe
 
 = Test 1 ===================================================
 $> ./nnt1pwwi4y9x965i1yto3ytr
 $> diff -U 3 user_output_test1 test1.output | cat -e
 
 Diff OK :D
 Grade: 1
 
 = Final grade: 1 ===============================================================

 */

