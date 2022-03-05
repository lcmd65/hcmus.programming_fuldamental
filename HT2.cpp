#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float a, b, c, n, x0, x, d;
    cout<<"Nhap he so cua phuong trinh bac hai a.x^2 + b.x + c";
    cout<<"\na = "; 
    cin>>a;
    cout<<"\nb = "; 
    cin>>b;
    cout<<"\nc = "; 
    cin>>c;
    if (a==0){
        if (b==0){
            if (c==0){
                cout<<"\nVo so nghiem.";
            }
            else {
                cout<<"\nVo nghiem.";
            }
        }
        else {
            n =1;
            x = -1.0*c/b;
            cout<<"\nPhuong trinh co "<<n<<" nghiem x = "<<x;
        }
    }
    else{
        d = pow(b,2) - 4*a*c;
        if (d<0){
            cout<<"\nVo nghiem.";
        }
        else if (d == 0){
            n = 1;
            x = -1.0*b/(2*a);
            cout<<"\nPhuong trinh co "<<n<<" nghiem kep x = "<<x;
        }
        else {
            n =2;
            x0 = 1.0*(-b+sqrt(d))/(2*a);
            x = -1.0*b/a-x0;
            cout<<"\nPhuong trinh co "<<n<<" nghiem x1 = "<<x0<<", x2 = "<<x;
        }
    }

    return 0;
}