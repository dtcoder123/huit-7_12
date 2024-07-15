#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
//Bai 5 Tinh c/(a-b)
int TinhToan(int a,int b,int c){
	cout <<"Nhap so nguyen a:";
	cin >> a;
	cout <<"Nhap so nguyen b:";
	cin >>b;
	cout <<"Nhap so nguyen c:";
	cin >> c;
	return c/(a-b);
}
//Bai 6: Viet chuong trinh nhap ho va ten, ngay sinh, gioi tinh cua nguoi lao dong.Hay tinh thoi gian nguoi lao dong duoc nghi huu ,biet rang tuoi huu cua nam gioi
// la du 62 tuoi va nu la du 60 tuoi
void ThoiGianNghiHuu(char hovaten[30],char gioitinh[5],int ngaysinh,int thangsinh,int namsinh,int tuoi,int namnghihuu){
	cin.ignore(1);
	cout << "Nhap vao ho ten nguoi lao dong:";
	cin.getline(hovaten,30);
	cout << "Nhap vao ngay sinh:";
	cin >> ngaysinh;
	cout << "Nhap vao thang sinh:";
	cin >> thangsinh;
	cout << "Nhap vao nam sinh:";
	cin >> namsinh; 		
	cin.ignore(1);
	cout << "Nhap vao gioi tinh (Nam/Nu/Khac):";
	cin.getline(gioitinh,5);
	cin.ignore(1);
	tuoi = 2024 - namsinh;
	if (gioitinh == "Nam"){
		namnghihuu = 62 + namsinh;
	}
	if (gioitinh == "Nu"){
		namnghihuu = 60 + namsinh;
	}
	try{
		if (tuoi < 18 || tuoi >60){
			throw 101;
		}
		if (gioitinh == "Khac"){
			throw "errcode";
		}
	}
	catch (int tuoi){
		cout << "Do tuoi khong phai do tuoi lao dong"<<endl;
	}
	catch(char gioitinh[5]){
		cout << "Gioi tinh khong phai nam/nu";
	}
	cin.ignore(2);
	cout << hovaten << " gioi tinh " << gioitinh << " sinh ngay " << ngaysinh <<"/"<< thangsinh <<"/"<< namsinh << ".Hien tai(nam 2024) da " << tuoi << "tuoi. Thoi gian duoc nghi huu la thang "<< thangsinh <<"/"<< namnghihuu <<endl;
}
//-------------------------------------------------------------------------------------------
//Bai 7:
void nhapM1C_SoNguyen(int *&k, int &n) {
    n = 10;
    k = (int *)malloc(n * sizeof(int));
    if (k == NULL) {
        cout << "Khong the cap phat bo nho" << endl;
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        *(k + i) = rand() % 100;
    }
}

