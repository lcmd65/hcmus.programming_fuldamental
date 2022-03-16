/*
  21280102_DOAN THI MAN NHI
  21280100_NGUYEN THI BICH NGOC
  21280064_LE CHON MINH DAT
  VISUAL STUDIO CODE 
  WINDOW
 */

#include <iostream>
#include <string>
#include <fstream>

 using namespace std;

// khai bao cac dinh nghia
struct date {
    int ngay;
    int thang;
    int nam;
};

struct F0 {
    string ma;
    string ten;
};

struct phantu {
    date ngay;
    int soca;
    F0 *fo;
};

struct danhsach {
    phantu* pt;
    int n = 0; //so luong phan tu 
};
typedef struct danhsach DanhSach;

int chonMenu();
void menu(DanhSach &list);
void nhapNgay(date& Ngay) ;
void nhapThongTinF0(phantu &pt);
phantu nhapThongTinMotPhanTu(phantu &pt) ;
void nhap(DanhSach& list);
void sapxep(DanhSach& list);
void themMotPhanTuVaoDS(DanhSach& list, int vitrithem);
void xuatThongTinMotPhanTu(phantu& pt);
void xuatDS(DanhSach& list); 
void luuDSVaoFile(DanhSach& list);
void napDSvaoFile(DanhSach& list);

/*----------FUNCTION----------*/

int chonMenu() {
    DanhSach list;
    int n;
    string choose;
    cout << "\n\nMoi chon menu (1-7): ";
    cin >> n;
    if (n > 0 && n <= 7) {
        return n;
    }
    else {
        cout << "Ban nhap khong hop le, ban co muon nhap lai khong? (yes/no): ";
        cin >> choose;
        {
            if (choose == "yes" || choose == "Yes" || choose == "YES")
                menu(list);
            else
            {
                cout << "out";
                exit(0);
            }

        }
    }
}

