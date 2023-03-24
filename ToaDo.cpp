#include<stdio.h>
#include<string.h>
#include<vector>
#include <stdint.h>

class Diem
{
    private:
     uint8_t tungDo;
     uint8_t hoanhDo;
    public;
      Diem(uint8_t y,uint8_t x);
      uint8_t getTungDo();
      uint8_t getHoangDo();
      void setTungDo(uint8_t x);
      void setHoanhDo(uint8_t y);
};
class NhieuDiem
{
    public:
    uint32_t khoangCach(Diem d1,Diem d2);
    uint32_t dienTich(Diem d1,Diem d2,Diem d3);
}