#include <iostream>
using namespace std;

//走法偏移量(右下始 逆時針):      x=n, y=n-1; (OK)
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};



int main(){
    int n, x, y, index, cut_side_length, count, count2=1;
    cout<<"> ";
    cin>>n;

    int array[n][n] = {0};//這個不是初始化嗎?
    index = 0;
    x=n, y=n-1; 
    cut_side_length = n;
    count = 1;

    //會有奇怪bug [0][1] 到 [0][n-1]並未初始化(溢位)
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            array[i][j] = 0;
        }
    }

    //填入數值
    for(int i=1; i <= (n*n+n)*0.5; i++){
        //繼續走
        x += dir_x[index];
        y += dir_y[index];
        //沒辦法，0不知道怎麼改先改成-1，之後再寫判斷改成0
        if(i%10==0)
            array[x][y] = -1;     
        else
           array[x][y] = i%10;//原本只有這行     
        
        //如果到達該邊長末端
        if(i == cut_side_length){
            //換方向
            index = (index + 1) % 4;
            //縮減邊長
            cut_side_length += n - count;
            count++;
        }
    }
    //輸出// 待修改
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(array[i][j]==0){
                cout<<"  ";
            }
            else if(array[i][j]==-1 ){
                array[i][j] = 0;
                cout<<array[i][j] << " ";
            }
            else{
                cout<<array[i][j] << " ";
            }
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}
//int c = (n*n+n)*0.5;//最原始公式 n*n - (n-1)*n*0.5


//逆時針:

// 走法偏移量(右上始 逆時針):    左->下->右->上   x=0, y=n (OK)
// int dir_x[4] = {0, 1, 0, -1};
// int dir_y[4] = {-1, 0, 1, 0};

// 走法偏移量(左上始 逆時針):      x=-1, y=0 bug: [0][1] 到 [0][n-1]並未初始化(溢位)
// int dir_x[4] = {1, 0, -1, 0};
// int dir_y[4] = {0, 1, 0, -1};

// 走法偏移量(左下始 逆時針):      x=n-1, y=-1 (OK)
// int dir_x[4] = {0, -1, 0, 1};
// int dir_y[4] = {1, 0, -1, 0};

//走法偏移量(右下始 逆時針):      x=n, y=n-1 (OK)
// int dir_x[4] = {-1, 0, 1, 0};
// int dir_y[4] = {0, -1, 0, 1};



//順時針:

// 走法偏移量(左上始 順時針):       x=0, y=-1; (OK)
// int dir_x[4] = {0, 1, 0, -1};
// int dir_y[4] = {1, 0, -1, 0};

// 走法偏移量(左下始 順時針):       x=n ,y=0; OK
// int dir_x[4] = {-1, 0, 1, 0}; 
// int dir_y[4] = {0, 1, 0, -1};

// 走法偏移量:(右下始 順時針)    x=n-1, y=n; 有bug! (OK)
// int dir_x[4] = {0, -1, 0, 1};
// int dir_y[4] = {-1, 0, 1, 0};

// 走法偏移量(右上始 順時針):       x=-1, y=n-1; OK
// int dir_x[4] = {1, 0, -1, 0}; 
// int dir_y[4] = {0, -1, 0, 1};