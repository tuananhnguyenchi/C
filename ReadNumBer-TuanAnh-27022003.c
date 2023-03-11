// Nguyen chi tuan anh

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct
{
  uint8_t size;
  uint8_t *fistAddress;
}TypeArray;

// step 1:program to print out digits
TypeArray *ConVertNumBer(uint32_t num)
{
    uint8_t i = 0, j = 0;
    uint32_t temp = num;
    static TypeArray arr;
    while (temp > 0)
    {
        temp /=10;
        i++;
    }    
    arr.size = i;
    arr.fistAddress = (uint8_t*)malloc(sizeof(uint8_t)*i);
    while (num>0)
    {
        uint8_t temp = num%10;
        num = num / 10;
        arr.fistAddress[j] = temp;
        j++;
    }
    return &arr;
}
//
void ConVert_NumBer_To_Letter(uint8_t num)
{
  switch(num)
  {
    case 1:
        printf("MOT ");
            break;        
    case 2:
        printf("HAI ");
            break;        
    case 3:
        printf("BA ");
            break;        
    case 4:
        printf("BON ");
            break;            
    case 5:
        printf("NAM "); 
            break;               
    case 6:
        printf("SAU ");
            break;        
    case 7:
        printf("BAY ");
            break;        
    case 8:
        printf("TAM ");
            break;        
    case 9:
        printf("CHIN ");                              
        break;
    default:         printf(" ");  
        break;
  }
}
void ReadUnit(uint8_t num)
{
  switch(num)
  {
    case 10:
        printf("ty ");
        break;
      case 9:
        printf("tram trieu ");
        break;
      case 8:
        printf("chuc trieu");
        break;
      case 7:
        printf( "trieu ");
        break;    
      case 6:  
        printf( "tram nghin ");
        break;
      case 5:
        printf( "chuc nghin ");
        break;
      case 4:
        printf( "nghin " );
        break;
      case 3:
        printf( "tram " );
        break;
      case 2:
        printf( "muoi " );
        break;
      default :
        printf("");
        break;
  }
}
void ReadNumBer(TypeArray *ptr)
{
     for (int index = ptr->size - 1; index >=0; index--)  
      {
       if(ptr->fistAddress[index]==0)
       {     uint8_t k=0;
              for(uint8_t i=0;i<=index;i++)
              {
                 k+=ptr->fistAddress[i];
              }
              if(k==0)
              {
                while(index%3!=0)
                {
                   index--;
                }
                ReadUnit(index+1);
                break;
              }
       }
       if(index%3==0)
       {
         
         if(ptr->fistAddress[index]==0)
         {
              ReadUnit(index+1);
         }
         else
         {
              if(ptr->fistAddress[index]==5)
              {
                if(index==(ptr->size-1)||(index==0))
                 {
                  ConVert_NumBer_To_Letter(ptr->fistAddress[index]);
                  ReadUnit(index+1);
                     
                  }
                else 
                {
                     printf("lam");
                 }
              }
              else
              {
              ConVert_NumBer_To_Letter(ptr->fistAddress[index]);
              ReadUnit(index+1);
              }
         }
       }
       if((index==2)||(index%3==2))
       {
              if(ptr->fistAddress[index]!=0)
              {
                  ConVert_NumBer_To_Letter(ptr->fistAddress[index]);
                  printf("tram"); 
              }
       }
       if((index==1)||(index%3==1))
       {
             if(ptr->fistAddress[index]!=0)
             {
              if(ptr->fistAddress[index]==1)
              {
                     printf("MUOI");// muoi
              }
              else
              {
                     ConVert_NumBer_To_Letter(ptr->fistAddress[index]);
                     printf("muoi");
              }
             }
             else
             {
              if(ptr->fistAddress[index+1]!=0)
              {
                     printf("linh");
              }
             }
       }
       if(index==0)
       {
              break;
       }
        
       }
   
}
int main(int argc, char const *argv[])
{
    TypeArray *ptr ;
    ptr=ConVertNumBer(24400000);
    //printf("%d",(ptr->fistAddress[7]));
    ReadNumBer(ptr);
    
}
