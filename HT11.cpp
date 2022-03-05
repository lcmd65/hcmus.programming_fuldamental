#include <iostream>
#include <math.h>
#include <string>
using namespace std;
void giai1();
void giai2();
float a, b, c, x0, x, d;
float n = 0;
string ketqua;

int main(){ 
    cout<<"Nhap he so cua phuong trinh bac hai a.x^2 + b.x + c";
    cout<<"\na = "; 
    cin>>a;
    cout<<"\nb = "; 
    cin>>b;
    cout<<"\nc = "; 
    cin>>c;
    if (a==0)   giai1();
    else   giai2();
    if (n==1) cout<<ketqua<<x0<<" "<<x;
    else cout<<ketqua;
    return 0;
}
void giai1(){
    if (b==0){
        if (c==0){
            ketqua = "Vo so nghiem.";
        }
        else {
            ketqua = "Vo nghiem.";
        }
    }
    else {
        n =1;
        x = -1.0*c/b;
        ketqua = "Phuong trinh co mot nghiem: ";
    }
}
void giai2(){
    d = pow(b,2) - 4*a*c;
    if (d<0){
        ketqua = "Vo nghiem.";
    }
    else if (d == 0){
        n = 1;
        x = -1.0*b/(2*a);
        ketqua = "Phuong trinh co mot nghiem kep: ";
    }
    else {
        n =1;
        x0 = 1.0*(-b+sqrt(d))/(2*a);
        x = -1.0*b/a-x0;
        ketqua = "Phuong trinh co hai nghiem: ";
    }

}
