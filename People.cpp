/*Tạo một lớp người với các thuộc tính tên, tuổi và địa chỉ, và các
phương thức để in thông tin của người đó và tính tuổi của người đó.*/
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <stdbool.h>
#include <string.h>

class People
{
    private:
    char Name[20];
    uint8_t Age;
    char Address[20];
    public:
    People();
    char* getName();
    uint8_t getAge();
    char* getAddress();
    void setName(const char inputName[]);
    void setAge(const uint8_t inputAge);
    void setAddress(const char inputAddress[]);
    void outputInformationPeople();
};
People::People()
{
    printf("Enter information:\n");
    printf("Enter name:");
    fflush(stdin);
    gets(Name);
    printf("Enter age:");
    scanf("%d",&Age);
    printf("Enter Address");
    fflush(stdin);
    gets(Address);
}
char *People::getName()
{
    return Name;
}
uint8_t People::getAge()
{
    return Age;
}
char* People::getAddress()
{
    return Address;
}
void People::setName(const char inputName[])
{
    strcpy(Name,inputName);
}
void People:: setAge(const uint8_t inputAge)
{
   Age=inputAge;
}
void People::setAddress(const char inputAddress[])
{
    strcpy(Address,inputAddress);
}
void People::outputInformationPeople()
{
    printf("Information:\n");
    printf("Name: %s",Name);
    printf("\n");
    printf("Age: %d",Age);
    printf("\n");
    printf("Address: %s",Address);

}
int main()
{
    People p1;
    p1.outputInformationPeople();
}
