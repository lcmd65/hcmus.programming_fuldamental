#include <iostream>
#include<math.h>

#define delta(a,b,c) b*b-4*a*c
#define PTNghiemlon(a,b,c) (-b+sqrt(b*b-4*a*c))/(2*a)
#define PTNghiemnho(a,b,c) (-b-sqrt(b*b-4*a*c))/(2*a)

using namespace std;


void GiaiPT(){
    cout<< "nhap cac gia tri a,b,c"<< endl;
    float a,b,c;
    cin >> a >> b >> c;
    if(a==0){
        if(b==0){
            if(c==0){
                cout<<"PT co vo so nghiem";
            }
            else{
                cout << "PT vo nghiem";
            }
        }
        else{
            cout <<" PT co nghiem" << -c/b ;
        }
    }
    else{
        if(delta(a,b,c) <0){
            cout <<"PT vo nghiem";
        }
        else{
            cout <<"Pt co nghiem x1, x2 la"<< PTNghiemlon(a,b,c) << PTNghiemnho(a,b,c);
        }
    }
}

int main(){
    GiaiPT();
    return 0;
}

