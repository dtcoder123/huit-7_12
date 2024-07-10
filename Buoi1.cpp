#include <iostream>
using namespace std;
//Bai 5
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

int main () {
	int a,b,c;
	cout << "Bai Lam:"<<endl;
//---------------------------------------------------
	cout << "Bai 5:"<<endl;
	int result = TinhToan(a,b,c);
	cout << result;
//---------------------------------------------------
	
	return 0;
}
