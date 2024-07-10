#include <iostream>
#include <string>
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
	cout << hovaten << " gioi tinh " << gioitinh << " sinh ngay " << ngaysinh <<"/"<< thangsinh <<"/"<< namsinh << ".Hien tai(nam 2024) da " << tuoi << "tuoi. Thoi gian duoc nghi huu la thang "<< thangsinh <<"/"<< namnghihuu <<endl;
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
//	cout << "Bai 5:"<<endl;
//	int result = TinhToan(a,b,c);
//	cout << result;
//---------------------------------------------------
	cout << "Bai 6:"<<endl;
	ThoiGianNghiHuu(hovaten,gioitinh,ngaysinh,thangsinh,namsinh,tuoi,namnghihuu);
	return 0;
}
