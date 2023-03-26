#include <stdio.h>
#include <stdint.h>
#include<math.h>
class Coordinates
{
    private:
    uint8_t pointX;
    uint8_t pointY;
    public:
    Coordinates(const uint8_t pointx,const uint8_t pointy);
    void setPointX(const uint8_t point_x);
    void setPointY(const uint8_t point_y);
    uint8_t getPointX();
    uint8_t getPointY();
};
Coordinates::Coordinates(const uint8_t pointx,const uint8_t pointy)
{  
    pointX=pointx;
    pointY=pointy;
    
}
void Coordinates::setPointX(const uint8_t point_x)
{
    pointX=point_x;
}
void Coordinates::setPointY(const uint8_t point_y)
{
    pointY=point_y;
}
uint8_t Coordinates::getPointX()
{
    return pointX;
}
uint8_t Coordinates::getPointY()
{
    return pointY;
}

class mathCoordinates
{
    public:
    mathCoordinates(Coordinates A,Coordinates B); //Calculate distance
    mathCoordinates(Coordinates A,Coordinates B,Coordinates C); //calculate area of ​​triangle
};
mathCoordinates::mathCoordinates(Coordinates A,Coordinates B)
{
 //kc=sqrt(double(d1.hd-d2.hd)*(d1.hd-d2.hd)+(d1.td-d2.td)*(d1.td-d2.td));
 //pow(x,y)	Trả về x mũ y.
 double distance;
 distance=sqrt(double(A.getPointX()-B.getPointX())*(A.getPointX()-B.getPointX())+(A.getPointY()-B.getPointY())*(A.getPointY()-B.getPointY()));
 printf("Khoang cach %lf",distance);
}
mathCoordinates::mathCoordinates(Coordinates A,Coordinates B,Coordinates C)
{
    //0.5|(*(X2-X1)*(Y3-Y1)-(X3-X1)*(y2-y1))|
    double acreage;
    acreage=(0.5*abs((B.getPointX()-A.getPointX())*(C.getPointY()-A.getPointY())-(C.getPointX()-A.getPointX())*(B.getPointY()-A.getPointY())));
    printf("Dien tich %f",acreage);
}
int main(int argc, char const *argv[])
{ 
   
   Coordinates A={3,2};
   //printf("%d",A.getPointX());
   Coordinates B={0,1};
   Coordinates C={1,5};
   mathCoordinates(A,B,C);
   printf("\n");
   mathCoordinates(A,B);
   
}