//nguyễn chí tuấn anh
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <cstring>
using namespace std;
class Time
{
    private:
     uint8_t hour;
     uint8_t minute;
    public:
     void input();
     uint8_t getHour();
     uint8_t getMinute();
     void setHour(const uint8_t inputHour);
     void setMinute(const uint8_t inputMinute);
     void output();
};
void Time::input()
{
   
    printf("Enter the hour:");
    scanf("%d",&hour);
    while ((hour<0)||(hour>24))
    {
        printf("Erro.Please re-enter.\n");
        printf("Enter the hour:");
        scanf("%d",&hour);
    }
    
    printf("Enter the minute:");
    scanf("%d",&minute);
    while ((minute<0)||(minute>60))
    {
       printf("Erro.Please re-enter.\n");
       printf("Enter the minute:");
       scanf("%d",&minute);
    }
    
}
uint8_t Time::getHour()
{
    return hour;
}
uint8_t Time::getMinute()
{
    return minute;
}
void Time::setHour(const uint8_t inputHour)
{
    hour=inputHour;
}
void Time::setMinute(const uint8_t inputMinute)
{
    minute=inputMinute;
}
void Time::output()
{
    printf("%s:%s",hour,minute);
}
//============================================//
class Flight
{
    private:
    char id[10];
    char origin[30];
    char  destination[30];
    Time departureTime;
    Time arrivalTime;
    uint32_t availableSeats;
    public:
     Flight(const char inputOrigin[],const char inputDestination[],const Time inputDepartureTime,const Time inputArrivalTime,const uint32_t inputAvailableSeats);
     char* getID();
     char* getOrigin();
     char* getDestination();
     Time getDepartureTime();
     Time getArrivalTime();
     uint32_t getAvilableSeats();
     void setOrigin(const char inputOrigin[]);
     void setDestination(const char inputDestination[]);
     void setDepartureTime(const Time inputDepartureTime); 
     void setArrivalTime(const Time inputArrivalTime);
     void setAvailableSeats(const uint32_t inputAvailableSeats);

};

Flight::Flight(const char inputOrigin[],const char inputDestination[],const Time inputDepartureTime,const Time inputArrivalTime,const uint32_t inputAvailableSeats)
{
   static uint8_t count=1;
   count++;
   char str2[8]= " NCTA ";
   char str1[5];
   sprintf(str1, "%d\n", count);
   strcat(str2, str1);
   strcpy(id,str2);
   strcpy(origin,inputOrigin);
   strcpy(destination,inputDestination);
   departureTime=inputDepartureTime;
   arrivalTime=inputArrivalTime;
   availableSeats=inputAvailableSeats;
}
char* Flight::getID()
{
    return id;
}
char* Flight::getOrigin()
{
    return origin;
}
char* Flight::getDestination()
{
    return destination;
}
Time Flight::getDepartureTime()
{
    return departureTime;
}
Time Flight::getArrivalTime()
{
    return arrivalTime;
}
uint32_t Flight::getAvilableSeats()
{
    return availableSeats;
}
void Flight::setOrigin(const char inputOrigin[])
{
     strcpy(origin,inputOrigin);
}
void Flight::setDestination(const char inputDestination[])
{
      strcpy(destination,inputDestination);
}
void Flight::setDepartureTime(const Time inputDepartureTime)
{
     departureTime=inputDepartureTime;
}
void Flight::setArrivalTime(const Time inputArrivalTime)
{
     arrivalTime=inputArrivalTime;
}
void Flight::setAvailableSeats(const uint32_t inputAvailableSeats)
{
     availableSeats=inputAvailableSeats;
}
//=================================================================//
class Booking
{
    private:
     uint8_t idBooking;
     char customerName[30];
     char flightId[30];
     uint16_t seatNumber;
    public:
     Booking(const char inputCustomeName[],const char inputFlightId[],const uint16_t inputSeatNumber);
     uint8_t getID();
     char* getCustomerName();
     char* getFlightId();
     uint16_t getSeatNumber();
     void setCustomerName(const char inputCustomerName[]);
     void setFlightId(const char inputCustomerName[]);
     void setSeatNumber(const uint16_t inputSeatNumber);
};
Booking::Booking(const char inputCustomeName[],const char inputFlightId[],const uint16_t inputSeatNumber)
{
   strcpy(customerName,inputCustomeName);
   strcpy(flightId,inputFlightId);
   seatNumber=inputSeatNumber;
   static uint8_t idBooking=100;
   idBooking++;
}
uint8_t Booking::getID()
{
    return idBooking;
}
char* Booking::getCustomerName()
{
    return customerName;
}
char* Booking::getFlightId()
{
    return flightId;
}
uint16_t Booking::getSeatNumber()
{
    return seatNumber;
}
void Booking::setCustomerName(const char inputCustomerName[])
{
     strcpy(customerName,inputCustomerName);
}
void Booking::setFlightId(const char inputFlightId[])
{
       strcpy(flightId,inputFlightId);
}
void Booking::setSeatNumber(const uint16_t inputSeatNumber)
{
     seatNumber=inputSeatNumber;
}


