
#include<stdio.h>
typedef struct{
    char tenhs[21];
    int mshs;
    float tk;
}HocSinh;
void indanhsach(HocSinh ds[],int n){
    printf("+-----+---------+--------------+-----------+\n");
    printf("|%-5s|%-9s|%-17s|%-9s|\n","STT","Ma HS","Ho Va Ten","Diem");
    printf("+-----+---------+--------------+-----------+\n");
    for(int i = 0 ;i<n;i++){
        printf("|%-5d|%-9d|%-17s|%-9.1f|\n",i+1,ds[i].mshs,ds[i].tenhs,ds[i].tk);
    }
    printf("+-----+---------+--------------+-----------+\n");
}
int main(){
    HocSinh ds[10];
    int n;
    do{
        printf("Nhap danh sach hoc sinh(n<=10):\n");
        scanf("%d",&n);
    }while(n<= 0 || n > 10);
    for(int i = 0;i<n;i++){
        printf("----nhap thong tin hoc sinh thu %d----\n",i+1);
        printf("Nhap ma so hoc sinh: ");
        scanf("%d",&ds[i].mshs);
        while(getchar() != '\n');
        printf("Nhap ho va ten hoc sinh:");
        scanf("%[^\n]",ds[i].tenhs);
        printf("Diem tong ket:");
        scanf("%f",&ds[i].tk);

    }
   indanhsach(ds,n);

   HocSinh ds_tk[10];
   for(int i = 0;i<n;i++){
        ds_tk[i]=ds[i];

   }
   for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds_tk[i].tk < ds_tk[j].tk) {
                HocSinh temp = ds_tk[i];
                ds_tk[i] = ds_tk[j];
                ds_tk[j] = temp;
            }
        }
    }

    printf("\n1/ DANH SACH SAP XEP THEO DIEM GIAM DAN:\n");
    indanhsach(ds_tk, n);

    HocSinh ds_ten[10];
    for (int i = 0; i < n; i++) {
        ds_ten[i] = ds[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ds_ten[i].tenhs, ds_ten[j].tenhs) > 0) {
                HocSinh temp = ds_ten[i];
                ds_ten[i] = ds_ten[j];
                ds_ten[j] = temp;
            }
        }
    }

    printf("\n2/ DANH SACH SAP XEP THEO TEN (ABC):\n");
    indanhsach(ds_ten, n);


}



