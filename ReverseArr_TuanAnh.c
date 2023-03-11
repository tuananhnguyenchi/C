#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>

//
typedef struct 
{
   uint8_t *fistAddress;
   uint8_t size;
}
Array;
//ham dem dau cach va chi so cua dau cach trong chuoi
Array *Count(char arr[])
{
   static Array ptr;
   ptr.size=0;
   ptr.fistAddress = (uint8_t*)malloc(sizeof(uint8_t)*ptr.size);
   uint8_t i=0;
   while(arr[i]!='\0')
   {
      if((arr[i]==0x20)||(arr[i]==0x2E))
      {
         ptr.size++;
         ptr.fistAddress[ptr.size-1]=i;
      }
      i++;
   }
   //i++;
   ptr.size++;
   ptr.fistAddress[ptr.size-1]=i;// lua vi tri cuoi cung cua mang
   return &ptr;
}
//
void ReverseArr(char arr[])
{
   Array *ptr2;
   ptr2=Count(arr);
   for(uint8_t i=ptr2->size-1;i>=0;i--)
   {
      if(i==0)
      {
         for(uint8_t j=0;j<(ptr2->fistAddress[i]);j++)
         {
            printf("%c",arr[j]);
         }
         break;
      }
      // in từng chữ ra 1
      for(uint8_t j=(ptr2->fistAddress[i-1])+1;j<ptr2->fistAddress[i];j++)
      {
         printf("%c",arr[j]);
      }
      if(arr[ptr2->fistAddress[i-1]]==0x2E) // dau cham
      {
         printf(".");
      }
      else
      {
      printf(" ");
      }
   }
   //free(ptr2); 
}
//viet chu cai dau cau in hoa
void PrintA(char arr[])
{
   Array *ptr3;
   ptr3=Count(arr);
  //printf("%d",ptr3->fistAddress[ptr3->size]);
   for(uint8_t i=0;i<ptr3->fistAddress[ptr3->size-1];i++)
   {
     if(i==0)
     {
      if(arr[i]>=97)
      {
         printf("%c",(arr[i]-32));
      }
      else
      {
         printf("%c",arr[i]);
      }
     }
     else
     {
      if(arr[i-1]==0x2E)
      {
         if(arr[i]>=97)
      {
         printf("%c",(arr[i]-32));
      }
      else
      {
         printf("%c",arr[i]);
      }
      }
      else
      {
         printf("%c",arr[i]);
      }
     }
   }
   //free(ptr3); 
}
//In hoa toan bo
void PrinABC(char arr[])
{
   Array *ptr4;
   ptr4=Count(arr);
  for(uint8_t i=0;i<ptr4->fistAddress[ptr4->size-1];i++)
   {
      if(arr[i]>=97)
      {
        printf("%c",(arr[i]-32));  
      }
      else
      {
       printf("%c",arr[i]);
      }
   }
  // free(ptr4); 
}
// In thuong toan bo
void Printabc(char arr[])
{
   Array *ptr5;
   ptr5=Count(arr);
  for(uint8_t i=0;i<ptr5->fistAddress[ptr5->size-1];i++)
   {
      if((arr[i]==0x20)||(arr[i]==0x2E))
      {
        printf("%c",arr[i]); 
      }
      else
      {
      if(arr[i]<97)
      {
         printf("%c",(arr[i]+32)); 
      }
      else
      {
       printf("%c",arr[i]);
      }
      }
   }
}
int main(int argc,char const *argv[])
{
   char arr[]="What are do you.tuan Anh.from Ha Tinh";
  // printf("%c",(arr[2]-32));
   printf("Dao chuoi:\n");
   ReverseArr(arr);// dao chuoi
   printf("\n");
   printf("In hoa chu cai dau tien chuoi:\n");
   PrintA(arr);// in hoa chu cai dau tien
   printf("\n");
   printf("In hoa toan bo chuoi:\n");
   PrinABC(arr);// in hoa toan bo
   printf("\n");
   printf("In thuong toan bo chuoi:\n");
   Printabc(arr);// in thuong

   //printf("%d\n",sizeof(arr));
  // Array *ptr3;
   //ptr3=Count(arr);
   //printf("%d",ptr3->size);
   //printf("%d",(ptr3->fistAddress[8]));
   //for(uint8_t i=0;i<ptr3->size;i++)
   //{
      //printf("%d",(ptr3->fistAddress[ptr3->size]));
   //}
   //printf("%c",*(ptr3->fistAddress+1));
   
  // PrintArr(ptr3);
  
}