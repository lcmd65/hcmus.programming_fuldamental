#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float a,b,c,d;
    cout<<"Nhap lan luot cac he so, cach nhau boi dau cach: ";
    cin>>a>>b>>c;
    if (a){
        d=b*b-4*a*c;
        if (d<0) cout<<"Vo nghiem !";
        else if (d==0) cout<<"Nghiem kep x = "<<-b/a;
        else {
            cout<<"Hai nghiem phan biet :\n";
            cout<<"x1 = "<<(-b-sqrt(d))/2*a<<" & x2 = "<<(-b+sqrt(d))/2*a;
        }
    }else if (b) cout<<"Mot nghiem x = "<<-c/b;
    else if (c) cout<<"Vo nghiem!";
    else cout<<"Vo so nghiem!";
    return 0;
}