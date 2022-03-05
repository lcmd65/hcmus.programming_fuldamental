#include <iostream>
#include <math.h>
using namespace std;

void nhap(float &a,float &b,float &c){
    cout << "\nNhap he so:";
	cout << "\na = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
}
int giaiPTB1(float b, float c, float& x){
    if (b == 0) {
        if (c == 0)
            return 3; //vo so nghiem
        else
            return 0; //vo nghiem 
    }
    else {
        x = -c/b;
        return 1; //1 nghiem -c/b
    }
}
int giaiPTB2(float a, float b, float c, float& x, float& x1, float& x2){
    float delta = pow(b,2) - 4*a*c;
    if (delta < 0)  return 0; //vo nghiem 
    else if (delta == 0)
    {
        x = -b/(2*a);
        return 1; //1 nghiem kep x = -b/(2*a)
    }
    else {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = -x1 - b/a;
        return 2; //2 nghiem x1 = (-b + sqrt(delta)) / (2*a) va x2 = -x1 - b/a
    }
}

void xuat (int n, float x, float x1, float x2){
    switch(n){
        case 0:
            cout << "\nPhuong trinh vo nghiem ";
            break;
        case 1:
            cout << "\nPhuong trinh co mot nghiem x = " << x;
            break;
        case 2:
            cout << "\nPhuong trinh co hai nghiem x1 = " << x1 << " & " << "x2 = " << x2;
            break;
        default:
            cout << "\nPhuong trinh co vo so nghiem ";
    }
}

int main()
{
    float a, b, c, x, x1, x2;
    int n;
    nhap(a,b,c);
    if(a==0)   n = giaiPTB1(b, c, x);
    else    n = giaiPTB2(a, b, c, x, x1, x2);
    xuat(n,x,x1,x2);
    return 0;
}
