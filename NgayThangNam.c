#include<stdio.h>
#include<stdint.h>
#include <stdbool.h>
#define namnhuan 366
#define namthuong 365
typedef enum{
    THANG_MOT = 1,
    THANG_HAI,
    THANG_BA,
    THANG_BON,
    THANG_NAM,
    THANG_SAU,
    THANG_BAY,
    THANG_TAM,
    THANG_CHIN,
    THANG_MUOI,
    THANG_MUOI_MOT,
    THANG_MUOI_HAI,
}THANG;
//
typedef enum{
    THU_HAI=2,
    THU_BA,
    THU_TU,
    THU_NAM,
    THU_SAU,
    THU_BAY,
    CHU_NHAT,
}THU;
//
typedef struct 
{
    uint8_t ngay;
    THANG thang;
    uint16_t nam;
}thoigian;
//
const thoigian thoigiangoc={1,1,1};
const THU thugoc=THU_HAI;
int Kiemtranam( thoigian m)
{
    if (m.nam % 400==0)
    {
        return 1;
    }
    if((m.nam %4 ==0)&&(m.nam %100 !=0))
    {
        return 1;
    }
    return 0;
}
//
int songaytrongthang(thoigian m)
{
 switch(m.thang)
 {
  case THANG_MOT:
  case THANG_BA:
  case THANG_NAM:
  case THANG_BAY:
  case THANG_TAM:
  case THANG_MUOI:
  case THANG_MUOI_HAI:
     return 31;
     break;
  case THANG_BON:
  case THANG_SAU:
  case THANG_CHIN:
  case THANG_MUOI_MOT:
    return 30;
    break;
  case THANG_HAI:
   if(Kiemtranam(m)==1)
   {
    return 29;
    
   }
   else 
   {
    return 28;
   }
   break;
  default :
   printf("ERROR!Thang khong hop le");
   break;
 }
 
}
//
void Tinhthu(thoigian m)
{
    uint32_t  songay=0;
    thoigian i;  
    THU thuhientai; 
    uint32_t n;
        //
    for( i.nam=thoigiangoc.nam; i.nam<m.nam; i.nam++)
    {
            if(Kiemtranam(i)==1)
            {
              songay+=namnhuan;
            }
            else
            {
                songay+=namthuong;
            }
    }
        //
    for( i.thang=thoigiangoc.thang;i.thang<m.thang;i.thang++)
    {
                songay+=songaytrongthang(i);
    }
        
        //
    songay+= m.ngay- thoigiangoc.ngay;
    n=(songay)%7;
    switch(n)
    {
        case 0:
          printf("thu hai");
          break;
        case 1:
          printf("thu ba");
          break;
        case 2:
          printf(" thu tu");
          break;
        case 3:
          printf("Thu nam");
          break;
        case 4:
          printf("Thu sau");
          break;
        case THU_NAM:
          printf("Thu bay");
          break;
        case 6:
          printf("chu nhat");
          break;
        default:
          printf(" Khong hop le");
          break;
    }  
}
//
bool check(thoigian m)
{
    if(m.nam<1)  return false;
    if(m.thang<1||m.thang>12) return false;
    switch(m.thang)
    {
        case THANG_MOT:
        case THANG_BA:
        case THANG_NAM:
        case THANG_BAY:
        case THANG_TAM:
        case THANG_MUOI:
        case THANG_MUOI_HAI:
          if(m.ngay<1||m.ngay>31) return false;
          break;
        case THANG_BON:
        case THANG_SAU:
        case THANG_CHIN:
        case THANG_MUOI_MOT:  
           if(m.ngay<1||m.ngay>30) return false;
           break;
        case THANG_HAI:
           if(Kiemtranam(m)==1)
           {
            if(m.ngay<1||m.ngay>29) return false;
           }
           else
           {
            if(m.ngay<1||m.ngay>28) return false;           
           }
        default :
          break;
        
    }
    return true;
}
void NhapXuat(thoigian *m)
{
 do
 {
  printf(" Nhap vao ngay:");
  scanf("%d",(int*)(&m->ngay));
  printf(" Nhap vao thang:");
  scanf("%d",(int*)(&m->thang));
  printf(" Nhap vao ngay:");
  scanf("%d",(int*)(&m->nam));
 }
 while(check(*m)==false);
}
int main(int argc,char const *argv[])
{
   thoigian m;
   NhapXuat(&m);
   Tinhthu(m);
   
}
