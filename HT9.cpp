#include <iostream>
#include<math.h>

using namespace std;

//ham truyen ca value , reference

void GiaiPTB1(float a, float b, float & x){
    x = -b/a;
}

//ham truyen ca value , reference

void GiaiPTB2(float a, float b, float c, float & x1, float & x2,float delta){
    if(delta==0){
        x1 = x2 = -b/(2*a);
    }
    else{
        x1= (-b+ sqrt(delta))/(2*a);
        x2= (-b+ sqrt(delta))/(2*a);
    } 
}
// ham giai phuong trinh tat ca cac truong hop

void GiaiPT(){
    cout<< "nhap cac gia tri a,b,c"<< endl;
    float a,b,c;
    cin >> a >> b >> c;
    float x1, x2;
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
            GiaiPTB1(b,c,x1);
            cout <<" PT co nghiem" << x1;
        }
    }
    else{
        float delta= b*b-4*a*c;
        if(delta <0){
            cout <<"PT vo nghiem";
        }
        else{
            GiaiPTB2(a,b,c,x1,x2,delta);
            cout <<"Pt co nghiem x1, x2 la"<< x1 << x2;
        }
    }
}

int main(){
    GiaiPT();
    return 0;
}

