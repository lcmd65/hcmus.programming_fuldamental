#include <iostream>
#include <math.h>
using namespace std;
struct heso{
    heso(float m, float n, float p){
        a = m;
        b = n;
        c = p;
    }
    float a;
    float b;
    float c;
};
int main()
{
	heso hs(1, -3, -4);
	if (hs.a == 0) {
		if (hs.b == 0) {
			if (hs.c == 0)
				cout << "\nPhuong trinh vo so nghiem";
			else
				cout << "\nPhuong trinh vo nghiem";
		}
		else cout << "\nPhuong trinh co 1 nghiem la: " << -hs.c / hs.b;
	}
	else {
		float delta;
		delta = pow(hs.b,2) - 4 * hs.a * hs.c;
		if (delta < 0)
			cout << " \nPhuong trinh vo nghiem ";
		else if (delta == 0)
			cout << "\nPhuong trinh co mot nghiem kep x = " << -hs.b / (2 * hs.a);
		else {
			cout << "\nPhuong trinh co 2 nghiem phan biet x1= " << (-hs.b + sqrt(delta)) / 2 * hs.a << " & " << "x2= " << (-hs.b - sqrt(delta)) / 2 * hs.a;
		}

	}
	return 0;
}
