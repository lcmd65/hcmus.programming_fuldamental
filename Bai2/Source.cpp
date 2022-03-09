#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

struct phanso {
    int tu;
    int mau;
};
typedef struct phanso PhanSo;

struct danhsach {
    PhanSo* arr; //khai bao 1 mang dong chua phan so 
    int n;
};
typedef struct danhsach DanhSach;

void menuBT2(DanhSach &list);
void nhapMotPhanSoVaoDay(DanhSach& list);
void xuatPhanSo(DanhSach& list);
PhanSo nhapMotPhanSo(PhanSo & ps);
bool xoaMotPhanSo(DanhSach &list,int pos);
bool suaGiaTriPhanSo(DanhSach &list , int pos);
PhanSo tinhTongDayPhanSo(DanhSach ds);
void sapXepDay(DanhSach& list);
PhanSo rutgonPhanSo(PhanSo ps);
void timCacPhanSo();
void ketThuc();
bool checkSNT(int n);
bool checkPSNT(phanso ps);
void xuatPSNT(danhsach list);

                                                   // FUNCTION //

// Ham lay gia tri ngau nhien
int GetRandom(int min, int max) {
    int a = 1 + min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
    if (a != 0) {
        return a;
    }
    else {
        return GetRandom(min, max);
    }
}

int chonMenu() {
    int n = 0;
    cout << "\n\nMoi chon menu: ";
    cin >> n;
    if (n > 0 || n <= 8) {
        return n;
    }
    else {
        return chonMenu();
    }
}

void xuatMotPhanSo(PhanSo& a) {
    cout << a.tu << "/" << a.mau << endl;
}

void menuBT2(DanhSach& list)
{
    int pos;
    bool k;
    cout << "--------------MENU--------------" << endl;
    cout << "Hay chon 1 so ung voi chuc nang yeu cau" << endl;
    cout << "1: Xuat day phan so" << endl;
    cout << "2: Nhap them 1 phan so" << endl;
    cout << "3: Xoa 1 phan so " << endl;
    cout << "4: Sua gia tri 1 phan so" << endl;
    cout << "5: Tinh tong day phan so" << endl;
    cout << "6: Sap xep lai day theo thu tu tang" << endl;
    cout << "7: Tim ca phan so (sau khi toi gian) co tu va mau deu la cac so nguyen to" << endl;
    cout << "8: Ket thuc, giai phong bo nho ma mang chiem giu và thoat chuong trinh" << endl;

    int temp = chonMenu();
    switch (temp) {
    case 1:
        xuatPhanSo(list);
        break;
    case 2:
        nhapMotPhanSoVaoDay(list);
        break;
    case 3:
    {
       
        cout << "Mang truoc khi xoa la ";
        xuatPhanSo(list);
        cout << "Nhap vi tri muon xoa (Vi tri bat dau la 0) ";
        cin >> pos;
        k=xoaMotPhanSo(list,pos);
        if (k = false)
            cout << "Vi tri khong hop le.";
        else {
            cout << "mang sau khi xoa la ";
            xuatPhanSo(list);
        }
    }
    break;
    case 4:
    {
        PhanSo ps;
        cout << "Mang truoc khi sua la ";
        xuatPhanSo(list);
        cout << "Nhap vi tri muon sua (Vi tri bat dau la 0) ";
        cin >> pos;
        k = suaGiaTriPhanSo(list,pos);
        if (k = false)
            cout << "Vi tri khong hop le.";
        else {
            cout << "mang sau khi sua la ";
            xuatPhanSo(list);
        }
    }
    break;
    case 5:
    {
        PhanSo ketqua;
        cout << "Mang ban dau la ";
        xuatPhanSo(list);
        cout << "Tong day phan so la : ";
        ketqua = tinhTongDayPhanSo(list);
        xuatMotPhanSo(ketqua);
    }
    break;
    case 6:
    {
        cout << "Mang ban dau la ";
        xuatPhanSo(list);
        cout << "mang sau khi sap xep tang dan ";
        sapXepDay(list);
        xuatPhanSo(list);
    }
    break;
    case 7:
            xuatPSNT(list);
            break;
    case 8:
        cout << "out";
        delete[]list.arr;
        exit(1);
        break;
    }
}

