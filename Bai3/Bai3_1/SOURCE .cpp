#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// khai bao cac dinh nghia
struct ngaythangnam {
    string ngay;
    string thang;
    string nam;
};
typedef struct ngaythangnam date;

struct TTmuitiem {
    int stt;
    string tenVaccine;
    date ngayTiem;
    string maNoiTiem;
};

struct Covid19 {
    string CMND;
    string hoTen;
    date ngaySinh;
    TTmuitiem* muiTiem;
    int soLuongMuiTiem;
};

struct danhsach {
    Covid19* arr;
    int n; //so luong phan tu 
};
typedef struct danhsach DanhSach;

//Fuction//

int chonMenu();
void menuBT2(DanhSach& list);
void nhap(DanhSach& list);
Covid19 nhapThongTinNguoi(Covid19& cv);
void xoaMotPhanTuKhoiDS();
bool suaThongTinMotPhanTu(DanhSach& list, int pos);
void sapXepDS(DanhSach& list);
void XuatDS(DanhSach& list);
void nguoiChuaTiemKMui();


int chonMenu() {
    DanhSach list;
    int n;
    string choose;
    cout << "\n\nMoi chon menu: ";
    cin >> n;
    if (n > 0 && n <= 8) {
        return n;
    }
    else {
        cout << "Ban nhap khong hop le , ban co muon nhap lai khong ? (yes/no)";
        cin >> choose;
        {
            if (choose == "yes" || choose == "Yes")
                menuBT2(list);
            else
            {
                cout << "out";
                exit(0);
            }

        }
    }
}

void menuBT2(DanhSach& list) {
    bool k;
    int pos;
    cout << "_________________________Menu________________________" << endl;
    cout << "Hay chon mot chuc nang" << endl;
    cout << "1. Tao mang dong va nhap danh sach vao mang " << endl;
    cout << "2. Them mot phan tu vao danh sach " << endl;
    cout << "3. Xoa mot phan tu khoi danh sach" << endl;
    cout << "4. Sua thong tin mot phan tu" << endl;
    cout << "5. Sap xep danh sach theo so CMND" << endl;
    cout << "6. Xuat danh sach" << endl;
    cout << "7. Xac dinh nhung nguoi chua tiem du K mui" << endl;
    cout << "8. Ket thuc chuong trinh" << endl;
    int n;
    n = chonMenu();
    switch (n) {
    case 1:
        cout << "nhap so luong nguoi can lap danh sach " << endl;
        cin >> list.n;
        nhap(list);
        break;
    case 2:
        break;
    case 3:break;
    case 4:
    {
        if (list.n > 0)
        {
            cout << "\nNhap vi tri muon sua (bat dau tu 0)";
            cin >> pos;
            k = suaThongTinMotPhanTu(list, pos);
            if (k == false)
                cout << "\nVi tri khong hop le .";
            else
            {
                cout << "\n Danh sach sau khi sua la ";
                XuatDS(list);
            }
        }
        else cout << "\n Ban phai nhap danh sach sinh vien truoc";
    }
    break;
    case 5:
        if (list.n > 0)
        {
            cout << "\n Mang sau khi sap xep la ";
            sapXepDS(list);
            XuatDS(list);
        }
        else cout << "\n Ban phai nhap danh sach sinh vien truoc \n ";
        break;
    case 6:
    {
        if (list.n > 0)
        {
            XuatDS(list);
        }
        else cout << "\n Ban phai nhap danh sach sinh vien truoc";
    }
    break;
    case 7:break;
    case 8: {
        cout << "out";
        delete[]list.arr;
        exit(1);
        break;
    }
    }
}

void nhapNgay(date& Ngay) {
    cout << "ngay \n";
    cin >> Ngay.ngay;
    cout << "thang\n ";
    cin >> Ngay.thang;
    cout << "nam\n";
    cin >> Ngay.nam;
}

void nhapThongTinMuiTiem(Covid19& cv) {
    for (int i = 0; i < cv.soLuongMuiTiem; i++) {
        cout << "mui tiem thu " << i + 1 << "\n\n";
        cout << "nhap ten vac xin " << endl;
        cin >> cv.muiTiem[i].tenVaccine;
        cout << "nhap ngay tiem " << endl;
        nhapNgay(cv.muiTiem[i].ngayTiem);
        cout << "nhap ma noi tiem " << endl;
        cin >> cv.muiTiem[i].maNoiTiem;
    }
}

Covid19 nhapThongTinNguoi(Covid19& cv) {
    cout << "\n nhap CMND " << endl;
    cin >> cv.CMND;
    cin.ignore(); // for xoa bo nho dem , tranh bi troi lenh 
    cout << "\n nhap ho ten " << endl;
    getline(cin, cv.hoTen);
    cout << "\n nhap ngay thang nam sinh " << endl;
    nhapNgay(cv.ngaySinh);
    cout << "\n nhap so luong mui tiem ";
    cin >> cv.soLuongMuiTiem;
    cv.muiTiem = new TTmuitiem[cv.soLuongMuiTiem];
    nhapThongTinMuiTiem(cv);
    return cv;
}

void nhap(DanhSach& list)
{
    list.arr = new Covid19[list.n];
    for (int i = 0; i < list.n; i++) {
        cout << "\n Nhap thong tin nguoi thu " << i + 1;
        nhapThongTinNguoi(list.arr[i]);
    }
}
//Sua thong tin 1 nguoi trong danh sach 
bool suaThongTinMotPhanTu(DanhSach& list, int pos) {
    Covid19 cv;
    if (pos < 0 || pos >= list.n)
        return false;
    else
    {
        list.arr[pos] = nhapThongTinNguoi(cv);
    }
}
//xuat 1 phan tu 
void xuat1phantu(Covid19& cv)
{
    cout << "\n CMND :" << cv.CMND << endl;
    cout << "\n Ho va ten : " << cv.hoTen << endl;;
    cout << "\n Ngay sinh " << cv.ngaySinh.ngay << "/" << cv.ngaySinh.thang << "/" << cv.ngaySinh.nam << endl;;
    cout << "\n So luong mui tiem : " << cv.soLuongMuiTiem << endl;;
    for (int i = 0; i < cv.soLuongMuiTiem; i++) {
        cout << "\n Mui tiem thu " << i + 1 << endl;
        cout << "\n Ten vaccin " << cv.muiTiem[i].tenVaccine << endl;
        cout << "\n Ngay tiem " << cv.muiTiem[i].ngayTiem.ngay << "/" << cv.muiTiem[i].ngayTiem.thang << "/" << cv.muiTiem[i].ngayTiem.nam << endl;
        cout << "\n Ma noi tiem " << cv.muiTiem[i].maNoiTiem << endl;
    }
}
//xuat phan tu
void XuatDS(DanhSach& list) {
    for (int i = 0; i < list.n; i++)
    {
        cout << "\n\n\t\t\t Thong tin nguoi thu " << i + 1 << endl;
        xuat1phantu(list.arr[i]);
    }
}
void swap(int& a, int& b)
{
    int tam = a;
    a = b;
    b = tam;
}
//Sap xep ds theo cmnd//cccd tang dan
void sapXepDS(DanhSach& list)
{
    for (int i = 0; i < list.n - 1; i++)
        for (int j = i + 1; j < list.n; j++)
        {
            if (list.arr[i].CMND > list.arr[j].CMND)
            {
                swap(list.arr[i], list.arr[j]);
            }
        }
}
int main() {
    DanhSach list;
    while (true) {
        menuBT2(list);
    }
    return 0;
}