void menu(DanhSach &list) {
    cout << "_________________________Menu________________________" << endl;
    cout << "Hay chon mot chuc nang:" << endl;
    cout << "1. Tao mang dong va nhap danh sach vao mang" << endl;
    cout << "2. Sap xep danh sach theo thu tu so ca F0 giam dan" << endl;
    cout << "3. Them mot phan tu vao danh sach " << endl;
    cout << "4. Xuat danh sach" << endl;
    cout << "5. Luu danh sach vao file" << endl;
    cout << "6. Nap danh sach tu file" << endl;
    cout << "7. Ket thuc chuong trinh" << endl;
    int v;  
    v = chonMenu();   
    switch (v) {
      case 1:
        do {
        cout << "Nhap so luong phan tu: ";
        cin >> list.n;
        if (list.n < 1)
            cout << "Khong hop le. Vui long nhap lai.";
        }while(list.n < 1);         
        nhap(list);
        break;
      case 2:
          if (list.n>0){
              cout << "Mang sau khi sap xep la : ";
              sapxep(list);
              xuatDS(list);
          }
          else
            cout << "\n Ban phai nhap danh sach truoc.\n";
          break;
      case 3:
          if (list.n>0){
                
          }
          else
            cout << "\n Ban phai nhap danh sach truoc.\n";
          break;
      case 4: 
          if (list.n>0){
              
          }
          else 
              cout << "\n Ban phai nhap danh sach truoc.\n";
          break;
      case 5:
          if (list.n > 0) {
              luuDSVaoFile(list);
          }
          else
              cout << "\n Ban phai nhap danh sach truoc.\n";
          break;
      case 6:   
          //if (list.n>0){
              napDSvaoFile(list);
          //}
          //else 
             // cout << "\n Ban phai nhap danh sach truoc.\n";
          break;
      
      case 7: 
          cout << "out";
          delete[]list.pt;
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

void nhapThongTinF0(phantu &pt) {
    for (int i = 0; i < pt.soca; i++) {
        cout << "\n---Benh nhan thu " << i + 1 << "---\n";
        cout << "\n\tMa SV/CB: "; 
        cin >> pt.fo[i].ma;
        cin.ignore(); // for xoa bo nho dem , tranh bi troi lenh
        cout << "\n\tTen SV/CB: ";
        getline(cin, pt.fo[i].ten);
    }
}

phantu nhapThongTinMotPhanTu(phantu &pt) {
    cout << "\nNgay ghi nhan: \n";
    nhapNgay(pt.ngay);
    cout << "\nSo ca F0: ";
    cin >> pt.soca;
    pt.fo = new F0[pt.soca];
    nhapThongTinF0(pt);
    return pt;
}

void nhap(DanhSach& list) 
{
    list.pt = new phantu[list.n];
    for (int i = 0; i < list.n; i++) {
        cout << "\n-----Nhap thong tin phan tu thu " << i + 1 << "-----\n";
        nhapThongTinMotPhanTu(list.pt[i]);
    }
}

void themMotPhanTuVaoDS(DanhSach& list, int vitrithem) {
    // toa mot mang dong tam thoi co kich thuoc = n+1
    phantu* arr = new phantu[list.n + 1];
    for (int i = 0; i < list.n; i++) {
        if (i < vitrithem) {
            arr[i] = list.pt[i];
        }
        else {
            arr[i + 1] = list.pt[i];
        }
    }
    delete[] list.pt;
    // tao lai mang arr co kich thuoc n+1
    list.pt = new phantu[list.n + 1];
    list.n += 1;
    for (int i = 0; i < list.n; i++) {
        list.pt[i] = arr[i];
    }
    delete[]arr;
    cout << "nhap thong tin benh nhan them vao DS" << endl;
    nhapThongTinMotPhanTu(list.pt[vitrithem]);
}

void xuatThongTinMotPhanTu(phantu& pt) {
    cout << "\t\t\tngay: " << pt.ngay.ngay << "/" << pt.ngay.thang << "/" << pt.ngay.nam << "\n";
    cout << "So ca covid: " << pt.soca << "\n";
    for (int i = 0; i < pt.soca; i++) {
        cout << "\tCa thu " << i + 1 << "\n";
        cout << "Ma:\t" << pt.fo[i].ma << "\n";
        cout << "Ten:\t" << pt.fo[i].ten << "\n";
    }
}
void xuatDS(DanhSach& list)
{
    for (int i = 0; i < list.n; i++) 
    {
        cout << "\n\n\t\t\t ---Thong tin " << i + 1 << "---\n";
        xuatThongTinMotPhanTu(list.pt[i]);
    }
}

void swap(int& a, int & b) //Ham hoan vi 
{
    int tam = a;
    a = b;
    b = tam;
}

//sap xep danh sach theo thu tu so ca F0 giam dan
void sapxep (DanhSach &list ) {
    for (int i = 0; i < list.n-1; i++)
        for (int j = i + 1; j < list.n; j++)
        {
            if (list.pt[j].soca > list.pt[i].soca)
                swap(list.pt[i], list.pt[j]);
        }
}


//LUU DS VAO FILE 
void luuDSVaoFile(DanhSach& list)
{
    ofstream FileOut; //khai bao ra 1 bien FileOut de ghi danh sach vao file 
    FileOut.open("D:\\OUT.txt", ios::out); // mo file o che do ghi ds vao file 
    cout << "\n Luu danh sach vao file !! ";
    for (int i = 0; i < list.n; i++)
    {
        FileOut << "\n Ngay ghi nhan : " << list.pt[i].ngay.ngay << " / " << list.pt[i].ngay.thang << " / " << list.pt[i].ngay.nam << endl;
        FileOut << "So ca : " << list.pt[i].soca << endl;
        if (list.pt[i].soca > 0) {
            for (int j = 0; j < list.pt[i].soca; j++)
            {

                FileOut << "--Thong tin nguoi thu " << j + 1 << "--" << endl;
                FileOut << "Ma SV/CB : " << list.pt[i].fo[j].ma << endl;
                FileOut << "Ten SV/CB : " << list.pt[i].fo[j].ten << endl;

            }
        }

    }
    FileOut.close(); //dong cac file da mo 
}


void napDSvaoFile(DanhSach& list)
{

    ifstream FileIn;
    FileIn.open("D:\\OUT.txt", ios::in);

    if (FileIn.fail() == true)
    {
        cout << "\nFile cua ban khong ton tai";
        system("pause");
        exit(0) ;
    }

    for (int i = 0; i < list.n; i++)
    {
        
        FileIn >> list.pt[i].ngay.ngay;
        FileIn >> list.pt[i].ngay.thang;
        FileIn >> list.pt[i].ngay.nam;
        cout << "Ngay ghi nhan : "<< list.pt[i].ngay.ngay << " / " << list.pt[i].ngay.thang << " / " << list.pt[i].ngay.nam << endl; 
        FileIn >> list.pt[i].soca;
        cout<< "So ca : " << list.pt[i].soca << endl;
        if (list.pt[i].soca > 0) {
            for (int j = 0; j < list.pt[i].soca; j++)
            {
                
                cout << "--Thong tin nguoi thu " << j + 1 << "--" << endl;
                FileIn >> list.pt[i].fo[j].ma;
                cout << "Ma SV/CB : " << list.pt[i].fo[j].ma << endl;
                FileIn >> list.pt[i].fo[j].ten;
                cout << "Ten SV/CB : " << list.pt[i].fo[j].ten << endl;

            }
        }

    }

    FileIn.close(); // đóng file lại sau khi xử lí
}


int main() {
    DanhSach list;
    while (true) {
        menu(list);
    }
    return 0;
}