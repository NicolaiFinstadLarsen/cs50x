#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string folket[4] = {"ole", "jens", "nico", "truls"};
    string kandidater[2][2];

    kandidater[0][0] = folket[2];
    kandidater[0][1] = folket[1];
    kandidater[1][0] = folket[0];
    kandidater[1][1] = folket[3];

    int rows = sizeof(kandidater)/sizeof(kandidater[0]);
    int colums = sizeof(kandidater[0])/sizeof(kandidater[0][0]);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            printf("%s ", kandidater[i][j]);
        }
        printf("\n");
    }

    return 0;
}