DanhSach taoMangTuDong() {
    DanhSach list;
    cout << "Nhap so phan tu";
    cin >> list.n;
    list.arr = new PhanSo[list.n];
    return list;
}


void xuatPhanSo(DanhSach& list) {
    for (int i = 0; i < list.n; i++) {
        xuatMotPhanSo(list.arr[i]);
    }
}

void taoMotGiaTri(PhanSo& a) {
    a.tu = GetRandom(-1000, 1000);
    a.mau = GetRandom(-1000, 1000);
}

void ganDanhSach(DanhSach& list) {
    srand(int(time(0)));
    for (int i = 0; i < list.n; i++) {
        taoMotGiaTri(list.arr[i]);
    }
}

// Ham tu dong nhap them 1 phan so vao cuoi mang
void nhapMotPhanSoVaoDay(DanhSach& list)
{
    PhanSo* ar = new PhanSo[list.n + 1];
    for (int i = 0; i < list.n; i++) {
        ar[i] = list.arr[i];
    }
    delete[] list.arr;
    list.arr = new PhanSo[list.n + 1];
    list.n = int(list.n + 1);
    for (int i = 0; i < list.n-1; i++) {
        list.arr[i] = ar[i];
    }
    list.arr[list.n-1] = nhapMotPhanSo(list.arr[list.n-1]);
    delete[]ar;
}
//XOA 1 PHAN TU TRONG MANG 
bool xoaMotPhanSo(DanhSach& list , int pos) {
    // Vi tri khong hop le
    if (pos < 0 || pos >= list.n)
        return false;
    else {
        // Dich chuyen mang
        for (int i = pos; i < list.n - 1; i++) {
            list.arr[i] = list.arr[i + 1];
        }
        // Giam so luong phan tu sau khi xoa.
        --list.n;
    } return true;
}
//Nhap 1 phan so moi 
PhanSo nhapMotPhanSo(PhanSo& ps)
{
    cout << "Nhap tu so ";
    cin >> ps.tu;
    cout << "Nhap mau so ";
    cin >> ps.mau;
    return ps;
}
//SUA 1 PHAN SO TRONG MANG 
bool suaGiaTriPhanSo(DanhSach& list, int pos)
{
    PhanSo ps;
    if (pos < 0 || pos >= list.n){
        return false;
    } 
    else {
        list.arr[pos] = nhapMotPhanSo(ps);
    }
} 

PhanSo Tinh_Tong_2_Phan_So(PhanSo x, PhanSo y)
{
    PhanSo ketqua;
    if (x.mau != y.mau)
    {
        ketqua.tu = (x.tu * y.mau) + (y.tu * x.mau);
        ketqua.mau = x.mau* y.mau;
    }
    else
    {
        ketqua.tu = x.tu + y.tu;
        ketqua.mau = x.mau;
    }
    return ketqua;
}


PhanSo tinhTongDayPhanSo(DanhSach ds)
{
    PhanSo ketqua= ds.arr[0];
    for (int i = 1; i < ds.n; i++)
    {
        ketqua = Tinh_Tong_2_Phan_So(ketqua, ds.arr[i]);
    }
    return ketqua;
}

//rut gon phan so
int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

PhanSo rutgonPhanSo(PhanSo ps) {
    int us = timUCLN(ps.tu, ps.mau);
    if (ps.tu == 0)  return ps;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    ps.tu /= us;
    ps.mau /= us;
    return ps;
}

void sapXepDay(DanhSach& list)
{
    PhanSo tam;
    for (int i = 0; i < list.n - 1; i++)
        for (int j = i + 1; j < list.n; j++)
        {
            if (list.arr[i].tu *1.0/ list.arr[i].mau > list.arr[j].tu*1.0   / list.arr[j].mau)
            {
                tam = list.arr[i];
                list.arr[i] = list.arr[j];
                list.arr[j] = tam;
            }
        }
}

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

int main() {
    DanhSach list;
    cout << "Nhap so phan tu : ";
    cin >> list.n;
    list.arr = new PhanSo[list.n];
    ganDanhSach(list);
    while (true) {
        menuBT2(list);
    }
    return 0;
}
