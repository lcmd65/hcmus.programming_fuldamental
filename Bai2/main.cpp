#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cstdlib>

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
void nhapMotPhanSo();
void xuatPhanSo(DanhSach &list);
// fuction

void menuBT2(){
    
}

void xuatMotPhanSo(PhanSo &a){
    cout << a.tu << "/" << a.mau <<endl;
}

void xuatPhanSo(DanhSach &list){
    for(int i=0; i<list.n; i++){
        xuatMotPhanSo(list.arr[i]);
    }
}

void taoMotGiaTri(PhanSo &a){
    a.tu = rand();
    a.mau = rand();
}

void ganDanhSach(DanhSach &list){
    for(int i=0; i<list.n; i++){
        taoMotGiaTri(list.arr[i]);
    }
}

void enterOneFraction(DanhSach &list){
    list.n+=1;
    taoMotGiaTri(list.arr[list.n]);
}

//main

int main(){
    DanhSach list;
    cout << "Nhap so phan tu";
    cin >> list.n ;
    list.arr = new PhanSo[list.n];
    ganDanhSach(list);
    xuatPhanSo(list);
    cout << rand();
    return 0;
}