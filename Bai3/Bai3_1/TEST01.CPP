/*
  21280102_DOAN THI MAN NHI
  21280100_NGUYEN THI BICH NGOC
  21280064_LE CHON MINH DAT
  VISUAL STUDIO CODE 
  WINDOW
 */

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

// khai bao cac dinh nghia
struct ngaythangnam {
    int ngay;
    int thang;
    int nam;
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
    int n = 0; //so luong phan tu 
};
typedef struct danhsach DanhSach;

//Fuction//

int chonMenu();
void menuBT2(DanhSach &list);
void nhap(DanhSach& list);
Covid19 nhapThongTinNguoi(Covid19& cv);
void themMotPhanTuVaoDS(DanhSach&list, int vitrithem);
void xoaMotPhanTuKhoiDS(DanhSach &list, int vitrixoa);
bool suaThongTinMotPhanTu(DanhSach& list,int pos);
void sapXepDS(DanhSach &list);
void XuatDS(DanhSach &list);
bool kiemtraSoMuiTiem(int k, Covid19 cv);
void kiemtra(DanhSach list, int &o, int k);
void xuatThongTinCoBan(Covid19 &cv);

int chonMenu() {
    DanhSach list;
    int n;
    string choose;
    cout << "\n\nMoi chon menu (1-8): ";
    cin >> n;
    if (n > 0 && n <= 8) {
        return n;
    }
    else {
        cout << "Ban nhap khong hop le, ban co muon nhap lai khong? (yes/no): ";
        cin >> choose;
        {
            if (choose == "yes" || choose == "Yes" || choose == "YES")
                menuBT2(list);
            else
            {
                cout << "out";
                exit(0);
            }

        }
    }
}

void menuBT2(DanhSach &list) {
    bool k;
    int pos;
    cout << "_________________________Menu________________________" << endl;
    cout << "Hay chon mot chuc nang:" << endl;
    cout << "1. Tao mang dong va nhap danh sach vao mang " << endl;
    cout << "2. Them mot phan tu vao danh sach " << endl;
    cout << "3. Xoa mot phan tu khoi danh sach" << endl;
    cout << "4. Sua thong tin mot phan tu" << endl;
    cout << "5. Sap xep danh sach theo so CMND (tang dan)" << endl;
    cout << "6. Xuat danh sach" << endl;
    cout << "7. Xac dinh nhung nguoi chua tiem du K mui" << endl;
    cout << "8. Ket thuc chuong trinh" << endl;
    int v;  
    v = chonMenu();   
    switch (v) {
      case 1:
        do {
            cout << "Nhap so luong nguoi can lap danh sach: ";
            cin >> list.n;
            if (list.n < 1)
                cout << "Khong hop le. Vui long nhap lai.";
        }while(list.n < 1);         
            nhap(list);
            break;
      case 2:
          int vitrithem;
          if (list.n>0){
              do {
                cout << "\nNhap vi tri can them danh sach: ";
                cin >> vitrithem;
              }while(vitrithem < 0 || vitrithem >= list.n);    
              themMotPhanTuVaoDS(list, vitrithem);
          }
          else
            cout << "\n Ban phai nhap danh sach sinh vien truoc.\n";
          break;
      case 3:
          int vitrixoa;
          if (list.n>0){
                do {
                    cout << "\nNhap vi tri can xoa: ";
                    cin >> vitrixoa;
                }while(vitrithem < 0 || vitrithem >= list.n);           
                xoaMotPhanTuKhoiDS(list, vitrixoa);
          }
          else
            cout << "\n Ban phai nhap danh sach sinh vien truoc.\n";
          break;
      case 4: 
          if (list.n>0)
          {
              cout << "\nNhap vi tri muon sua (bat dau tu 0): ";
              cin >> pos;
              k = suaThongTinMotPhanTu(list, pos);
              if (k == false)
                  cout << "\nVi tri khong hop le.\n";
              else
              {
                  cout << "\n Danh sach sau khi sua la: ";
                  XuatDS(list);
              }
          }
          else cout << "\n Ban phai nhap danh sach sinh vien truoc.\n";
          break;
      case 5:
          if (list.n > 0)
          {
              cout << "\nMang sau khi sap xep la: ";
              sapXepDS(list);
              XuatDS(list);
          }
          else cout << "\nBan phai nhap danh sach sinh vien truoc.\n ";
          break;
      case 6:   
          if (list.n > 0)
          {
              XuatDS(list);
          }
          else cout << "\nBan phai nhap danh sach sinh vien truoc.\n";  
          break;
      case 7:
            int k, o;
            o = 0;
            if (list.n > 0){
                do {
                    cout << "\nNhap so luong mui tiem ban muon kiem tra: ";
                    cin >> k;
                    if (k < 1)
                        cout << "\nBan nhap khong hop le. Vui long nhap lai.";
                }while(k < 1);
                cout << "-----Danh sach nhung nguoi chua tiem du " << k << " mui-----\n";
                kiemtra(list, o, k);
                if (o == 0)
                    cout << "\nTat ca da tiem du " << k << " mui.";
            }
            else
                cout << "\nBan phai nhap danh sach sinh vien truoc.\n";  
            break;   

      case 8: 
          cout << "out";
          delete[]list.arr;
          exit(1);
          break;
    }
}

void nhapNgay(date& Ngay) {
    cout << "\tNgay: ";
    cin >> Ngay.ngay;
    cout << "\tThang: ";
    cin >> Ngay.thang;
    cout << "\tNam: ";
    cin >> Ngay.nam;
}

