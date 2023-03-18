// nguyen chi tuan anh
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <stdbool.h>
using namespace std;
//
typedef struct 
{
    uint8_t STT;
    uint8_t ID;
    char    TEN_MON[30];
    uint16_t GIA;
}thuc_don;
//
typedef struct
{
  thuc_don THONG_TIN_MON;
  uint8_t SO_LUONG;
}so_luong_mon;
//
typedef struct
{
    uint8_t SO_BAN;
    bool TRANG_THAI=false; // khởi tạo ban đầu là bàn không có người
    vector<so_luong_mon> DATA_MON;
}thong_tin_ban;
//
static vector<thuc_don> Database_Thuc_Don;
static vector<thong_tin_ban> Database_Thong_Tin_Ban(9);// khởi tạo 9 bàn 

//===============================================================//

void DanhSachMon(vector<thuc_don> Database)
{
   printf("*****************************************\n");
       printf("*  STT    ID    TEN MON         GIA   ***\n");
    for(uint8_t i=0;i<Database.size();i++)
    {
       printf("*  %d     %d    %s           %d  ***\n",Database[i].STT,Database[i].ID,Database[i].TEN_MON,Database[i].GIA);
    }
       printf("*****************************************\n");
}
//
bool check(uint8_t ID,vector<thuc_don> Database)
{
  for(uint8_t i=0;i<Database.size();i++)
  {
    if(Database[i].ID==ID)
    {
      return true;
    }
  }
  return false;
}
//
uint8_t checkMonAn(uint8_t ID,vector<thuc_don> Database)
{
  for(uint8_t i=0;i<Database.size();i++)
  {
    if(Database[i].ID==ID)
    {
      return i;
    }
  }
  return 0;
}
//============================================================================//


class Quan_Ly
{
    public:
    Quan_Ly();
    //vector<thuc_don> Database_Thuc_Don;
    void Them_Mon();
    void Sua_Mon();
    void Xoa_Mon();
    void Hien_Thi_Danh_Sach_Mon();
};
Quan_Ly::Quan_Ly()
{
    printf("DAY LA TRANG DANH CHO QUAN LY \n");
}
void Quan_Ly::Them_Mon()
{
    thuc_don td;
    static uint8_t id=100;
    printf("Nhap vao ten mon:");
    fflush(stdin);
    gets(td.TEN_MON);
    printf("Nhap vao gia: ");
    scanf("%d",&td.GIA);
    td.ID=id;
    td.STT=Database_Thuc_Don.size()+1;

    Database_Thuc_Don.push_back(td);
    id++;
}
void Quan_Ly::Sua_Mon()
{
  uint8_t key;
  printf("Nhap ID cua mon an can sua \n");
  scanf("%d",&key);
  for(uint8_t i=0;i<Database_Thuc_Don.size();i++)
  {
    if(Database_Thuc_Don[i].ID==key)
    { 
        uint8_t phim;
        printf("***********************************\n");
        printf("***  1.Nhan 1 de sua ten mon    ***\n");
        printf("***  2.Nhan 2 de sua gia mon    ***\n");
        printf("***********************************\n");
        printf("\nNhap che do ban muon:");
        scanf("%d",&phim);
        switch(phim)
        {
            case 1:
             printf(" Nhap lai ten mon: ");
             fflush(stdin);
             gets(Database_Thuc_Don[i].TEN_MON);
             break;
            case 2:
             printf("Nhap lai gia moi: " );
             scanf("%d",&Database_Thuc_Don[i].GIA);
             break;
            default:
              printf("Khong hop le.");
              break;
        }

    }
    else
    {
        printf(" ID khong hop le");
    }
  }
}
void Quan_Ly::Xoa_Mon()
{
  uint8_t key;
  printf("Nhap ID cua mon an can xoa \n");
  scanf("%d",&key);
  for(uint8_t i=0;i<Database_Thuc_Don.size();i++)
  {
    if(Database_Thuc_Don[i].ID==key)
    {
      Database_Thuc_Don.erase(Database_Thuc_Don.begin()+i);
    }
    else
    {
      printf(" Mon an can xoa khong co trong danh sach.\n");
    }
  }
}
void Quan_Ly::Hien_Thi_Danh_Sach_Mon()
{
   /*   printf("*****************************************\n");
       printf("*  STT    ID    TEN MON         GIA   ***\n");
    for(uint8_t i=0;i<Database_Thuc_Don.size();i++)
    {
       printf("*  %d     %d    %s      %d   ***\n",Database_Thuc_Don[i].STT,Database_Thuc_Don[i].ID,Database_Thuc_Don[i].TEN_MON,Database_Thuc_Don[i].GIA);
    }
       printf("*****************************************\n");
       */
       DanhSachMon(Database_Thuc_Don);
}
//=============================================================//

class Nhan_Vien
{
    public:
    void Goi_Mon(uint8_t ban);
    void Tinh_Tien(uint8_t ban);
};

