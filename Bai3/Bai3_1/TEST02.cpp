/*
  21280102_DOAN THI MAN NHI
  21280100_NGUYEN THI BICH NGOC
  21280064_LE CHON MINH DAT
  VISUAL STUDIO CODE 
  WINDOW
 */

 #include <iostream>
 #include <string>

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
        cout << "Nhap so luong nguoi can lap danh sach: ";
        cin >> list.n;
        if (list.n < 1)
            cout << "Khong hop le. Vui long nhap lai.";
        }while(list.n < 1);         
        nhap(list);
        break;
      case 2:
          if (list.n>0){
              
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
          if (list.n>0){
              
          }
          else 
              cout << "\n Ban phai nhap danh sach truoc.\n";
          break;
      case 6:   
          if (list.n>0){
              
          }
          else 
              cout << "\n Ban phai nhap danh sach truoc.\n";
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
    cout << "\nNgay ghi nhan:\n";
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

int main() {
    DanhSach list;
    while (true) {
        menu(list);
    }
    return 0;
}