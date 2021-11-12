//Bai 1
/*
#include <stdio.h>
#include <math.h>
#define MAX1 49999
#define MAX2 10000
double Tong_cau_a();
double Tong_cau_b();
int main(){
    double pi_cau_a, pi_cau_b;
    pi_cau_a=4*Tong_cau_a();
    pi_cau_b=sqrt(6*Tong_cau_b());
    printf("pi_a=%lf\n",pi_cau_a);
    printf("pi_b=%lf\n",pi_cau_b);

}
double Tong_cau_a(){
    double sum=0;
    for(int i=0;i<=MAX1;i++){
        if(i % 2 ==0){
            sum+=1.0/(2*i+1);
        }else{
            sum-=1.0/(2*i+1);
        }
    }
    return sum;
}
double Tong_cau_b(){
    double sum=0;
    for(int i=1;i<=MAX2;i++){
        sum+=1.0/pow(i,2);
    }
    return sum;
}
*/

//Bai 2
/*
#include <stdio.h>
#include <math.h>
const double epsilon=0.00001;
float TinhLapDon(float alpha, float);
float g(float alpha, float u);
int main(){
    float alpha, u;
    printf("Nhap cong suat ngo ra u: ");
    scanf("%f", &u);
    if(u<0.00){
        alpha=M_PI;
    }else if(u>1.0){
        alpha=0;
    }else{
        alpha=TinhLapDon(alpha, u);
    }
    printf("\nGoc kich alpha (tinh theo radian)=%f",alpha);
}
float TinhLapDon(float alpha, float u){
    float y;
    alpha=M_PI/2.0;
    do{
        y=alpha;
        alpha=g(alpha, u);  
    }while(fabs(alpha-y)>epsilon);
    return alpha;
}
float g(float alpha, float u){
    return (2*M_PI*(1-u)+sin(2*alpha))/2.0;
}
*/



//Bai 3

#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
//void NhapToaDoDiemA();
int main(){
    int n_a, n_b, n_c;
    char key;
    //Xu li A 
    printf("Nhap so diem cua A: ");
    scanf("%d",&n_a);
    float Hoanh_Do_A[n_a];
    float Tung_Do_A[n_a];
    float A_XTB, A_YTB, sumAx=0, sumAy=0;
    for(int i=0;i<n_a;i++){
        printf("Nhap toa do A[%d]: ",i);
        scanf("%f%f",&Hoanh_Do_A[i],&Tung_Do_A[i]);
    }
    for(int i=0;i<n_a;i++){
        sumAx+=Hoanh_Do_A[i];
        sumAy+=Tung_Do_A[i];
    }
    A_XTB=sumAx/(float)n_a;
    A_YTB=sumAy/(float)n_a;
    printf("Diem dai dien cho A: A_TB(%f,%f)\n",A_XTB, A_YTB);    
    
    //-------------------------------

    //Xu li B
    
    printf("Nhap so diem cua B: ");
    scanf("%d",&n_b);
    float Hoanh_Do_B[n_b];
    float Tung_Do_B[n_b];
    float B_XTB, B_YTB, sumBx=0, sumBy=0;
    for(int i=0;i<n_b;i++){
        printf("Nhap toa do B[%d]: ",i);
        scanf("%f%f",&Hoanh_Do_B[i],&Tung_Do_B[i]);
    }
    for(int i=0;i<n_b;i++){
        sumBx+=Hoanh_Do_B[i];
        sumBy+=Tung_Do_B[i];
    }
    B_XTB=sumBx/(float)n_b;
    B_YTB=sumBy/(float)n_b;
    printf("Diem dai dien cho B: B_TB(%f,%f)\n",B_XTB, B_YTB);
    
    //----------------------------------------

    //Xu li C
    
    printf("Nhap so diem cua C: ");
    scanf("%d",&n_c);
    float Hoanh_Do_C[n_c];
    float Tung_Do_C[n_c];
    float C_XTB, C_YTB, sumCx=0, sumCy=0;
    for(int i=0;i<n_c;i++){
        printf("Nhap toa do C[%d]: ",i);
        scanf("%f%f",&Hoanh_Do_C[i],&Tung_Do_C[i]);
    }
    for(int i=0;i<n_c;i++){
        sumCx+=Hoanh_Do_C[i];
        sumCy+=Tung_Do_C[i];
    }
    C_XTB=sumCx/(float)n_c;
    C_YTB=sumCy/(float)n_c;
    printf("Diem dai dien cho C: C_TB(%f,%f)\n",C_XTB, C_YTB);
    
    //----------------------------------

    //xu li X
    float XA, XB, XC, KC_min;
    float Hoanh_Do_X, Tung_Do_X;
    do{
        printf("Nhap toa do cua X: ");
        scanf("%f%f",&Hoanh_Do_X, &Tung_Do_X);
        XA=sqrt(pow((Hoanh_Do_X-A_XTB),2)+pow(Tung_Do_X-A_YTB,2));
        XB=sqrt(pow((Hoanh_Do_X-B_XTB),2)+pow(Tung_Do_X-B_YTB,2));
        XC=sqrt(pow((Hoanh_Do_X-C_XTB),2)+pow(Tung_Do_X-C_YTB,2));
        KC_min=XA<XB?(XA<XC?XA:XC):(XB<XC?XB:XC);
        if(KC_min==XA){
            printf("Phan loai X thuoc tap A\n");
        }else if(KC_min==XB){
            printf("Phan loai X thuoc tap B\n");
        }else{
            printf("Phan loai X thuoc tap C\n");
        }
        printf("Nhap ESC de thoat!\n");
        Sleep(2000);
        if(kbhit()){
            key=getch();
        }
    }while(key!=27);
}



/*void HoanhDoDiemA(int n_a){
    float Hoanh_Do[n_a];
    float Tung_Do[n_a];
    float A_XTB=0, A_YTB=0;
    for(int i=0;i<n_a;i++){
        printf("Nhap toa do A[%d]: ",i);
        scanf("%d%d",&Hoanh_Do[i],&Tung_Do[i]);
    }
    for(int i=0;i<n_a;i++){
        A_XTB+=Hoanh_Do[i];
        A_YTB+=Tung_Do[i];
    }
    return A_XTB/(float)n_a;

}
*/

