#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <conio.h>
using namespace std;

class Animal
{
    private:
    uint8_t ID;
    char animalName[20];
    uint8_t animalAge;
    uint16_t animalWeigth;
    public:
    Animal();
    Animal(const char inputAnimalName[], const  uint8_t inputAnimalAge, const uint16_t inputAnimalWeigth);
    uint8_t getID();
    char* getAnimalName() ;
    uint8_t getAnimalAge();
    uint16_t getAnimalWeigth();
    void setAnimalName(const char inputAnimalName[]);
    void setAnimalAge(const  uint8_t inputAnimalAge);
    void setAnimalWeigth(const uint16_t inputAnimalWeigth);
};
Animal::Animal(const char inputAnimalName[], const  uint8_t inputAnimalAge, const uint16_t inputAnimalWeigth)
{
     static uint8_t l_id = 100;
     ID = l_id;
     l_id++;
    strcpy(animalName, inputAnimalName);
    animalAge=inputAnimalAge;
    animalWeigth=inputAnimalWeigth;
}
uint8_t Animal::getID()
{
    return ID;
}
char* Animal::getAnimalName() 
{
    return animalName;
}
uint8_t Animal::getAnimalAge()
{
    return animalAge;
}
uint16_t Animal::getAnimalWeigth()
{
    return animalWeigth;
}
void Animal::setAnimalName(const char inputAnimalName[])
{
     strcpy(animalName, inputAnimalName);
}
void Animal::setAnimalAge(const uint8_t inputAnimalAge)
{
    animalAge=inputAnimalAge;
}
void Animal::setAnimalWeigth(const uint16_t inputAnimalWeigth)
{
    animalWeigth=inputAnimalWeigth;
}

//
class Animals 
{
    private:
    vector<Animal> Database;
     enum state
        {
            INPUT = 1,
            AGE,
            WEIGTH,
            REMOVE,
            EXIT,
        }state;
    public:
    Animals();
    void InputAnimalsImformation();
    void CompareAge();
    void CompareWeigth();
    void removeAnimals();
};
/*Contractor*/
Animals::Animals()
{
    while(true)
    {
        uint8_t select;
        printf("****************************************************************\n");
        printf("*** 1.Enter animal imformtion to campare.                     ***\n");
        printf("*** 2.List sorted by age of animals from lowest to highest    ***\n");
        printf("*** 3.List sorted by weigth of animals from lowest to highest ***\n");
        printf("*** 4.Remove the animal name from the list                    ***\n");
        printf("*** 5.Exit                                                    ***\n");
        printf("*****************************************************************\n");
        printf("\n");
        printf("Enter your selection:");
        scanf("%d",&select);
        do
        {  
            switch(select)
            {
            case INPUT:
              uint8_t inputSelect;
              do
              {
               printf("1.Continue enter new animal\n");
               printf("2.Exit\n");
               printf("Enter your selection:");
               scanf("%d",&inputSelect);
               if(inputSelect==1)
                {
                 InputAnimalsImformation();
                }
               if((inputSelect!=2)&&(inputSelect!=1))
                {
                   printf("Error");
                }
              } 
			  while(inputSelect!=2);
               break;
            case AGE:
               uint8_t selectAge;
              do
              {
               CompareAge();
               printf("Enter 1 to exit:");
               scanf("%d",&selectAge); 
               if(selectAge!=1)
               {
                printf("Error.");
               }
              }while(selectAge!=1);
               //CompareAge();
               break;
            case WEIGTH:
               uint8_t selectWeigth;
              do
              {
               CompareWeigth();
               printf("Enter 1 to exit:");
               scanf("%d",&selectWeigth); 
               if(selectWeigth!=1)
               {
                printf("Error.");
               }
              }while(selectAge!=1);
               break;
            case REMOVE:
              uint8_t selectRemove;
              do
              {
               printf("\n");
               printf("1.Continue delete animal\n");
               printf("2.Exit\n");
               printf("Enter your selection:");
               scanf("%d",&selectRemove);
               if(selectRemove==1)
                {
                 removeAnimals();
                }
                if((selectRemove!=2)&&(selectRemove!=1))
                {
                    printf("Error.");
                }
              }while(selectRemove!=2);
              break;  
            case EXIT:
               break;
            default:
             printf("Error.");
             break;
            }
        }while(select!=5);
    }
}
/*Enter animal imformtion to campare*/
void Animals::InputAnimalsImformation()
{
    
     printf(" Enter the information of the  animal\n");
     char inputAnimalName[20];
     uint8_t inputAnimalAge;
     uint16_t inputAnimalWeigth;
     printf("Enter animal name: ");
     fflush(stdin);
     gets(inputAnimalName);
     printf("Enter animal age:");
     scanf("%d",&inputAnimalAge);
     printf("Enter animal weigth: ");
     scanf("%d",&inputAnimalWeigth);
     Animal animal(inputAnimalName, inputAnimalAge,inputAnimalWeigth);
     Database.push_back(animal);
   

}
/*List sorted by age of animals from lowest to highest*/
void Animals ::CompareAge()
{ 
  
    for(uint8_t i=0;i<Database.size();i++)
    {
      for(uint8_t j=1;j<Database.size();j++)
      {
        if(Database[i].getAnimalAge()>Database[j].getAnimalAge())
        {
            Animal Temp("",0,0);
            Temp=Database[i];
            Database[i]=Database[j];
            Database[j]=Temp;
        }
      }
    }
   printf("List sorted by age of animals from lowest to highest\n");
   printf(" ID    NAME      AGE     WIETH     \n");
   for(uint8_t i=0;i<Database.size();i++)
   {
    printf(" %d    %c       %d      %d        \n",Database[i].getID(),Database[i].getAnimalName(),Database[i].getAnimalAge(),Database[i].getAnimalWeigth());
   } 
}
/*List sorted by weigth of animals from lowest to highest */
void Animals:: CompareWeigth()
{
    for(uint8_t i=0;i<Database.size();i++)
    {
      for(uint8_t j=1;j<Database.size();j++)
      {
        if(Database[i].getAnimalWeigth()>Database[j].getAnimalWeigth())
        {
            Animal Temp("",0,0);
            Database[i]=Temp;
            Database[i]=Database[j];
            Database[j]=Temp;
        }
      }
    }
    printf("List sorted by weigth of animals from lowest to highest \n");
    printf(" ID    NAME      AGE     WIETH     \n");
    for(uint8_t i=0;i<Database.size();i++)
   {
     printf(" %d    %c        %d      %d        \n",Database[i].getID(),Database[i].getAnimalName(),Database[i].getAnimalAge(),Database[i].getAnimalWeigth());
   } 
}
void Animals::removeAnimals()
{
   printf("List animals:\n");
    printf(" ID    NAME      AGE     WIETH     \n");
   for(uint8_t i=0;i<Database.size();i++)
   {
    printf(" %d    %s        %d      %d        \n",Database[i].getID(),Database[i].getAnimalName(),Database[i].getAnimalAge(),Database[i].getAnimalWeigth());
   } 
    uint8_t inputID;
    printf(" Enter the animal ID to delete :");
    scanf("%d",&inputID);
    for (int i=0;i<Database.size();i++)
    {
        if (Database[i].getID() == inputID){
            Database.erase(Database.begin() + i);
        }
    }
}
int main(int argc, char const *argv[])
{
    Animals a;
}
