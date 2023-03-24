#include<stdio.h>
#include<string.h>
#include<vector>
#include <stdint.h>

class Sach
{
    private:
     uint8_t id;
     char tenSach[20];
     char tacGia[20];
     uint32_t namXuatBan;
     uint8_t soLuong;
    public:
     Sach(char ten[],char tacgia[],uint32_t nam,uint8_t soluong);
     char *getTenSach();
     char *getTacGia();
     uint32_t getNamXuatBan();
     uint8_t getSoLuong();
     void setTenSach(char ten[]);
     void setTacGia(char tacGia);
     void setGia(uint32_t nam) ;
     void setSoLuong(uint32_t soluong);
}
class QuanLySach
{
    private:
    vector <Sach> Database;
    public:
    void InThongTinSach();
    void MuonSach();
    void TraSach();
}