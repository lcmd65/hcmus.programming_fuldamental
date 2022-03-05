//21280102_Doan Thi Man Nhi
// Hinh thuc 14

#include <iostream>
using namespace std;
#include <math.h>

void  giaiPTB1(float b, float c, float& x)
{
	if (b == 0) {
		if (c == 0) {
			cout<<"pt co vo so nghiem" ;
		}
		else {
			cout << "pt vo nghiem";
		}
	}
	else {
		x = -c / b;
		cout << "pt co 1 nghiem la : " << x;
	}
}

void giaiPTB2(float a, float b, float c, float& x1, float& x2)
{
	float delta;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		cout << "pt vo nghiem";
	else if (delta == 0)
	{
		x1 = x2 = -b / (2 * a);
		cout << "  Phuong trinh co mot nghiem kep x=  " << x1;
	}
	else {
		x1 = (-b + sqrt(delta)) / 2 * a;
		x2 = (-b - sqrt(delta)) / 2 * a;
		cout << "\nPhuong trinh co 2 nghiem phan biet x1= " << x1 << "\n" << "x2= " << x2;
	}

}

int main()
{
	float a, b, c, x, x1, x2;
	cout << "\nNhap a : ";
	cin >> a;
	cout << "\nNhap b : ";
	cin >> b;
	cout << "\nNhap c : ";
	cin >> c;
	if (a == 0)
	{
		giaiPTB1(b, c, x);
	}
	else {
		giaiPTB2(a, b, c, x1, x2);
	}
	return 0;
}