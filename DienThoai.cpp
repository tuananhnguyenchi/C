// nguyen chi tuan anh 
// update
#include<stdio.h>
#include<string.h>
#include<vector>
#include <stdint.h>

using namespace std;
// class Điện Thoại
class DienThoai
{
    private:
      uint8_t ID;
      char tenDienThoai[20];
      char hangSanXuat[20];
      double giaDienThoai;
    public:
      DienThoai(char ten[], char hang[], double gia);
      char *getTenDienThoai();
      char *getHangSanXuat();
      double getGia();
      uint8_t getID();
      void setDienThoai(char ten[]);
      void setHangSanXuat(char hang[]);
      void setGia(double gia);
};
DienThoai::DienThoai(char ten[], char hang[], double gia)
{
  static uint8_t id=100;
  ID=id;
  strcpy(tenDienThoai,ten);
  strcpy(hangSanXuat,hang);
  giaDienThoai=gia;
  ID=id;
  id++;
}
char* DienThoai:: getTenDienThoai()
{
     return tenDienThoai;
}
char* DienThoai:: getHangSanXuat()
{
    return hangSanXuat;
}
double DienThoai::getGia()
{
  return giaDienThoai; 
}
uint8_t DienThoai::getID()
{
  return ID;
}
void DienThoai::setDienThoai(char ten[])
{
 
  strcpy(tenDienThoai,ten);
}
void DienThoai::setHangSanXuat(char hang[])
{
  strcpy(hangSanXuat,hang);
}
void DienThoai::setGia(double gia)
{

  giaDienThoai=gia;
}
//class quản lý điện thoại
class QuanLyDienThoai
{
    private:
      vector <DienThoai> Database_Dien_Thoai;
      enum TRANG_THAI
      {
        THEM=1,
        SUA,
        XOA,
        HIEN_THI,
      }TRANG_THAI;
      bool kiemTraId(uint8_t id);
    public:
      QuanLyDienThoai();
      void ThemDienThoai();
      void SuaDienThoai();
      void XoaDienThoai();
      void HienThiDanhSachDienTHoai();
};
QuanLyDienThoai::QuanLyDienThoai()
{
  while(1)
  {
    uint8_t luaChon;
    printf("*********************************************\n");
    printf("** 1.Them Dien Thoai Moi Vao Danh Sach     **\n");
    printf("** 2.Sua Thong Tin Dien Thoai              **\n");
    printf("** 3.Xoa Dien Thoai Khoi Danh Sach         **\n");
    printf("** 4.Hien Thi Danh Sach Dien Thoai         **\n");
    printf("*********************************************\n");
    printf("\n");
    printf("Moi nhap lua chon cua ban:");
    scanf("%d",&luaChon);
    switch(luaChon)
    {
      case THEM:
       uint8_t key1;
       do{
         printf("***********************\n");
         printf("** 1.Them dien thoai **\n");
         printf("** 2.Thoat           **\n");
         printf("***********************\n");
         printf("\n");
         printf("Moi nhap lua chon cua ban:");
         scanf("%d",&key1);
         if(key1==1)
         {
          ThemDienThoai();
         } 
         if((key1!=1)&&(key1!=2))
         {
          printf("Khong hop le.De nghi chi nhap 1 hoac 2 \n");
         }    
         }while(key1!=2);
         break;
      case SUA:
         uint8_t key2;
         do
         {
           printf("***********************************\n");
           printf("*** Nhan 1 tiep tuc sua         ***\n");
           printf("*** Nhan 0 de thoat             ***\n");
           printf("***********************************\n");
           printf("\n");
           printf("Nhap che do ban muon:");
           scanf("%d",&key2);
           if(key2==1)
           {
            SuaDienThoai();
           }
           if((key2!=1)&&(key2!=0))
           {
            printf("Khong hop le.De nghi chi nhap 1 hoac 0 thoi.\n");
           }
         } while(key2!=0);
          break;
      case XOA:
          uint8_t key3;
         do
         {
           printf("***********************************\n");
           printf("*** Nhan 1 tiep tuc xoa         ***\n");
           printf("*** Nhan 0 de thoat             ***\n");
           printf("***********************************\n");
           printf("\n");
           printf("Nhap che do ban muon:");
           scanf("%d",&key3);
           if(key3==1)
           {
            XoaDienThoai();
           }
           if((key3!=1)&&(key3!=0))
           {
            printf("Khong hop le.De nghi chi nhap 1 hoac 0 thoi.\n");
           }
         } while(key3!=0);
          break;
      case HIEN_THI:
         HienThiDanhSachDienTHoai();
      
    }

  }
}
bool QuanLyDienThoai::kiemTraId(uint8_t id)
{
  for(uint8_t i=0;i<Database_Dien_Thoai.size();i++)
  {
     if(id=Database_Dien_Thoai[i].getID())
     {
       return true;
     }
     
  }
  return false;
}
void QuanLyDienThoai::ThemDienThoai()
{
   char tenDienThoai[20];
   char hangSanXuat[20];
   double giaDienThoai;
   printf("Nhap Thong Tin Dien Thoai Can Them Vao:\n");
   printf("Nhap vao ten dien thoai:");
   fflush(stdin);
   gets(tenDienThoai);
   printf("Nhap vao hang san xuat dien thoai:");
   fflush(stdin);
   gets(hangSanXuat);
   printf("Nhap vao gia dien thoai:");
   scanf("%d",&giaDienThoai);
   DienThoai dt(tenDienThoai,hangSanXuat,giaDienThoai);
   Database_Dien_Thoai.push_back(dt);
}
void QuanLyDienThoai:: SuaDienThoai()
{  
    uint8_t key,idTam;
    printf("Nhap ID dien thoai can sua:\n");
    scanf("%d",&idTam);
    do
    {
      if(kiemTraId(idTam)==false)
      {
       printf("Dien thoai can sua khong ton tai\n");
      }
     else
      {
       uint8_t h;
      for(uint8_t i=0;i<Database_Dien_Thoai.size();i++)
      {  
       if(idTam==Database_Dien_Thoai[i].getID())
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
        char ten[20];
        printf("Nhap ten moi cua dien thoa:");
        fflush(stdin);
        gets(ten);
        Database_Dien_Thoai[h].setDienThoai(ten);
        break;
      case 2:
        double gia;
        printf("Nhap gia moi cua dien thoai:");
        scanf("%d",&gia);
        Database_Dien_Thoai[h].setGia(gia);
        break;
      case 3:
        char hang[20];
        printf("Nhap hang san xuat moi cua dien thoai:");
        fflush(stdin);
        gets(hang);
        Database_Dien_Thoai[h].setHangSanXuat(hang);
        break;
      default :
        printf(" Khong hop le .De nghi chi nhap 1/2/3/0 va khong nhap so khac\n");
        break;  
    }
  } 
  }while(key!=0); 
}
void QuanLyDienThoai::XoaDienThoai()
{
   uint8_t idTam;
   printf("Nhap ID cua dien thoai can xoa\n");
   scanf("%d",&idTam);
   if(kiemTraId(idTam)==false)
   {
    printf("ID khong ton tai.");
   }
   else
   {
    for(uint8_t i=0;i<Database_Dien_Thoai.size();i++)
      {
         if(idTam==Database_Dien_Thoai[i].getID())
         {
          Database_Dien_Thoai.erase(Database_Dien_Thoai.begin()+i);
         }
      }

   } 
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

/*class SmartPhone:public DienThoai
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
*/
int main(int argc, char const *argv[])
{
    QuanLyDienThoai qldt;
}