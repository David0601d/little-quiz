#include <stdio.h>
#include <stdlib.h>
//https://ithelp.ithome.com.tw/articles/10190384
#define SIZE 5


//走法偏移量: 右->下->左->上
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

int main()
{
    int index, x, y, temp_x, temp_y;
    int array[SIZE][SIZE] = {0};

    index = 0;
    x = 0;
    
    y = -1;

    for (int i = 0; i < SIZE * SIZE; i++)
    {
        //試走，如果超出邊界或遇到已經走過的格子，index + 1 轉彎
        temp_x = x + dir_x[index];
        temp_y = y + dir_y[index];
        
        if (temp_x < 0 || temp_x > SIZE - 1 || 
            temp_y < 0 || temp_y > SIZE - 1 || 
            array[temp_x][temp_y] != 0)
        {
            index = (index + 1) % 4;
        }
        //往下一個座標前進
        x = x + dir_x[index];
        y = y + dir_y[index];
        array[x][y] = i + 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;

}