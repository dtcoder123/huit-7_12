#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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
    
    free(k); // Giai phong bo nho da cap phat
    
	return 0;
}
