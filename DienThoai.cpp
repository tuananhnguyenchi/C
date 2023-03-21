#include<stdio.h>
#include<string.h>
#include<vector>
#include <stdint.h>

//
using namespace std;
// class Điện Thoại
class DienThoai
{
    private:
      uint8_t ID;
      char TenDienThoai[20];
      char HangSanXuat[20];
      double Gia;
    public:
      DienThoai();
      char *getTenDienThoai();
      char *getHangSanXuat();
      double getGia();
      uint8_t getID();
      void setDienThoai();
      void setHangSanXuat();
      void setGia();
};
DienThoai::DienThoai()
{
  static uint8_t id=100;
  printf("Nhap ten dien thoai:");
  fflush(stdin);
	gets(TenDienThoai);
  printf("Nhap hang san xuat dien thoai:");
  fflush(stdin);
	gets(HangSanXuat);
  printf("Nhap gia dien thoai:");
  scanf("%d",&Gia);
  ID=id;
  id++;
}
char* DienThoai:: getTenDienThoai()
{
     return TenDienThoai;
}
char* DienThoai:: getHangSanXuat()
{
    return HangSanXuat;
}
double DienThoai::getGia()
{
  return Gia;
  
}
uint8_t DienThoai::getID()
{
  return ID;
}
void DienThoai::setDienThoai()
{
  char Ten[];
  printf("Nhap ten dien thoai:");
  fflush(stdin);
	gets(Ten);
  strcpy(TenDienThoai,Ten);
}
void DienThoai::setHangSanXuat()
{
  char Hang[];
  printf("Nhap hang san xuat dien thoai:");
  fflush(stdin);
	gets(Hang);
  strcpy(HangSanXuat,Hang);
}
void DienThoai::setGia()
{
  double gia;
  printf("Nhap gia dien thoai:");
  scanf("%d",&gia);
  Gia=gia;
}
//class quản lý điện thoại
class QuanLyDienThoai
{
    private:
      vector <DienThoai> Database_Dien_Thoai;
    public:
    void ThemDienThoai(DienThoai dt);
    void SuaDienThoai(uint8_t id);
    void XoaDienThoai(uint8_t id);
    void HienThiDanhSachDienTHoai();
};
void QuanLyDienThoai::ThemDienThoai()
{
   printf("Nhap Thong Tin Dien Thoai Can Them Vao:\n");
   DienThoai dt;
   Database_Dien_Thoai.push_back(dt);
}
void QuanLyDienThoai:: SuaDienThoai(uint8_t id)
{  
    uint8_t h;
    for(uint8_t i=0;i<Database_Dien_Thoai.size();i++)
    {  
       if(id==Database_Dien_Thoai[i].getID())
       {
         printf("****************************************************\n");
         printf("***          THONG TIN DIEN THOAI CAN SUA :      ***\n");
         printf("*** ID         TEN         HANG            GIA   ***\n");
         printf("**  %d          %c           %c             %d   ***\n",Database_Dien_Thoai[i].getID(),Database_Dien_Thoai[i].getTenDienThoai(),Database_Dien_Thoai[i].getHangSanXuat(),Database_Dien_Thoai[i].getGia());
         printf("****************************************************\n");
         printf("\n");
         h=i;
         break;
       }
    }
    printf("***********************************\n");
    printf("*** Nhan 1 de sua ten           ***\n");
    printf("*** Nhan 2 de sua gia           ***\n");
    printf("*** Nhan 3 de sua hang san xuat ***\n");
    printf("*** Nhan 0 de thoat             ***\n");
    printf("***********************************\n");
    printf("\n");
    printf("Nhap che do ban muon:");
    scanf("%d",&key);
    switch(key)
    {
      case 0:
       break;
      case 1:
        Database_Dien_Thoai[h].setDienThoai();
        break;
      case 2:
        Database_Dien_Thoai[h].setGia();
        break;
      case 3:
        Database_Dien_Thoai[h].setHangSanXuat();
        break;
      default :
        break;  
    }   
}
void QuanLyDienThoai::XoaDienThoai(uint8_t id)
{
  
}
void QuanLyDienThoai::HienThiDanhSachDienTHoai()
{
  printf("******************************************************\n");
  printf("***           DANH SACH DIEN THOAI HIEN CO         ***\n");
  printf("*** ID         TEN         HANG            GIA     ***\n");
  for(uint8_t i=0;i<Database_Dien_Thoai.size();i++)
  {
    printf("**  %d          %c           %c             %d   ***\n",Database_Dien_Thoai[i].getID(),Database_Dien_Thoai[i].getTenDienThoai(),Database_Dien_Thoai[i].getHangSanXuat(),Database_Dien_Thoai[i].getGia());
  }
  printf("******************************************************\n");
}

class SmartPhone:public DienThoai
{
    private:
     uint16_t dungLuongPin;
     uint8_t dungLuongBoNho;
    public:
     SmartPhone(char ten[],char hang[],double gia,uint16_t pin,uint8_t boNho);
     uint16_t getDungLuongPin();
     uint8_t  getDungLuongBoNho();
     void     setDungLuongPin(uint16_t pin);
     void     setDungLuongBoNho(uint8_t boNho);
};

int main(int argc, char const *argv[])
{
    //DienThoai dt;
    //double h;
    //printf("Gia dien thoai la %3f",dt.getGia());
}