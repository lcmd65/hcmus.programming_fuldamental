#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// khai bao cac dinh nghia
struct ngaythangnam {
    string ngay;
    string thang;
    string nam;
}; 
typedef struct ngaythangnam date;

struct muitiem {
    int stt;
    string tenVacXin;
    date ngayTiem;
    string maNoiTiem;        
};

struct Covid19{
    string CMND;
    string hoTen;
    date ngaySinh;
    muitiem *muiTiem;
    int soLuongMuiTiem;
};

struct danhsach{
    Covid19 *arr;
    int n;
};
typedef struct danhsach DanhSach;

                        //Fuction//
                        
int chonMenu();
void menuBT2();
void taoMotMangDong(DanhSach &list, int size);
void themMotPhanTuDS();
void xoaMotPhanTuKhoiDS();
void suaThongTinMotPhanTu();
void sapXepDS();
void XuatDS();
void nguoiChuaTiemKMui();


int chonMenu(){
    int n = 0;
    cout << "\nMoi chon menu: ";
    cin >> n;
    if (n > 0 || n <= 8) {
        return n;
    }
    else {
        return chonMenu();
    }
}

void menuBT2(){
    cout << "_________________________Menu________________________" << endl;
    cout << "Bat dau toa danh sach benh nhan dau tien" << endl;
    cout << "Hay chon mot chuc nang" << endl;
    cout << "1. Tao mang dong va nhap danh sach vao mang "<< endl;
    cout << "2. Them mot phan tu vao danh sach "<< endl;
    cout << "3. Xoa mot phan tu khoi danh sach" << endl;
    cout << "4. Sua thong tin mot phan tu" << endl;
    cout << "5. Sap xep danh sach theo so CMND" << endl;
    cout << "6.Xuat danh sach"<< endl;
    cout << "7.Xac dinh nhung nguoi chua tiem du K mui"<< endl;
    cout << "8. Ket thuc chuogn trình"<< endl;
    int n;
    n= chonMenu();
    switch(n){
        case 1:
         DanhSach list;
            int size;
            cout << "nhap danh sach" << endl;
            cin >> size;
            taoMotMangDong(list, size);
            break;
        case 2:break;
        case 3:break;
        case 4:break;
        case 5:break;
        case 6:break;
        case 7:break;
        case 8:{ 
            cout << "out";
            delete[]list.arr;
            exit(1);
            break;
        }
    }
}

void nhapDanhSachDauTien(DanhSach &list){
    for(int i=0; i< list.n; i++){
        
    }
}

void nhapNgay(date & Ngay){
    cout << "ngay";
    cin >> Ngay.ngay;
    cout << "thang";
    cin >> Ngay.thang;
    cout << "nam";
    cin >> Ngay.nam;
}

void muiTiemThu(muitiem& muiTiem, int stt){
    cout << "mui tiem thu" <<stt << endl;
    cout << "nhap ten vac xin"<< endl;
    cin >> muiTiem.tenVacXin;
    cout << "nhap ngay tiem"<< endl;
    nhapNgay(muiTiem.ngayTiem);
    cout << "nhap ma noi tiem"<< endl;
    cin >> muiTiem.maNoiTiem;
}

void nhapLuongMuiTiem(Covid19 &cv){
    for(int i=0 ; i < cv.soLuongMuiTiem; i++){
        muiTiemThu(cv.muiTiem[i], i);
    }
}

void themMotPhanTuDS(Covid19 & cv){
    int size;
    cout << "nhap CMND" << endl;
    cin >> cv.CMND;
    cout << "nhpa hoTen viet lien khong dau" << endl;
    cin >> cv.hoTen;
    cout << "nhap ngay sinh"<< endl;
    nhapNgay(cv.ngaySinh);
    cout << "nhap so luong mui tiem";
    cin >> cv.soLuongMuiTiem ;
    cv.muiTiem = new muitiem[cv.soLuongMuiTiem];
    nhapLuongMuiTiem(cv);
}

void taoMotMangDong(DanhSach &list, int size){
    list.n = size;
    list.arr = new Covid19[list.n];
    for(int i= 0; i< list.n; i++){
        themMotPhanTuDS(list.arr[i]);
    }
}


int main(){
    while(true){
        menuBT2();
    }
    return 0;
}