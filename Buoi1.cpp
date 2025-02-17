#include <iostream>
#include <cstring>
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
void ThoiGianNghiHuu(char hovaten[30], char gioitinh[5], int ngaysinh, int thangsinh, int namsinh, int tuoi, int& namnghihuu) {
    cin.ignore(1);
    cout << "Nhap vao ho ten nguoi lao dong: ";
    cin.getline(hovaten, 30);
    cout << "Nhap vao ngay sinh: ";
    cin >> ngaysinh;
    cout << "Nhap vao thang sinh: ";
    cin >> thangsinh;
    cout << "Nhap vao nam sinh: ";
    cin >> namsinh;         
    cin.ignore(1);
    cout << "Nhap vao gioi tinh (Nam/Nu/Khac): ";
    cin.getline(gioitinh, 5);

    tuoi = 2024 - namsinh;
    if (strcmp(gioitinh, "Nam") == 0) {
        namnghihuu = 62 + namsinh;
    } else if (strcmp(gioitinh, "Nu") == 0) {
        namnghihuu = 60 + namsinh;
    }

    try {
        if (tuoi < 18 || tuoi > 60) {
            throw 101;
        }
        if (strcmp(gioitinh, "Khac") == 0) {
            throw "errcode";
        }
    } catch (int e) {
        cout << "Do tuoi khong phai do tuoi lao dong" << endl;
    } catch (const char* e) {
        cout << "Gioi tinh khong phai nam/nu" << endl;
    }

    cout << hovaten << " gioi tinh " << gioitinh << " sinh ngay " << ngaysinh << "/" << thangsinh << "/" << namsinh << ". Hien tai (nam 2024) da " << tuoi << " tuoi. Thoi gian duoc nghi huu la thang " << thangsinh << "/" << namnghihuu << endl;
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
//Bai 9:
void Bai9(float *pa, float *pb) {
    float tong = *pa + *pb;
    float hieu = *pa - *pb;
    float tich = *pa * *pb;
    float thuong = *pa / *pb;

    float *pTong = &tong;
    float *pHieu = &hieu;
    float *pTich = &tich;
    float *pThuong = &thuong;

    cout << "\nTong cua a va b: " << tong;
    cout << "\nDia chi cua tong: " << static_cast<void*>(pTong);

    cout << "\nHieu cua a va b: " << hieu;
    cout << "\nDia chi cua hieu: " << static_cast<void*>(pHieu);

    cout << "\nTich cua a va b: " << tich;
    cout << "\nDia chi cua tich: " << static_cast<void*>(pTich);

    cout << "\nThuong cua a va b: " << thuong;
    cout << "\nDia chi cua thuong: " << static_cast<void*>(pThuong);
}

void Bai3() {
    float a = 5.7, b = 4.8;
    float *pa = &a;
    float *pb = &b;

    cout << "\nDia chi cua a: " << static_cast<void*>(pa);
    cout << "\nDia chi cua b: " << static_cast<void*>(pb);
    Bai9(pa, pb);
}
//-------------------------------------------------------------------------------------------
//	Cau 10:

void printChars(const char *st) {
    while (*st != '\0') {
        cout << *st << ' ';
        st++;
    }
    cout << endl;
}

void toUpperCase(char *st) {
    while (*st != '\0') {
        *st = toupper((unsigned char) *st);
        st++;
    }
}

void capitalizeWords(char *st) {
    bool newWord = true;
    while (*st != '\0') {
        if (isspace((unsigned char) *st)) {
            newWord = true;
        } else if (newWord) {
            *st = toupper((unsigned char) *st);
            newWord = false;
        }
        st++;
    }
}
//-------------------------------------------------------------------------------------------
//Cau 11:
void xuatSoCucTieu(int *k, int n) {
    if (n <= 1) {
        cout << "Khong co so cuc tieu trong mang vi mang co it hon 2 phan tu." << endl;
        return;
    }

    cout << "Cac so cuc tieu trong mang la: ";
    for (int i = 1; i < n - 1; i++) {
        if (k[i] < k[i - 1] && k[i] < k[i + 1]) {
            cout << k[i] << " ";
        }
    }
    if (k[0] < k[1]) {
        cout << k[0] << " ";
    }
    if (k[n - 1] < k[n - 2]) {
        cout << k[n - 1] << " ";
    }
    cout << endl;
}

void xoaPhanTuTaiViTri(int *&arr, int &n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    for (int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    arr = (int *)realloc(arr, n * sizeof(int));
}

void themPhanTuTaiViTri(int *&arr, int &n, int x, int k) {
    if (k < 0 || k > n) {
        cout << "Vi tri khong hop le." << endl;
        return;
    }
    arr = (int *)realloc(arr, (n + 1) * sizeof(int));
    for (int i = n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    n++;
}

void chuyenChanLe(int *arr, int n) {
    int *temp = new int[n];
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            temp[index++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
}
bool kiemTraChanLeXenKe(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 == 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

void NhapMang(int *&arr, int &n) {
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    arr = new int[n];
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << "Phan tu thu " << i << ": ";
        cin >> arr[i];
    }
}

void XuatMang(int *arr, int n) {
    cout << "Cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//------------------------------------------------------------------------------------------
//Cau 8:
struct PhanSo {
    int tu;
    int mau;
};
void nhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    do {
        cout << "Nhap mau so (mau so phai khac 0): ";
        cin >> ps.mau;
        if (ps.mau == 0) {
            cout << "Mau so phai khac 0. Vui long nhap lai.\n";
        }
    } while (ps.mau == 0);
}
void xuatPhanSo(const PhanSo &ps) {
    cout << ps.tu << "/" << ps.mau << endl;
}
void nhapMangPhanSo(PhanSo *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        nhapPhanSo(arr[i]);
    }
}
void xuatMangPhanSo(const PhanSo *arr, int n) {
    for (int i = 0; i < n; ++i) {
        xuatPhanSo(arr[i]);
    }
}
void xuatPhanSoMauLonHonTu(const PhanSo *arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i].mau > arr[i].tu) {
            xuatPhanSo(arr[i]);
        }
    }
}
int demPhanSoTuMauChan(const PhanSo *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i].tu % 2 == 0 && arr[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void rutGonPhanSo(PhanSo &ps) {
    int ucln = UCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
}
PhanSo tinhTichPhanSo(const PhanSo *arr, int n) {
    PhanSo tich = {1, 1};
    for (int i = 0; i < n; ++i) {
        tich.tu *= arr[i].tu;
        tich.mau *= arr[i].mau;
    }
    rutGonPhanSo(tich);
    return tich;
}
PhanSo timPhanSoLonNhat(const PhanSo *arr, int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (static_cast<double>(arr[i].tu) / arr[i].mau > static_cast<double>(max.tu) / max.mau) {
            max = arr[i];
        }
    }
    return max;
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
//	cout << endl;
//---------------------------------------------------
//	cout << "Bai 6:"<<endl;
//	ThoiGianNghiHuu(hovaten,gioitinh,ngaysinh,thangsinh,namsinh,tuoi,namnghihuu);
//---------------------------------------------------
//	cout << "Cau 7":<<endl;
//	srand(time(NULL));
//	int *k;
//    int n;
//  	nhapM1C_SoNguyen(k, n);
//    cout << "Mang truoc khi xoa phan tu co gia tri 0:";
//    xuatM1C_SoNguyen(k, n);
//    xoaPhanTuKhong(k, n);
//    cout << "\nMang sau khi xoa phan tu co gia tri 0:";
//    xuatM1C_SoNguyen(k, n);
//    timPhanTuLonNhat(k, n);
//    timPhanTuChanLe(k, n);
//     int x = 2011; 
//    themPhanTuSauDauTien(k, n, x);
//    cout << "\nMang sau khi them phan tu " << x << " sau phan tu dau tien:";
//    xuatM1C_SoNguyen(k, n);
//    free(k); // Giai phong bo nho da cap phat
//    cout << endl;
//
//    nhapMang(k, n);
//    xuatMang(k, n);
//    int tong = tongSoChinhPhuong(k, n);
//    cout << "Tong cac so chinh phuong trong mang la: " << tong << endl;
//    xuatSoCucDai(k, n);
//------------------------------------------------------------------------------
//	cout << "Cau 9"<<endl;
//	Bai3();
//------------------------------------------------------------------------------
//	cout <<"Cau 10"<<endl;
//	char st[100];
//    cout << "nhap vao chuoi: ";
//    cin.getline(st, sizeof(st));
//    cout << "cac ky tu trong chuoi la: ";
//    printChars(st);
//    toUpperCase(st);
//    cout << "chuoi sau khi chuyen sang chu hoa: " << st << endl;
//    strcpy(st, " ");
//	capitalizeWords(st);
//	 int *arr, n;
//    NhapMang(arr, n);
//
//    XuatMang(arr, n);
//
//    xuatSoCucTieu(arr, n);
//
//    int viTriXoa;
//    cout << "Nhap vi tri can xoa: ";
//    cin >> viTriXoa;
//    xoaPhanTuTaiViTri(arr, n, viTriXoa);
//    XuatMang(arr, n);
//
//    int x, viTriThem;
//    cout << "Nhap gia tri can them: ";
//    cin >> x;
//    cout << "Nhap vi tri can them: ";
//    cin >> viTriThem;
//    themPhanTuTaiViTri(arr, n, x, viTriThem);
//    XuatMang(arr, n);
//    chuyenChanLe(arr, n);
//    cout << "Mang sau khi chuyen so chan len dau va so le xuong cuoi: ";
//    XuatMang(arr, n);
//
//    if (kiemTraChanLeXenKe(arr, n)) {
//        cout << "Mang co chua chan le xen ke." << endl;
//    } else {
//        cout << "Mang khong chua chan le xen ke." << endl;
//    }
//
//    delete[] arr;
 	int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    PhanSo *arr = new PhanSo[n];
    nhapMangPhanSo(arr, n);

    cout << "Mang phan so vua nhap:\n";
    xuatMangPhanSo(arr, n);

    cout << "Cac phan so co mau so lon hon tu so:\n";
    xuatPhanSoMauLonHonTu(arr, n);

    cout << "So phan so co tu va mau so chan: " << demPhanSoTuMauChan(arr, n) << endl;

    for (int i = 0; i < n; ++i) {
        rutGonPhanSo(arr[i]);
    }
    cout << "Mang phan so sau khi rut gon:\n";
    xuatMangPhanSo(arr, n);

    PhanSo tich = tinhTichPhanSo(arr, n);
    cout << "Tich cac phan so trong mang: ";
    xuatPhanSo(tich);

    PhanSo max = timPhanSoLonNhat(arr, n);
    cout << "Phan so lon nhat trong mang: ";
    xuatPhanSo(max);

    delete[] arr;
	return 0;
}
