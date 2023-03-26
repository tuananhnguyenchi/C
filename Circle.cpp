#include <stdio.h>
#include <stdint.h>
#define PI 3.14

class Circle
{
    private:
    uint16_t radius;
    public:
    Circle(const uint16_t Radius);
    void setRadius(const uint16_t Radius);
    uint16_t getRadius();
    double getArea();
    double getPerimeter();
    void Display();
};

Circle::Circle(const uint16_t Radius)
{
    radius=Radius;
}
void Circle::setRadius(const uint16_t Radius)
{
     radius=Radius;
}
uint16_t Circle::getRadius()
{
    return radius;
}
double Circle::getArea()
{
    return PI*radius*radius;
}
double Circle::getPerimeter()
{
    return PI*2*radius;
}
void Circle::Display()
{
    printf("Preimeter is: %f",getPerimeter());
    printf("\n");
    printf("Area is : %f ",getArea());
}
int main(int argc, char const *argv[])
{
   Circle H={5};
    H.Display();
}
