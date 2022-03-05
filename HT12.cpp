//21280102_Doan Thi Man Nhi
// Hinh thuc 

#include <iostream>
using namespace std;
#include <math.h>

void nhap(float& a, float& b, float& c)
{
	cout << "\nNhap a : ";
	cin >> a;
	cout << "\nNhap b : ";
	cin >> b;
	cout << "\nNhap c : ";
	cin >> c;
}

int giaiPTB2(float a, float b, float c, float& x, float& x1, float& x2)
{
	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				return -1; //pt co vo so nghiem
			else
				return 0; //pt vo nghiem 
		}
		else {
			x = -c / b;
			return -2; // Phuong trinh co 1 nghiem la -c / b
		}
	}
	else {
		float delta;
		delta = b * b - 4 * a * c;
		if (delta < 0)
			return 0; //pt vo nghiem 
		else if (delta == 0)
		{
			x1 = x2 = -b / (2 * a);
			return 1; // Phuong trinh co mot nghiem kep x = -b / (2 * a)
		}
		else {
			x1 = (-b + sqrt(delta)) / 2 * a;
			x2 = (-b - sqrt(delta)) / 2 * a;
			return 2; // Phuong trinh co 2 nghiem phan biet x1=(-b + sqrt(delta)) / 2 * a va x2=(-b - sqrt(delta)) / 2 * a
		}

	}
}

void xuat(int K, float x, float x1, float x2)
{
	if (K == -1)
		cout << "\nPhuong trinh vo so nghiem ";
	else if (K == 0)
		cout << "\nPhuong trinh vo nghiem ";
	else if (K == -2)
		cout << "\nPhuong trinh co 1 nghiem duy nhat x=" << x;
	else if (K == 1)
		cout << "\nPhuong trinh co 1 nghiem kep duy nhat x1=x2= " << x1;
	else
		cout << "\nPhuong trinh co 2 nghiem phan biet x1= " << x1 << "\n" << "x2= " << x2;
}

int main()
{
	float a, b, c, x, x1, x2;
	nhap(a, b, c);
	int K = giaiPTB2(a, b, c, x, x1, x2);
	xuat(K, x, x1, x2);
	return 0;
}