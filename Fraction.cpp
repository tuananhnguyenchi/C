/*Tạo một lớp phân số với các thuộc tính tử số và mẫu số và các phương
thức để tính toán các phép tính toán cơ bản như cộng, trừ, nhân và
chia*/
#include <stdio.h>
#include <stdint.h>

class Fraction
{
    private:
     uint16_t numerator;
     uint16_t denominator;
    public:
    
     void inputFraction();
     uint16_t getNumerator() ;
     uint16_t getDeniminator() ;
     void setNumeator(const uint16_t inputNumerator);
     void setDenominator(const uint16_t inputDenominator);
     void outputFraction();
};
void Fraction::inputFraction()
{

     printf("Enter numerator:");
     scanf("%d",&numerator);
     printf("Enter deniminator:");
     scanf("%d",&denominator);
 
}
//
uint16_t Fraction::getNumerator() 
{  
    
     return numerator;
}
//
uint16_t Fraction::getDeniminator() 
{
     return denominator;
}
void Fraction::setNumeator(const uint16_t inputNumerator)
{
    numerator=inputNumerator;
}
void Fraction::setDenominator(const uint16_t inputDenominator)
{
  denominator=inputDenominator;
}
void Fraction::outputFraction()
{
    printf("%d/%d",numerator,denominator);
}
//====================================================//

class Math
{
   private:
    enum state
    {
        ADD=1,
        SUB,
        MUL,
        DIV
    };
   public:
    Math();
    uint16_t MinComMul(uint16_t number1,uint16_t number2);//Find the least common multiple
    void Add();
    void Sub();
    void Mul();
    void Div();
};

Math::Math()
{
    while(true)
    {
        uint8_t select;
        do 
        {
            printf("1.Addition\n");
            printf("2.Subtraction\n");
            printf("3.Multiplication\n");
            printf("4.Division\n");
            printf("5.Exit\n");
            printf("\n");
            printf("Enter the selection:");
            scanf("%d",&select);
            switch(select)
            {
                case ADD:
                  Add();
                  break;
                case SUB:
                  Sub();
                  break;
                case MUL:
                  Mul();
                  break;
                case DIV:
                  Div();
                  break;
                default:
                 break;
            }

        }while(select!=5);
    }
}
//Find the least common multiple
uint16_t Math::MinComMul(uint16_t number1,uint16_t number2)
{
    if(number1>number2)
    {
        uint16_t Max=number1*number2;
        for(uint16_t i=number1;i<Max;i=+number1)
        {
            if((i%number1==0) &&(i%number2==0))
            {
                return i;
            }
        }
    }
    if(number1<number2)
    {
        uint16_t Max=number1*number2;
        for(uint16_t i=number2;i<Max;i=+number2)
        {
            if((i%number1==0) &&(i%number2==0))
            {
                return i;
            }
        } 
    }
    if(number1==number2)
    {
        return number1;
    }
}

void Math::Add()
{
    uint16_t commonDenomintor;
    float commonNumerator;
    printf("Enter the fist fraction:\n");
    Fraction fraction1;
    fraction1.inputFraction();
    printf("Enter the second fraction:\n");
    Fraction fraction2;
    fraction2.inputFraction();
  
    commonDenomintor=MinComMul(fraction1.getDeniminator(),fraction2.getDeniminator());
    commonNumerator=((commonDenomintor/fraction1.getDeniminator())*fraction1.getNumerator())+((commonDenomintor/fraction2.getDeniminator())*fraction2.getNumerator());
    printf("The result of the calculation is %d/%d",commonNumerator,commonDenomintor);
    printf("\n");
}
void Math::Sub()
{
    uint16_t commonDenomintor;
    uint16_t commonNumerator;
    printf("Enter the fist fraction:\n");
    Fraction fraction1;
    fraction1.inputFraction();
    printf("Enter the second fraction:\n");
    Fraction fraction2;
    fraction2.inputFraction();
    uint16_t number1=fraction1.getDeniminator();
    uint16_t number2=fraction2.getDeniminator();
    commonDenomintor=MinComMul(number1,number2);
    commonNumerator=((commonDenomintor/fraction1.getDeniminator())*fraction1.getNumerator())-((commonDenomintor/fraction2.getDeniminator())*fraction2.getNumerator());
    printf("The result of the calculation is %d/%d",commonNumerator,commonDenomintor); 
    printf("\n");
}
void Math::Mul()
{
    float commonDenomintor;
    uint16_t commonNumerator;
    printf("Enter the fist fraction:\n");
    Fraction fraction1;
    fraction1.inputFraction();
    printf("Enter the second fraction:\n");
    Fraction fraction2;
    fraction2.inputFraction();
    commonNumerator=fraction1.getNumerator()*fraction2.getNumerator();
    commonDenomintor=fraction1.getDeniminator()*fraction2.getDeniminator();
    printf("The result of the calculation is %f/%d",commonNumerator,commonDenomintor); 
    printf("\n");
}
void Math::Div()
{
    float commonDenomintor;
    float commonNumerator;
    printf("Enter the fist fraction:\n");
    Fraction fraction1;
    fraction1.inputFraction();
    printf("Enter the second fraction:\n");
    Fraction fraction2;
    fraction2.inputFraction();
    commonNumerator=fraction1.getNumerator()/fraction2.getNumerator();
    commonDenomintor=fraction1.getDeniminator()/fraction2.getDeniminator();
    printf("The result of the calculation is %f/%d",commonNumerator,commonDenomintor); 
    printf("\n");
}

int main()
{
 Math m1;

}
