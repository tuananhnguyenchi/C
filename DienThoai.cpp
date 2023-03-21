#include<stdio.h>
#include<string.h>
#include<vector>
#include <stdint.h>
// class Điện Thoại
class DienThoai
{
    private:
      uint16_t ID;
      char TenDienThoai[20];
      char HangSanXuat[20];
      double Gia;
    public:
      DienThoai();
      char *getTenDienThoai();
      char *getHangSanXuat();
      double getGia();
      void setDienThoai(char Ten[]);
      void setHangSanXuat(char Hang[]);
      void setGia(double gia);
      void NhapThongTinDienThoai();

};
DienThoai::DienThoai()
{
  static uint16_t id=100;
  printf("Nhap ten dien thoai:");
  fflush(stdin);
	gets(TenDienThoai);
  printf("Nhap hang san xuat dien thoai:");
  fflush(stdin);
	gets(HangSanXuat);
  printf("Nhap gia dien thoai:");
  scanf("%lf",&Gia);
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
void DienThoai::setDienThoai(char Ten[])
{
  strcpy(TenDienThoai,Ten);
}
void DienThoai::setHangSanXuat(char Hang[])
{
  strcpy(HangSanXuat,Hang);
}
void DienThoai::setGia(double gia)
{
  Gia=gia;
}


//class quản lý điện thoại
class QuanLyDienThoai
{
    private:
      //vector <DienThoai> DanhSachDienThoai;
    public:
    void ThemDienThoai(DienThoai dt);
    void SuaDienThoai(uint8_t id);
    void XoaDienThoai(uint8_t id);
    void HienThiDanhSachDienTHoai();
};
void QuanLyDienThoai::ThemDienThoai(DienThoai dt)
{
   printf("Nhap Thong Tin Dien Thoai Can Them Vao:\n");
   

}

class SmartPhone:public DienThoai
{
    private:
     uint16_t dungLuongPin;
     uint8_t dungLuongBoNho;
    public:
     SmartPhone(char ten[],char hang[],double gia,uint16_t pin,uint8_t boNho);
     uint16_t getDungLuongPin(uint16_t pin);
     uint8_t getDungLuongBoNho(uint8_t boNho);
     void     setDungLuongPin(uint16_t pin);
     void     setDungLuongBoNho(uint8_t boNho);
};

int main(int argc, char const *argv[])
{
    DienThoai dt;
    double h;
    printf("Gia dien thoai la %3f",dt.getGia());
}