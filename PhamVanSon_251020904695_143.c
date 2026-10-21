#include <stdio.h>
#include <string.h>
typedef struct {
    char tenHang[21];
    char maHang[7];
    double donGia;
    int soLuong;
} HangHoa;
int nhapDanhSach(HangHoa ds[]){
    int n = 0;
    while (1) {
        char ten[100];
        printf("\n--- Nhap mat hang thu %d ---\n", n + 1);
        printf("Ten hang (Nhap *** de dung): ");
        scanf(" %[^\n]", ten);
        if (strcmp(ten, "***") == 0) {
            break;
        }

        strncpy(ds[n].tenHang, ten, 20);
        ds[n].tenHang[20] = '\0';

        printf("Ma hang (6 ky tu): ");
        scanf("%s", ds[n].maHang);

        printf("Don gia: ");
        scanf("%lf", &ds[n].donGia);

        printf("So luong ban: ");
        scanf("%d", &ds[n].soLuong);

        n++;
    }
    return n;
}


void sapXepTheoMaHang(HangHoa ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ds[i].maHang, ds[j].maHang) > 0) {
                HangHoa temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void inDanhSachThoaDieuKien(HangHoa ds[], int n) {
    double tongCong = 0;
    int stt = 1;

    printf("\n+-----+---------+----------------------+------------+----------+------------+\n");
    printf("| STT | Ma hang | Ten hang hoa         | Don gia    | So luong | Tong tien  |\n");
    printf("+-----+---------+----------------------+------------+----------+------------+\n");

    for (int i = 0; i < n; i++) {
        double tongTien = ds[i].donGia * ds[i].soLuong;
        if (tongTien > 500000) {
            printf("| %02d  | %-7s | %-20s | %-10.0f | %-8d | %-10.0f |\n",
                   stt++, ds[i].maHang, ds[i].tenHang, ds[i].donGia, ds[i].soLuong, tongTien);
            tongCong += tongTien;
        }
    }

    printf("+-----+---------+----------------------+------------+----------+------------+\n");
    printf("                                              TONG CONG: %.0f VNĐ\n", tongCong);
}

int main() {
    HangHoa ds[100];
    int n = 0;
    n = nhapDanhSach(ds);

    if (n == 0) {
        printf("Chua nhap mat hang nao.\n");
        return 0;
    }
    sapXepTheoMaHang(ds, n);

    inDanhSachThoaDieuKien(ds, n);

    return 0;
}