//=======================================================//
class Airline
{
    private:
      enum state
        {
            ADD = 1,
            REMOVE,
            SEARCH,
            GET,
            BOOK,
            CANCEL,
            VIEW
        }state;
     vector<Flight> Database_List_Fight;
     vector<Booking> Database_List_Boking;
    public:
      Airline();
      void addFlight();
      void removeFlight();
      void searchFlights();
      void getFlightDetails();
      void bookFlight();
      void cancelBooking();
      void viewBooking();
     
};
Airline::Airline()
{
     while (true)
    {
        printf("\t\t\t* Welcome to Airline *\n");
        printf("1. Add Flight\n");
        printf("2. Remove Flight\n");
        printf("3. Search Flight\n");
        printf("4. Get Flight Detail\n");
        printf("5. Book Flight\n");
        printf("6. Cancel Flight\n");
        printf("7. View Booking\n");
        printf("Enter your choice: ");
        uint8_t state = 0;
        scanf("%d", &state);
        switch (state)
        {
             
        case ADD:
             uint8_t key1;
          do{
        
          printf("** 1.ADD **\n");
          printf("** 2.exit           **\n");
          printf("\n");
          printf("Enter the selection:");
          scanf("%d",&key1);
         if(key1==1)
         {
            addFlight();
         } 
         if((key1!=1)&&(key1!=2))
         {
          printf("Errol\n");
         }    
         }while(key1!=2);
         break;
        case REMOVE:
           uint8_t key2;
          do{
        
          printf("** 1.REMOVE **\n");
          printf("** 2.exit **\n");
          printf("\n");
          printf("Enter the selection:");
          scanf("%d",&key2);
         if(key2==1)
         {
           removeFlight();
         } 
         if((key2!=2)&&(key2!=2))
         {
          printf("Errol\n");
         }    
         }while(key2!=2);
         break;
        case SEARCH:
          uint8_t key3;
          do{
        
          printf("** 1.SEARCH **\n");
          printf("** 2.exit           **\n");
          printf("\n");
          printf("Enter the selection:");
          scanf("%d",&key3);
         if(key3==1)
         {
            removeFlight();
         } 
         if((key3!=1)&&(key3!=2))
         {
          printf("Errol\n");
         }    
         }while(key3!=2);
         break;
        case GET:
            uint8_t key4;
          do{
        
          printf("** 1.GET **\n");
          printf("** 2.exit           **\n");
          printf("\n");
          printf("Enter the selection:");
          scanf("%d",&key4);
         if(key4==1)
         {
            getFlightDetails();
         } 
         if((key4!=1)&&(key4!=2))
         {
          printf("Errol\n");
         }    
         }while(key4!=2);
         break;
        case BOOK:
             uint8_t key5;
          do{
        
          printf("** 1.BOOK **\n");
          printf("** 2.exit           **\n");
          printf("\n");
          printf("Enter the selection:");
          scanf("%d",&key5);
         if(key5==1)
         {
           bookFlight();
         } 
         if((key5!=1)&&(key5!=2))
         {
          printf("Errol\n");
         }    
         }while(key5!=2);
         break;
        case CANCEL:
             uint8_t key6;
          do{
        
          printf("** 1.Cancel **\n");
          printf("** 2.exit           **\n");
          printf("\n");
          printf("Enter the selection:");
          scanf("%d",&key6);
         if(key6==1)
         {
           cancelBooking();
         } 
         if((key6!=1)&&(key6!=2))
         {
          printf("Errol\n");
         }    
         }while(key6!=2);
         break; 
        case VIEW:
         uint8_t key7;
          do{
          printf("** 1.VIEW **\n");
          printf("** 2.exit    **\n");
          printf("\n");
          printf("Enter the selection:");
          scanf("%d",&key7);
         if(key7==1)
         {
           viewBooking();
         } 
         if((key4!=1)&&(key7!=2))
         {
          printf("Errol\n");
         }    
         }while(key7!=2);
         break; 

          

        }
    }

}
void Airline::addFlight()
{
    char id[10];
    char origin[30];
    char  destination[30];
    Time departureTime;
    Time arrivalTime;
    uint32_t availableSeats;
    printf("   ADD FILGHT:\n  ");
    printf("Enter the origin\n");
    scanf("%s", origin);
    printf("Enter the destination\n");
    scanf("%s", destination);        
    printf("Enter the departure time\n");
    scanf("%hhd", &departureTime);        
    printf("Enter the arrival time\n");
    arrivalTime.input();  
    printf("Enter the available seats\n");
    scanf("%hd", &availableSeats);
    Flight flight(origin,destination, departureTime, arrivalTime, availableSeats);
    Database_List_Fight.push_back(flight);
}
void Airline::removeFlight()
{   
    char inputId[10];
    printf("Enter ID Flight:");
    scanf("%s",inputId);
    bool found=false;
    for(uint8_t i=0;i<Database_List_Fight.size();i++)
    {
        
       if(strcmp(inputId, Database_List_Fight[i].getID())==0)
       {
        Database_List_Fight.erase(Database_List_Fight.begin() + i);
         found = true;
         break;
       }
    }
    if(!found) printf("Could not find id ");
}
void Airline::searchFlights()
{
    char origin[30];
    char  destination[30];
    printf("Enter the origin\n");
    scanf("%s", origin);
    printf("Enter the destination\n");
    scanf("%s", destination); 
    bool found=false; 
    for(uint8_t i=0;i<Database_List_Fight.size();i++)
    {
        
       if((strcmp(origin, Database_List_Fight[i].getOrigin())==0)&&(strcmp(destination, Database_List_Fight[i].getDestination())==0))
       {
         printf("ID:%s",Database_List_Fight[i].getID());
         printf("From %s to %s ",Database_List_Fight[i].getOrigin(),Database_List_Fight[i].getDestination());
         printf("Departure Time:");
         Database_List_Fight[i].getDepartureTime().output();
         printf("Arrval Time:");
         Database_List_Fight[i].getDepartureTime().output();
         printf("Available Seat: ",Database_List_Fight[i].getAvilableSeats());
         found = true;
         break;
       }
    }
    if(!found) printf("No flight found!\n\n");
}
void Airline::getFlightDetails()
{
    char inputFlightId[10];
    bool found=false; 
    printf("Enter the flight id:");
    scanf("%d",inputFlightId);
    for(uint8_t i=0;i<Database_List_Fight.size();i++)
    {
        if(strcmp(Database_List_Fight[i].getID(),inputFlightId)==0)
        {
         printf("ID:%s",Database_List_Fight[i].getID());
         printf("From %s to %s ",Database_List_Fight[i].getOrigin(),Database_List_Fight[i].getDestination());
         printf("Departure Time:");
         Database_List_Fight[i].getDepartureTime().output();
         printf("Arrval Time:");
         Database_List_Fight[i].getDepartureTime().output();
         printf("Available Seat: ",Database_List_Fight[i].getAvilableSeats());
         found = true;
         break;
        }
    }
     if(!found) printf("No flight found!\n\n");

}
void Airline::bookFlight()
{
    bool found=false;
    char inputCustomerName[30];
    char inputFlightId[30];
    uint32_t inputSeatNumber;
    printf("Enter the cusomer name:");
    scanf("%s",inputCustomerName);
    printf("Enter the fligth id:");
    scanf("%s",inputFlightId);
    printf("Enter the seat number:");
    scanf("%d",&inputSeatNumber);
    Booking newBooking(inputCustomerName,inputFlightId,inputSeatNumber);
    for(uint8_t i=0;i<Database_List_Fight.size();i++)
    {
         if(strcmp(Database_List_Fight[i].getID(),inputFlightId)==0)
        {
            found=true;
            if(Database_List_Fight[i].getAvilableSeats()>0)
            {
               if(Database_List_Boking.size()==0)
               {
                 Database_List_Fight[i].setAvailableSeats(Database_List_Fight[i].getAvilableSeats()-1);
                 Database_List_Boking.push_back(newBooking);
                  printf("Booking Successful!\n\n");
                    break;
               }
               else
               {
                bool check=false;
                for(uint8_t i=0;i<Database_List_Boking.size();i++)
                {
                    
                    if(strcmp(Database_List_Boking[i].getFlightId(),inputFlightId)==0)
                    {
                       
                        if(Database_List_Boking[i].getSeatNumber()==inputSeatNumber)
                        {
                            check=true;
                              printf("That seat has been booked. Please chose another seat or flight!\n\n");
                                break; 
                        }
                    }
                }
                 if(!check)
                 {
                    Database_List_Fight[i].setAvailableSeats(Database_List_Fight[i].getAvilableSeats()-1);
                  Database_List_Boking.push_back(newBooking);
                  printf("Booking Successful!\n\n");   
                 }
               }
            }
           
        }
        
    }
    if(!found)
    {
     printf("Sorry, there are no more available seats on this flight. Please chose another flight\n\n");
    }      
    
}
void Airline::cancelBooking()
{
     uint8_t inputIdBooking;
     char tempFlightID[30];
     bool found=false;
     printf("Enter the ID boking:");
     scanf("%d",&inputIdBooking);
     for(uint8_t i=0;i<Database_List_Boking.size();i++)
     {
        if(inputIdBooking==Database_List_Boking[i].getID())
        {
          found=true;
          strcpy(tempFlightID,Database_List_Boking[i].getFlightId());
          Database_List_Boking.erase(Database_List_Boking.begin()+i);
        }
     }
     if(found)
     {
           printf("No booking found!\n\n");
     }
     else
     {
        for(uint8_t i=0;i<Database_List_Fight.size();i++)
        {
            if(strcmp(Database_List_Fight[i].getID(),tempFlightID)==0)
            {
                Database_List_Fight[i].setAvailableSeats(Database_List_Fight[i].getAvilableSeats()+1);
                break;
            }
        }
          printf("Canceling Booking Successful!\n\n");
     }
}
void Airline::viewBooking()
{
    char inputCustomerName[30];
    bool found=false;
    printf("Enter the customer name:");
    scanf("%s",inputCustomerName);
    for(uint8_t i=0;i<Database_List_Boking.size();i++ )
    {
    if(strcmp(Database_List_Boking[i].getCustomerName(),inputCustomerName)==0)
    {
        found=true;
      printf("Customer name:",Database_List_Boking[i].getCustomerName());
      printf("ID :",Database_List_Boking[i].getID());
      printf("Flight ID:",Database_List_Boking[i].getFlightId());
      printf("Seat Number:",Database_List_Boking[i].getSeatNumber());

    }
}
  if(!found) printf("No booking found!\n\n");
}

//====================================================================//
int main(int argc, char const *argv[])
{
    


Airline al;
    return 0;

}
 