void nhapThongTinMuiTiem(Covid19& cv) {
    for (int i = 0; i < cv.soLuongMuiTiem; i++) {
        cout << "---Mui tiem thu " << i + 1 << "---\n\n";
        cout << "\tTen vac xin: " << endl <<"\t";
        cin >> cv.muiTiem[i].tenVaccine;
        cout << "\tNgay tiem: " << endl;
        nhapNgay(cv.muiTiem[i].ngayTiem);
        cout << "\tMa noi tiem: " << endl<<"\t";
        cin >>cv.muiTiem[i].maNoiTiem;
    }
}

Covid19 nhapThongTinNguoi(Covid19& cv) {
    cout << "\nCMND: " << endl << "\t";
    cin >> cv.CMND;
    cin.ignore(); // for xoa bo nho dem , tranh bi troi lenh
    cout << "\nHo ten: "<< endl << "\t";
    getline(cin, cv.hoTen);
    cout << "\nNgay thang nam sinh: "<< endl;
    nhapNgay(cv.ngaySinh);
    cout << "\nSo luong mui tiem: "<< endl << "\t";
    cin >> cv.soLuongMuiTiem;
    cv.muiTiem = new TTmuitiem[cv.soLuongMuiTiem];
    nhapThongTinMuiTiem(cv);
    return cv;
}

void nhap(DanhSach& list) 
{
    list.arr = new Covid19[list.n];
    for (int i = 0; i < list.n; i++) {
        cout << "\n-----Nhap thong tin nguoi thu " << i + 1 << "-----\n";
        nhapThongTinNguoi(list.arr[i]);
    }
}

//Them mot phan tu vao danh sach
void themMotPhanTuVaoDS(DanhSach&list, int vitrithem){
    Covid19* ar = new Covid19[list.n +1];
    for (int i = 0; i < vitrithem; i++) {
        ar[i] = list.arr[i];
    }
    for (int i = vitrithem; i < list.n; i++) {
        ar[i+1] = list.arr[i];
    }
    delete[] list.arr;
    list.arr = new Covid19[list.n + 1];
    list.n += 1;
    for (int i = 0; i < list.n; i++) {
        list.arr[i] = ar[i];
    }
    delete[]ar;
    cout << "---Nhap thong tin can them vao DS---" << endl; 
    nhapThongTinNguoi(list.arr[vitrithem]);
}

//Xoa mot phan tu khoi danh sach
void xoaMotPhanTuKhoiDS(DanhSach&list, int vitrixoa){
    Covid19* ar = new Covid19[list.n -1];
    for (int i = 0; i < vitrixoa; i++) {
        ar[i] = list.arr[i];
    }
    for (int i = vitrixoa; i < list.n-1; i++) {
        ar[i] = list.arr[i+1];
    }
    delete[] list.arr;
    list.arr = new Covid19[list.n - 1];
    list.n -= 1;
    for (int i = 0; i < list.n; i++) {
        list.arr[i] = ar[i];
    }
    delete[]ar;
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
void xuat1phantu(Covid19 &cv)
{
    cout << "\n CMND:" << cv.CMND << endl;
    cout << "\n Ho va ten: " << cv.hoTen << endl;;
    cout << "\n Ngay sinh: " << cv.ngaySinh.ngay<<"/"<<cv.ngaySinh.thang<<"/"<<cv.ngaySinh.nam << endl;;
    cout << "\n So luong mui tiem: "<< cv.soLuongMuiTiem << endl;;
    for(int i = 0; i < cv.soLuongMuiTiem; i++) {
        cout << "\n ---Mui tiem thu " << i + 1 << "---" << endl;
        cout << "\n Ten vaccin: " << cv.muiTiem[i].tenVaccine<< endl;
        cout << "\n Ngay tiem: " << cv.muiTiem[i].ngayTiem.ngay << "/" << cv.muiTiem[i].ngayTiem.thang << "/" << cv.muiTiem[i].ngayTiem.nam << endl;
        cout << "\n Ma noi tiem: " << cv.muiTiem[i].maNoiTiem<< endl;
    }
}
//xuat phan tu
void XuatDS(DanhSach &list) {
    for (int i = 0; i < list.n; i++)
    {
        cout << "\n\n\t\t\t ---Thong tin nguoi thu " << i + 1 << "---\n";
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
void sapXepDS(DanhSach &list)
{
    for (int i = 0; i < list.n-1;i++)
        for (int j = i + 1; j < list.n; j++)
        {
            if (list.arr[i].CMND > list.arr[j].CMND)
            {
                swap(list.arr[i],list.arr[j]);
            }
        }
}

//Kiem tra nhung nguoi chua tiem du K mui
bool kiemtraSoMuiTiem(int k, Covid19 cv) {
    if (cv.soLuongMuiTiem < k){
        return true;
    }
    else    
        return false;
}
void kiemtra(DanhSach list, int &o, int k){
    for (int i = 0; i < list.n; i++){
        if (kiemtraSoMuiTiem(k, list.arr[i]) == true){
            cout << "\n\t\t---Nguoi thu " << o + 1 << "---";
            xuatThongTinCoBan(list.arr[i]);
            o++;

        }   
    }
}
void xuatThongTinCoBan(Covid19 &cv){
    cout << "\n CMND:" << cv.CMND << endl;
    cout << "\n Ho va ten: " << cv.hoTen << endl;;
    cout << "\n Ngay sinh: " << cv.ngaySinh.ngay<<"/"<<cv.ngaySinh.thang<<"/"<<cv.ngaySinh.nam << endl;;
    cout << "\n So luong mui tiem: "<< cv.soLuongMuiTiem << endl;;
}

int main() {
    DanhSach list;
    while (true) {
        menuBT2(list);
    }
    return 0;
}
