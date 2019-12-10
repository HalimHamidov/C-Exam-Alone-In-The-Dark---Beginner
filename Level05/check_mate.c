#include <unistd.h>

typedef struct  sp
{
    int x;
    int y;
}               tp;

tp fk(int bs, char **b)
{
    int x = 0;
    int y;
    while (x < bs)
    {
        y = 0;
        while (y < bs)
        {
            if (b[x][y] == 'K')
                return ((tp){x, y});
            ++y;
        }
        ++x;
    }
    return ((tp){-2, -2});
}

int cc(tp p, tp d, int bs, char **b)
{
    p.x += d.x;
    p.y += d.y;
    if (p.x < 0 || p.x >= bs || p.y < 0 || p.y >= bs)
        return (0);
    if (b[p.x][p.y] == 'Q')
        return (1);
    else if (b[p.x][p.y] == 'R')
        return (d.x == 0  || d.y == 0);
    else if (b[p.x][p.y] == 'B')
        return (d.x != 0 && d.y != 0);
    else if (b[p.x][p.y] == 'P')
        return (d.x == 1 && d.y != 0 && b[p.x-1][p.y - d.y] == 'K');
    return (cc(p, d, bs, b));
}
int cm(int bs, char **b)
{
    tp kp = fk(bs, b);
    return (
            cc(kp, (tp){-1, -1}, bs, b)
            || cc(kp, (tp){-1, 0}, bs, b)
            || cc(kp, (tp){-1, 1}, bs, b)
            || cc(kp, (tp){0, -1}, bs, b)
            || cc(kp, (tp){0, 1}, bs, b)
            || cc(kp, (tp){1, -1}, bs, b)
            || cc(kp, (tp){1, 0}, bs, b)
            || cc(kp, (tp){1, 1}, bs, b));
            
}

int main(int argc, char **argv)
{
    if (argc < 2)
        write (1, "\n", 1);
    else if (cm(argc - 1, &argv[1]))
        write (1, "Success\n", 8);
    else
        write (1, "Fail\n", 5);
    return (0);
}

//Assignment name  : check_mate
//Expected files   : *.c, *.h
//Allowed functions: write, malloc, free
//--------------------------------------------------------------------------------
//
//Write a program who takes rows of a chessboard in argument and check if your 
//King is in a check position.
//
//Chess is played on a chessboard, a squared board of 8-squares length with 
//specific pieces on it : King, Queen, Bishop, Knight, Rook and Pawns.
//For this exercice, you will only play with Pawns, Bishops, Rooks and Queen...
//and obviously a King.
//
//Each piece have a specific method of movement, and all patterns of capture are
//detailled in the examples.txt file.
//
//A piece can capture only the first ennemy piece it founds on its capture
//patterns.
//
//The board have a variable size but will remains a square. There's only one King
//and all other pieces are against it. All other characters except those used for
//pieces are considered as empty squares.
//
//The King is considered as in a check position when an other enemy piece can
//capture it. When it's the case, you will print "Success" on the standard output
//followed by a newline, otherwise you will print "Fail" followed by a newline.
//
//If there is no arguments, the program will only print a newline.
//
//Examples:
//
//$> ./chessmate '..' '.K' | cat -e
//Fail$
//$> ./check_mate 'R...' '.K..' '..P.' '....' | cat -e
//Success$
//$> ./chessmate 'R...' 'iheK' '....' 'jeiR' | cat -e
//Success$
//$> ./chessmate | cat -e
//$
//$>