void Nhan_Vien::Goi_Mon(uint8_t soban)
{
  
  thong_tin_ban ttb;
  so_luong_mon slm;
  DanhSachMon(Database_Thuc_Don);
  uint8_t id;//ID mon an duoc nhap tu ban phim
  uint8_t sl;// Số lượng món ăn được nhập từ bàn phím
  printf(" Nhap ID mon an :");
  scanf("%d",&id);
  while(check(id,Database_Thuc_Don)==false)
  {
    printf("ID mon an khong hop le.De nghi nhap lai");
    scanf("%d",&id);
  }
  printf("Nhap so luong mon an:");
  scanf("%d",&sl);
  ttb.SO_BAN=soban;
  ttb.TRANG_THAI=true ;// Tức là đã có người ngồi còn flase là bàn còn trống
  slm.SO_LUONG=sl;
  //slm.THONG_TIN_MON=Database_Thuc_Don[h];
 // ttb.DATA_MON.so_luong_mon=sl; //
  uint8_t h=checkMonAn(id,Database_Thuc_Don);
  slm.THONG_TIN_MON=Database_Thuc_Don[h];
  ttb.DATA_MON.push_back(slm);
  Database_Thong_Tin_Ban.push_back(ttb);
}
void Nhan_Vien::Tinh_Tien(uint8_t ban)
{
       printf("*****************************************\n");
       printf("*  SO BAN    ID    TEN MON     SO LUONG    GIA   ***\n");
    for(uint8_t i=0;i<Database_Thong_Tin_Ban.size();i++)
    {
       if(Database_Thong_Tin_Ban[i].SO_BAN==ban)
       {
        for(uint8_t j=0;j<Database_Thong_Tin_Ban[i].DATA_MON.size();j++)
        {
        printf("*  %d     %d    %s      %d    %d*%d***\n",Database_Thong_Tin_Ban[i].SO_BAN,Database_Thong_Tin_Ban[i].DATA_MON[j].THONG_TIN_MON.ID,Database_Thong_Tin_Ban[i].DATA_MON[j].THONG_TIN_MON.TEN_MON,Database_Thong_Tin_Ban[i].DATA_MON[j].SO_LUONG,Database_Thong_Tin_Ban[i].DATA_MON[j].SO_LUONG,Database_Thong_Tin_Ban[i].DATA_MON[j].THONG_TIN_MON.GIA);
        }
        Database_Thong_Tin_Ban[i].TRANG_THAI=false;
        break;
    }
       printf("*****************************************\n");
    }     
}

class DisPlay 
{
  public:
  DisPlay();
  Quan_Ly ql;
  Nhan_Vien nv;
  //DisPlay();
  void DisPlay_Quan_Ly();
  void DisPlay_Nhan_Vien();
};
DisPlay::DisPlay()
{   
    uint8_t key=0; //
    printf("***********************************\n");
    printf("***  1.Nhan 1 de vao quan ly    ***\n");
    printf("***  2.Nhan 2 de vao nhan vien  ***\n");
    printf("***********************************\n");
    printf("\nNhap che do ban muon:");
    scanf("%d",&key);
    switch(key)
    {
        case 1:
        DisPlay_Quan_Ly();
        break;
        case 2:
        DisPlay_Nhan_Vien();
        break;
        default:
         printf(" Khong hop le .");
         break;
    }

}
void DisPlay::DisPlay_Quan_Ly()
{  uint8_t key;
   do
   {
    //uint8_t key;
    printf("************************************************\n");
    printf("**         CHE DO QUAN LY                     **\n");
    printf("**   1.Them Mon                               **\n");
    printf("**   2.Sua Mon                                **\n");
    printf("**   3.Xoa Mon                                **\n");
    printf("**   4.Hien Thi Danh Sach Mon                 **\n");
    printf("**   5.Quay Lai                               **\n");
    printf("************************************************\n");
    printf(" Nhap che do ban muon su dung:");
    scanf("%d",&key);
    //uint8_t key;
    switch(key)
    {
      case 1:
        uint8_t key1;
        do
        {
         ql.Them_Mon();
         printf("1.Them mon moi\n");
         printf("2.Quay lai quan ly\n");
         //uint8_t key1;
         printf("Nhap che do ban muon:");
         scanf("%d",&key1);
        }
        while(key1!=2);
        break;
      case 2:
       ql.Sua_Mon();
       break;
      case 3:
        ql.Xoa_Mon();
        break;
      case 4:
        ql.Hien_Thi_Danh_Sach_Mon();
        break;
      case 5:
        break;
      default:
       printf(" Khong hop le.\n");
       break;
    }
   } while(key!=5);

  // return 0;
}
void DisPlay::DisPlay_Nhan_Vien()
{
  uint8_t key;
  do
  {  
   printf("********************************************************************\n");
   printf("**                     CHE DO NHAN VIEN                           **\n");
   for(uint8_t i =0; i<9; i++)
    {
      
        printf("BAN %d\t", i+1);
    }
    printf("\n");    
    for(uint8_t i = 0; i<9; i++)
    {
        if(Database_Thong_Tin_Ban[i].TRANG_THAI == false) printf("  -  \t");
        else printf("  x  \t");
    } 
    
    printf("\n*********************************************************************\n"); 
    uint8_t ban;
    printf("Chon ban :");
    scanf("%d",&ban);

   // While(ban>9)
   // {
    //  printf("Ban khong hop le.Moi chon lai:");
     // scanf("%d",&ban);
   // }

   printf("********************************************************************\n");
   printf("**                     CHE DO NHAN VIEN                           **\n");
   printf("**   1.Goi Mon                                                    **\n");
   printf("**   2.Tinh Tien                                                  **\n");
   printf("**   3.Quay lai                                                   **\n");
   printf("********************************************************************\n");
   printf(" Nhap che do ban muon:");
   scanf("%d",&key);
   switch(key)
   {
    case 1:
    uint8_t key1;
    do
    {
     nv.Goi_Mon(ban);
     printf("**************************************\n");
     printf("** 1.Tiep tuc goi mon               **\n");
     printf("** 2.Quay Lai                       **\n");
     printf("**************************************\n");
     printf("Nhap lua chon:");
     scanf("%d",&key1);
     }while(key1!=2);
     break;
    case 2:
     while(1)
     {
      nv.Tinh_Tien(ban);
     } 
      //printf("")
      break;
    

   } 
  }while(key!=3);
}


//
int main(int argc, char const *argv[])
{ 
   
   DisPlay Menu;
   while(true)
   {
   	DisPlay Menu;
    Menu;
   }
}
