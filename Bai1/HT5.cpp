//21280102_Doan Thi Man Nhi
// Hinh thuc 5
#include <iostream>
using namespace std;
#include <math.h>

void giaiPTB2(float a, float b, float c)
{
	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				cout << "\nPhuong trinh vo so nghiem";
			else
				cout << "\nPhuong trinh vo nghiem";
		}
		else cout << "\nPhuong trinh co 1 nghiem la : " << -c / b;
	}
	else {
		float delta;
		delta = b * b - 4 * a * c;
		if (delta < 0)
			cout << " \nPhuong trinh vo nghiem ";
		else if (delta == 0)
			cout << "\nPhuong trinh co mot nghiem kep x = " << -b / (2 * a);
		else {
			cout << "\nPhuong trinh co 2 nghiem phan biet x1= " << (-b + sqrt(delta)) / 2 * a << "\n" << "x2= " << (-b - sqrt(delta)) / 2 * a;
		}

	}
}

int main()
{
	float a, b, c;
	cout << "\nNhap a : ";
	cin >> a;
	cout << "\nNhap b : ";
	cin >> b;
	cout << "\nNhap c : ";
	cin >> c;
	giaiPTB2(a, b, c);
	return 0;
}