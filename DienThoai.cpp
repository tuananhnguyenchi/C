#include<stdio.h>
#include<string.h>

class DienThoai
{
    private:
      uint16_t ID;
      char TenDienThoai[20];
      char HangSanXuat[20];
      double Gia;
    public:
      DienThoai(char Ten[],char Hang[],double gia);
      char *getTenDienThoai(char Ten[]);
      char *getHangSanXuat(char Hang[]);
      double getGia(double gia);
      void setDienThoai();
      void setHangSanXuat();
      void setGia();

};
DienThoai::DienThoai(char Ten[],char Hang[],double gia)
{
  static uint16_t id=100;
  strcpy(TenDienThoai,Ten);
  strcpy(HangSanXuat,Hang);
  Gia=gia;
  ID=id;
  id++;
}
char DienThoai::*getTenDienThoai(char Ten[])
{

}
char DienThoai::getHangSanXuat(char Hang[])
{

}
double DienThoai::getGia(double gia)
{
  
}

class QuanLyDienThoai
{
    private:
    vecter<DienThoai> DanhSachDienThoai;
    public:
    void ThemDienThoai(DienThoai &dt);
    void SuaDienThoai(uint8_t id);
    void XoaDienThoai(uint8_t id);
    void HienThiDanhSachDienTHoai();
};

class SmartPhone:public DienThoai
{
    private:
     uint16_t dungLuongPin
     uint8_t dungLuongBoNho;
    public:
     SmartPhone(char ten[],char hang[],double gia,uint16_t pin,uint8_t boNho);
     uint16_t getDungLuongPin(uint16_t pin);
     uint8_t getDungLuongBoNho(uint8_t boNho);
     void     setDungLuongPin(uint16_t pin);
     void     setDungLuongBoNho(uint8_t boNho);
}

int main()
{
    
}