#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"> ";
    cin>>n;
    //a排
    for(int i=1; i<=n; i++){
        cout<< i%10 <<" ";
    }
    cout<<endl;

    //b排、中間空格、c排
    int b = 4*n-4;
    int c = n+1;  
    for(int i=1; i<=n-2; i++){
        cout<< b%10;
        for(int j=1; j<=2*n-3; j++){//2n-1 再-2
            cout<<" ";
        }
        cout<< c%10;
        cout<<endl;
        b--;
        c++;
    }

    //d排
    int d = 3*n-2;
    for(int i=1; i<=n ; i++){
        cout<< d%10 <<" ";
        d--;
    }   
    cout<<endl;
    system("pause");
    return 0;
}


