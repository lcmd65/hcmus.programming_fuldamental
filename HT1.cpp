#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float a, b, c;
	a = 1, b = -3, c = -4;
	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				cout << "\nPhuong trinh vo so nghiem";
			else
				cout << "\nPhuong trinh vo nghiem";
		}
		else cout << "\nPhuong trinh co 1 nghiem la: " << -c / b;
	}
	else {
		float delta;
		delta = b * b - 4 * a * c;
		if (delta < 0)
			cout << " \nPhuong trinh vo nghiem ";
		else if (delta == 0)
			cout << "\nPhuong trinh co mot nghiem kep x = " << -b / (2 * a);
		else {
			cout << "\nPhuong trinh co 2 nghiem phan biet x1= " << (-b + sqrt(delta)) / 2 * a << " & " << "x2= " << (-b - sqrt(delta)) / 2 * a;
		}

	}
	return 0;
}