/*
    Subhashis Suara
    UCSE19012
*/

#include <stdio.h>

int size = 10; // This is also the number of queens

int chessboard[10][10];

int canAttack(int i,int j)
{
    int k, l;
    
    // Checking rows and columns
    for(k = 0;k < size;k++)
    {
        if((chessboard[i][k] == 1) || (chessboard[k][j] == 1))
            return 1;
    }
 
    // Checking diagonals
    for(k = 0;k < size;k++)
    {
        for(l = 0;l < size;l++)
        {
            if(((k + l) == (i + j)) || ((k - l) == (i - j)))
            {
                if(chessboard[k][l] == 1)
                    return 1;
            }
        }
    }
    
    return 0;
}

int nQueen(int queen)
{
    /*
        - If all returns are 0 then solution is completed

        - If even one of the returns in 1 then that queen 
          is removed and checking continues (backtracking)
    */
    int i, j;

    if(queen == 0) // queen = 0 means solution is completed as all queens have been placed successfully
        return 0;

    for(i = 0;i < size;i++)
    {
        for(j = 0;j < size;j++)
        {
            if((!canAttack(i,j)) && (chessboard[i][j] != 1))
            {
                chessboard[i][j] = 1;
                if(nQueen(queen - 1) == 0) // Trying to place other queens with the current one(s)
                    return 0;
                chessboard[i][j] = 0;
            }
        }
    }

    return 1;
}

int main()
{
    int i, j;

    for(i = 0;i < size;i++)
        for(j = 0;j < size;j++)
            chessboard[i][j]=0;

    nQueen(size);

    /*
        Output:
        1 -> Queen
        0 -> Empty
    */
    for(i = 0;i < size;i++)
    {
        for(j = 0;j < size;j++)
            printf("%d ", chessboard[i][j]);
        printf("\n");
    }

    return 0;
}
