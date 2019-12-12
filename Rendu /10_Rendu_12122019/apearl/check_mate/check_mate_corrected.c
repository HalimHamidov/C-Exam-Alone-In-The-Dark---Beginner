//not passed exam
#include <unistd.h>

typedef struct  sp
{
    int x;
    int y;
}               tp;

tp fk(int bs, char **b);
int cm(int bs, char **b);
int cc(tp p, tp d, int bs, char **b);

int main(int argc, char **argv)
{
    int i = 0;
    if (argc < 2)
        write (1, "\n", 1);
    else if (cm(argc-1, &argv[1]))
        write (1, "Success\n", 8);
    else
        write (1, "Fail\n", 5);
    return (0);
}

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

int cm(int bs, char **b)
{
    tp kp = fk(bs, b);
    
    return (cc(kp, (tp){-1, -1}, bs, b)
                || cc(kp, (tp){-1, 0}, bs, b)
                || cc(kp, (tp){-1, 1}, bs, b)
                || cc(kp, (tp){0, -1}, bs, b)
                || cc(kp, (tp){0, 1}, bs, b)
                || cc(kp, (tp){1, -1}, bs, b)
                || cc(kp, (tp){1, 0}, bs, b)
                || cc(kp, (tp){1, 1}, bs, b)
                );
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
        return (d.x == 0 || d.y == 0);
    else if (b[p.x][p.y] == 'B')
        return (d.x != 0 && d.y != 0);
    else if (b[p.x][p.y] == 'P')
        return (d.x == 1 && d.y != 0 && b[p.x - 1][p.y - d.y] == 'K');
    return (cc(p, d, bs, b));
}


