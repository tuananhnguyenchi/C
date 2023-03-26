#include <stdio.h>
#include <stdint.h>

class Rectangual
{
    private:
    uint16_t width;
    uint16_t length;
    public:
    Rectangual(const uint16_t Width,const uint16_t Length);
    void setWidth(const uint16_t Width);
    void  setLength(const uint16_t Length);
    uint16_t getWidth();
    uint16_t getLength();
    double getArea();
    double getPerimeter();
    void Checksquare();
    void Display();
};
Rectangual::Rectangual(const uint16_t Width,const uint16_t Length)
{
    width=Width;
    length=Length;   
}
void Rectangual::setWidth(const uint16_t Width)
{
   width=Width;
}
void Rectangual::setLength(const uint16_t Length)
{
  length=Length;
}
uint16_t Rectangual::getLength()
{
    return length;
}
uint16_t Rectangual::getWidth()
{
    return width;
}
double Rectangual::getArea()
{
    return length*width;
}
double Rectangual::getPerimeter()
{
    return length*width*2;
}
void Rectangual::Checksquare()
{
    if(width==length)
    {
        printf("It is square");
        
    }
    else printf("It is not square");
}
void Rectangual::Display()
{
    printf("Preimeter is: %f",getPerimeter());
    printf("\n");
    printf("Area is : %f ",getArea());
    printf("\n");
    Checksquare();
}
int main(int argc, char const *argv[])
{
    Rectangual H={5,5};
    H.Display();
}