void xuatM1C_SoNguyen(int *k, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nPhan tu thu " << i << " co gia tri " << *(k + i) << " va dia chi o nho la " << (k + i);
        cout << "\nPhan tu thu " << i << " co gia tri " << k[i] << " va dia chi o nho la " << (k + i);
    }
}
//Bai 7a:
void timPhanTuLonNhat(int *k, int n) {
    if (n <= 0) return; 
    int solonnhat = 0;
    for (int i = 1; i < n; i++) {
        if (k[i] > k[solonnhat]) {
            solonnhat = i;
        }
    }
    cout << "\nPhan tu lon nhat la " << k[solonnhat] << " tai dia chi o nho la " << (k + solonnhat);
}
//Bai 7b:
void timPhanTuChanLe(int *k, int n) {
    if (n <= 0) return;

    int chanLonNhat = -1, leNhoNhat = -1;
    bool coChan = false, coLe = false;

    for (int i = 0; i < n; i++) {
        if (k[i] % 2 == 0) { // Ph?n t? ch?n
            if (!coChan || k[i] > k[chanLonNhat]) {
                chanLonNhat = i;
                coChan = true;
            }
        } else { // Ph?n t? l?
            if (!coLe || k[i] < k[leNhoNhat]) {
                leNhoNhat = i;
                coLe = true;
            }
        }
    }

    if (coChan) {
        cout << "\nPhan tu chan lon nhat la " << k[chanLonNhat] << " tai dia chi o nho la " << (k + chanLonNhat);
    } else {
        cout << "\nKhong co phan tu chan trong mang";
    }

    if (coLe) {
        cout << "\nPhan tu le nho nhat la " << k[leNhoNhat] << " tai dia chi o nho la " << (k + leNhoNhat);
    } else {
        cout << "\nKhong co phan tu le trong mang";
    }
}
//Cau 7c:
void xoaPhanTuKhong(int *&k, int &n) {
    int newSize = 0;
    for (int i = 0; i < n; i++) {
        if (k[i] != 0) {
            k[newSize++] = k[i];
        }
    }
    n = newSize;
    k = (int *)realloc(k, n * sizeof(int));
}
//Cau 7d:
void themPhanTuSauDauTien(int *&k, int &n, int x) {
    int *newArray = (int *)malloc((n + 1) * sizeof(int));
    if (newArray == NULL) {
        cout << "Khong the cap phat bo nho" << endl;
        exit(1);
    }
    newArray[0] = k[0];
    newArray[1] = x;
    for (int i = 1; i < n; i++) {
        newArray[i + 1] = k[i];
    }
    free(k);
    k = newArray;
    n += 1;
}
//Cau 7e:
bool isPerfectSquare(int num) {
    int sqrtNum = (int)sqrt(num);
    return (sqrtNum * sqrtNum == num);
}
int tongSoChinhPhuong(int *k, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (isPerfectSquare(*(k + i))) {
            tong += *(k + i);
        }
    }
    return tong;
}
void nhapMang(int *&k, int &n) {
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    k = new int[n];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i << ": ";
        cin >> k[i];
    }
}
void xuatMang(int *k, int n) {
    cout << "Cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << k[i] << " ";
    }
    cout << endl;
}
//Cau 7f:
void xuatSoCucDai(int *k, int n) {
    if (n <= 1) {
        cout << "Khong co so cuc dai trong mang vi mang co it hon 2 phan tu." << endl;
        return;
    }

    cout << "Cac so cuc dai trong mang la: ";
    for (int i = 1; i < n - 1; i++) {
        if (k[i] > k[i - 1] && k[i] > k[i + 1]) {
            cout << k[i] << " ";
        }
    }
    if (k[0] > k[1]) {
        cout << k[0] << " ";
    }
    if (k[n - 1] > k[n - 2]) {
        cout << k[n - 1] << " ";
    }
    cout << endl;
}

//-------------------------------------------------------------------------------------------
int main () {
	int a,b,c;
	char hovaten[30];
	char gioitinh[5];
	int ngaysinh;
	int thangsinh;
	int namsinh;
	int tuoi;
	int namnghihuu;
	cout << "Bai Lam:"<<endl;
//---------------------------------------------------
	cout << "Bai 5:"<<endl;
	int result = TinhToan(a,b,c);
	cout << result;
	cout << endl;
//---------------------------------------------------
	cout << "Bai 6:"<<endl;
	ThoiGianNghiHuu(hovaten,gioitinh,ngaysinh,thangsinh,namsinh,tuoi,namnghihuu);
//---------------------------------------------------
	srand(time(NULL));
	int *k;
    int n;
  	nhapM1C_SoNguyen(k, n);
    cout << "Mang truoc khi xoa phan tu co gia tri 0:";
    xuatM1C_SoNguyen(k, n);
    xoaPhanTuKhong(k, n);
    cout << "\nMang sau khi xoa phan tu co gia tri 0:";
    xuatM1C_SoNguyen(k, n);
    timPhanTuLonNhat(k, n);
    timPhanTuChanLe(k, n);
     int x = 2011; 
    themPhanTuSauDauTien(k, n, x);
    cout << "\nMang sau khi them phan tu " << x << " sau phan tu dau tien:";
    xuatM1C_SoNguyen(k, n);
    free(k); // Giai phong bo nho da cap phat
    cout << endl;

    nhapMang(k, n);
    xuatMang(k, n);
    int tong = tongSoChinhPhuong(k, n);
    cout << "Tong cac so chinh phuong trong mang la: " << tong << endl;
    xuatSoCucDai(k, n);
//------------------------------------------------------------------------------

	return 0;
}
