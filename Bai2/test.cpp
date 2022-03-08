#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

struct phanso{
    int tu;
    int mau;
};
typedef struct phanso PhanSo;

struct danhsach{
    PhanSo *arr;
    int n;
};
typedef struct danhsach DanhSach;

void menuBT2();
void nhapMotPhanSo(DanhSach &list);
void xuatPhanSo(DanhSach &list);
void nhapMotPhanSo(DanhSach &list);
void xoaMotPhanSo();
void suaGiaTriPhanSo();
void tinhTongDayPhanSo();
void sapXepDay();
void timCacPhanSo();
void ketThuc();
phanso rutgonPhanSo(phanso ps);
int timUCLN(int a, int b);
void rutgon(danhsach list);
bool checkSNT(int n);
bool checkPSNT(phanso ps);
void xuatPSNT(danhsach list);
// fuction

int GetRandom(int min,int max){
    int a = 1+ min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
    if (a!=0){
        return a;
    }
    else{
        return GetRandom(min, max);
    }
}

int chonMenu(){
	int n = 0;
	cout << "\n\nMoi chon menu: ";
	cin >> n;
	if (n > 0 || n <=8){
		return n;
    }
	else{
        return chonMenu();
    }
}


void menuBT2(DanhSach &list){

    cout << "--------------MENU--------------"<<endl;
    cout << "Hay chon 1 so ung voi chuc nang yeu cau" << endl;
    cout << "1: Xuat day phan so"<< endl;
    cout << "2: Nhap them 1 phan so"<< endl;
    cout << "3: Xoa 1 phan so"<< endl; 
    cout << "4: Sua gia tri 1 phan so"<< endl;
    cout << "5: Tinh tong day phan so"<< endl;
    cout << "6: Sap xep lai day theo thu tu tang"<< endl;
    cout << "7: Tim ca phan so (sau khi toi gian) co tu va mau deu la cac so nguyen to"<< endl;
    cout << "8: Ket thuc, giai phong bo nho ma mang chiem giu và thoat chuong trinh"<< endl;

    int temp = chonMenu();
    switch(temp){
        case 1:
            xuatPhanSo(list);
            break;
        case 2:
            nhapMotPhanSo(list);
            break;
        case 3:
            xuatPSNT(list);
        case 4:
        case 5:
        case 6:
        case 7:
        case 8: 
        case 0: 
            cout << "out";
            delete []list.arr;
            exit(1);
            break;
    }
}

DanhSach taoMangTuDong(){
    DanhSach list;
    cout << "Nhap so phan tu";
    cin >> list.n ;
    list.arr = new PhanSo[list.n];
    return list;
}

void xuatMotPhanSo(PhanSo &a){
    cout << a.tu << "/" << a.mau <<endl;
}

void xuatPhanSo(DanhSach &list){
    for(int i=0; i<list.n; i++){
        list.arr[i] = rutgonPhanSo(list.arr[i]);
        xuatMotPhanSo(list.arr[i]);
    }
}

void taoMotGiaTri(PhanSo &a){
    a.tu = GetRandom(-1000,1000);
    do{
        a.mau = GetRandom(-1000,1000);
    }while(a.mau==0);
}

void ganDanhSach(DanhSach &list){
    srand(int(time(0)));
    for(int i=0; i<list.n; i++){
        taoMotGiaTri(list.arr[i]);
    }
}

void nhapMotPhanSo(DanhSach &list)
{
    PhanSo *ar = new PhanSo[list.n+1];
    for(int i=0; i<list.n; i++){
        ar[i]= list.arr[i];
    }
    delete [] list.arr;
    list.arr = new PhanSo[list.n +1];
    list.n =list.n +1;
    for(int i=0; i<list.n; i++){
        list.arr[i]= ar[i];
    }
    taoMotGiaTri(list.arr[list.n]);
    delete []ar;
}
//Rút gọn phân số
int timUCLN(int a, int b){
    a = abs(a);
    b = abs(b);
    while(a!=b){
        if(a>b) a-=b;
        else b-=a;
    }
    return a;
}

phanso rutgonPhanSo(phanso ps){
    int us = timUCLN(ps.tu, ps.mau);
    if(ps.tu == 0)  return ps;
    if(ps.mau<0){
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    ps.tu /= us;
    ps.mau /= us;
    return ps;
}
/*
void rutgon(danhsach list){
    for(int i = 0; i<list.n; i++){
        list.arr[i] = rutgonPhanSo(list.arr[i]);
    }
}
*/

//check SNT
bool checkSNT(int n){
    n = abs(n);
    if(n<2) return false;
    else if(n==2){
        return true;
    }
    else{
        for(int i=2; i<sqrt(n); i++){
            if(n%i==0)  return false;
        }
        return true;
    }
}

bool checkPSNT(phanso ps){
    ps = rutgonPhanSo(ps);
    if(checkSNT(ps.tu)==true && checkSNT(ps.mau)==true) return true;
    else    return false;
}

void xuatPSNT(danhsach list){
     for(int i=0; i<list.n; i++){
        if(checkPSNT(list.arr[i])==true)
            xuatMotPhanSo(list.arr[i]);
    }
}

//main

int main(){
    DanhSach list;
    cout << "Nhap so phan tu";
    cin >> list.n ;
    list.arr = new PhanSo[list.n];
    ganDanhSach(list);
	while (true){
		menuBT2(list);
	}
    return 0;
}
