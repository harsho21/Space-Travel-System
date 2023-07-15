#include <bits/stdc++.h>
#include <vector>
#include<ctime>
#include <cstdlib>


int ticket_count=1;
using namespace std;
class Traveller;
class Ticket;

class planet{
    public:
    int position_x;
    int position_y;
    int position_z;
    string planet_Name;
    string atmosphere;
    string water;  
    int inhabitants;
    void getCoordinates(){
     cout<<planet_Name<< " coordinates are x:"<<position_x<<"y: "<<position_y<<"z: "<<position_z<<endl;
    }
    void getAtmosphere(){
     cout<<planet_Name<<" atmosphere is "<<atmosphere<<endl;
    }
    void getWater(){
        cout<<planet_Name<<" is made upof "<<water<< " water"<<endl;

    }
    void getinhabitants(){
        cout<<"There are "<<inhabitants<<" living in "<<planet_Name<<endl;

    }
};


class Traveller{
    int traveller_id;
    public:
       string name;
       int ID;
       vector<Ticket> list_of_tickets;
       void getName(){
        cout<<"The traveller name is:";
        cout<<name<<endl;


       }
       void getid(){
       cout<<"The Traveller ID is:";
        cout<<ID<<endl;

       }
     

};

class Commander:public Traveller{
    int authority;
    public:
       int experiance;
       int license_id;
       void set_auth(int auth){
        authority=auth;
       }
};

class Passenger:public Traveller{
     int validity;
};
class Astronaut: public Traveller{
    public:
      int experiance;
};

class Ticket:public Commander, public Passenger, public Astronaut {
    int price;
    public:
       int ticket_id;
       planet source_station;
       planet destination;
       int date,month,year;
       struct tm* booking_date;
       string traveller_name;

       void book_ticket(Traveller psg,planet planets[]){
          traveller_name=psg.name;
          ticket_id=ticket_count;
          ticket_count++;
          cout<<"Enter your source station: ";
          string station;
          cin>>station;
          string destin;
          cout<<"Enter your destination planet: ";
          cin>>destin;
          while(station==destin){
            cout<<"Source and destination cannot be same.Please  enter the destination again"<<endl;
            cin>>destin;
          }
         
          for(int i=0;i<3;i++){
            if(station==planets[i].planet_Name){
                source_station=planets[i];
            
            }
            else if(destin==planets[i].planet_Name){
                destination=planets[i];
            }
          }
         
          time_t tt;
          time(&tt);
          booking_date=localtime(&tt);
          cout<<"Enter your travel date in the format of dd/mm/yyyy: ";
          std::cin >> date; // read the day
          if ( std::cin.get() != '/' ){
            std::cout << "expected /\n";

          }
         std::cin >> month; // read the month
         if ( std::cin.get() != '/' ){
           std::cout << "expected /\n";
         }
         std::cin >> year; // read the year
          cout<<"Your Ticket id is: ";
          cout<<ticket_id<<"(Please remember your ticket id for future references)"<<endl;
          cout<<"Ticket_booked"<<endl;
          
       }
       
       
       
       void update_ticket(planet planets[], Ticket ticket){
          struct tm* current_date;
          time_t tt;
          time(&tt);
          current_date=localtime(&tt);
          if((((current_date->tm_year-ticket.year)*365)+((current_date->tm_mday-ticket.date))+((current_date->tm_mon-ticket.month)*30))>3650){
            cout<<"Your ticket is expired."<<endl;
          }
          else{
          ticket_id=ticket_count;
          cout<<"Enter your source station: ";
          string station;
          cin>>station;
          string destin;
          cout<<"Enter your destination planet: ";
          cin>>destin;
          while(station==destin){
            cout<<"Source and destination cannot be same.Please  enter the destination again"<<endl;
            cin>>destin;
           }
          for(int i=0;i<3;i++){
            if(station==planets[i].planet_Name){
                source_station=planets[i];
            
            }
            else if(destin==planets[i].planet_Name){
                destination=planets[i];
            }
          }
          cout<<"Enter your travel date in the format of dd/mm/yyyy: ";
          std::cin >> date; 
          if ( std::cin.get() != '/' ){
            std::cout << "expected /\n";

          }
         std::cin >> month; 
         if ( std::cin.get() != '/' ){
           std::cout << "expected /\n";
         }
         std::cin >> year;
          cout<<"Ticket_Updated"<<endl;
          
       }
       }
       void setprice(int tic_price){
        price=tic_price;
       }
       

       int  getprice(planet source_plantet,planet destin_planet , int month , int day , int year){
        time_t tt;
        time(&tt);
        struct tm *lt=localtime(&tt);
        int diff=(year-lt->tm_year)+(month-lt->tm_mon+1)+(day-lt->tm_mday);
        int k=60000000;
        int ticket_price=k/diff;
        return  ticket_price;
       }
       

       void cancel_ticket(planet planets[], Ticket ticket,Traveller psg){
         struct tm* current_date;
          time_t tt;
          time(&tt);
          current_date=localtime(&tt);
          if((((current_date->tm_year-ticket.year)*365)+((current_date->tm_mday-ticket.date))+((current_date->tm_mon-ticket.month)*30))>3650){
            cout<<"Your ticket is expired."<<endl;
          }
          else{
            for(int i=0;i<psg.list_of_tickets.size();i++){
                if(psg.list_of_tickets[i].ticket_id==ticket.ticket_id){
                    psg.list_of_tickets.erase(psg.list_of_tickets.begin()+(i-1),psg.list_of_tickets.begin()+i);
                }
            }
          }
       }

};


class SpaceTravelClass{
     vector<Passenger> list_of_travellers;
     int  astronaut_id;
     int commander_id; 
     public:
     planet initial_planet;
     planet final_planet;
     int date,month,year;

     public:
       void Add_travellers(Passenger pass){
        list_of_travellers.push_back(pass);
       }
       void list_travellers(){
        for(int a=0;a<list_of_travellers.size();a++){
            cout<<list_of_travellers[a].name<<endl;
        }
       }
       int getastronaut_id(){
        return astronaut_id;
       }
       int getcommander_id(){
       return commander_id;
       }
       void update_astro_id(int id){
        astronaut_id=id;
       }
       void update_commander_id(int id){
        commander_id=id;
       }
};



int main(){
    vector<Traveller> travellers;
    vector<Passenger> passenger;
    vector<Commander> commander;
    vector<Astronaut> astronaut;
    vector<Ticket> all_tickets;
    vector<SpaceTravelClass> stc;
    int id=1;
for(int i=0;i<11;i++){
    Passenger new_pass;
    string s= "passenger" + to_string(i+1);
	new_pass.name=s;
    new_pass.ID=id;
    id=id+1;
    passenger.push_back(new_pass);
}
for(int i=0;i<2;i++){
    Commander new_comm;
    string s="commander"+ to_string(i+1);
    new_comm.name=s;
    new_comm.ID=id;
    id=id+1;
    new_comm.set_auth(i+10);
    new_comm.license_id=i+20;
    new_comm.experiance=2*(i+1);
    commander.push_back(new_comm);
   

}
for(int i=0;i<2;i++){
    Astronaut new_astro;
    string s="astronaut"+ to_string(i+1);
    new_astro.name=s;
    new_astro.ID=id;
    id=id+1;
    new_astro.experiance=3*(i+1);
    astronaut.push_back(new_astro);
   

}

planet planets[3];
planet earth;
earth.position_x=0;
earth.position_y=0;
earth.position_z=0;
earth.planet_Name="earth";
earth.atmosphere="breathable";
earth.water="70%";
earth.inhabitants=80000000;
planets[0]=earth;

planet mars;
mars.position_x=5;
mars.position_y=7;
mars.position_z=12;
mars.atmosphere="non breathable";
mars.inhabitants=40000;
mars.water="2%";
mars.planet_Name="mars";
planets[1]=mars;

planet europa;
europa.planet_Name="europa";
europa.position_x=64;
europa.position_y=87;
europa.position_z=50;
europa.atmosphere="non breathable";
europa.water="40%";
europa.inhabitants=896465;
planets[2]=europa;


int func=0;
Traveller psg;
cout<<"type 1 if you want to get your name from your id."<<endl;
cout<<"type 2 if you want to get your id from your name."<<endl;
cout<<"Enter 3 to book a ticket"<<endl;
cout<<"Enter 4 to update a ticket."<<endl;
cout<<"Enter 5 to know planet details."<<endl;
cout<<"Enter 6 to find the ticket price"<<endl;
cout<<"Enter 7 if you are a commander and you want to know your upcoming travel details."<<endl;
cout<<"Enter 8 to cancel your ticket"<<endl;
cout<<"Enter 9 to view the space travels."<<endl;
cout<<"type -1 to clear all the details"<<endl;

while(func!=-1){
cin>>func;

if(func==1){
    cout<<"Enter your id:";
    int tr_id;
    cin>>tr_id;
    Traveller psg;
    int fl=0;
    for(int i=0;i<passenger.size();i++){
            
            if(passenger[i].ID==tr_id){
                fl=1;
                psg=passenger[i];
            }
    }
    for(int i=0;i<commander.size();i++){
            if(commander[i].ID==tr_id){
                fl=1;
                psg=commander[i];
            }
    }
    for(int i=0;i<astronaut.size();i++){
            if(astronaut[i].ID==tr_id){
                fl=1;
                psg=astronaut[i];
            }
    }
   if(fl==1){
    psg.getName();
   }
   else if(fl==0){
    cout<<"Your ID is not registered."<<endl;
   }
    
}
else if(func==2){
    cout<<"Enter your name:";
    string tr_name;
    cin>>tr_name;
   
    int fl=0;
    int size;
    int siz=tr_name.length();
    for(int i=0;i<passenger.size();i++){
            if(passenger[i].name==tr_name){
                fl=1;
                psg=passenger[i];
                break;
            }
    }
    for(int i=0;i<commander.size();i++){
            if(commander[i].name==tr_name){
                fl=1;
                psg=commander[i];
                break;
            }
    }
    for(int i=0;i<astronaut.size();i++){
            if(astronaut[i].name==tr_name){
                fl=1;
                psg=astronaut[i];
                break;
            }
    }
   if(fl==1){
    psg.getid();
   }
   else if(fl==0){
    cout<<"Your ID is not registered."<<endl;
   }
    
}

else if(func==3){
    string psg_name="";
    cout<<"Enter your name: ";
    cin>>psg_name;
    int id;
    int siz=psg_name.length();
    cout<<"Enter your id";
    int fl=0;
    cin>>id;
    for(int i=0;i<passenger.size();i++){
            if(passenger[i].name==psg_name && passenger[i].ID==id){
                fl=1;
                psg=passenger[i];
                break;
            }
    }
    for(int i=0;i<commander.size();i++){
            if(commander[i].name==psg_name && commander[i].ID==id){
                fl=1;
                psg=commander[i];
                break;
            }
    }
    for(int i=0;i<astronaut.size();i++){
            if(astronaut[i].name==psg_name && astronaut[i].ID==id){
                fl=1;
                psg=astronaut[i];
                break;
            }
}
if(fl==1){
    Ticket new_tic;
    new_tic.book_ticket(psg,planets);
    int price=new_tic.getprice(new_tic.source_station,new_tic.destination,new_tic.month,new_tic.date,new_tic.year);
    new_tic.setprice(price);
    psg.list_of_tickets.push_back(new_tic);
    int fl1=0;
    for(int t=0;t<stc.size();t++){
            Passenger pas;
            if(stc[t].initial_planet.planet_Name==new_tic.source_station.planet_Name && stc[t].final_planet.planet_Name==new_tic.destination.planet_Name && stc[t].date==new_tic.date && stc[t].month==new_tic.month && stc[t].year==new_tic.year){
               for(int k=0;k<passenger.size();k++){
                   if(passenger[k].name==new_tic.traveller_name){
                    pas=passenger[k];
                    break;
            }
           
         }
               stc[t].Add_travellers(pas);
               cout<<" A new passnger is added ro a space travel class."<<endl;
               fl1=1;
            }
         }
    
if(fl1==0){
    for(int j=0;j<all_tickets.size();j++){
        if(all_tickets[j].source_station.planet_Name==new_tic.source_station.planet_Name && all_tickets[j].destination.planet_Name==new_tic.destination.planet_Name && all_tickets[j].date==new_tic.date && all_tickets[j].month==new_tic.month && all_tickets[j].year==new_tic.year){
        SpaceTravelClass new_stc;
        Passenger pas1,pas2;
        for(int k=0;k<passenger.size();k++){
            if(passenger[k].name==new_tic.traveller_name){
                pas1=passenger[k];
                break;
            }
            if(passenger[k].name==all_tickets[j].traveller_name){
                pas2=passenger[k];
            }
         }
         new_stc.Add_travellers(pas1);
         new_stc.Add_travellers(pas2);
         new_stc.update_astro_id(14+(rand()%2));
         new_stc.update_commander_id(12+(rand()%2));
         new_stc.initial_planet=new_tic.source_station;
         new_stc.final_planet=new_tic.destination;
         new_stc.date=new_tic.date;
         new_stc.month=new_tic.month;
         new_stc.year=new_tic.year;
         stc.push_back(new_stc);
         cout<<"A new space travel class is created."<<endl;
        }
    }
    }
     all_tickets.push_back(new_tic);
    
    }
   
    else if(fl==0){
    cout<<"You are not a registered user."<<endl;
    }
}
else if(func==4){
    string psg_name="";
    cout<<"Enter your name: ";
    cin>>psg_name;
    int id;
    int siz=psg_name.length();
    cout<<"Enter your id";
    int fl=0;
    cin>>id;
    for(int i=0;i<passenger.size();i++){
            if(passenger[i].name==psg_name && passenger[i].ID==id){
                fl=1;
                psg=passenger[i];
                break;
            }
    }
    for(int i=0;i<commander.size();i++){
            if(commander[i].name==psg_name && commander[i].ID==id){
                fl=1;
                psg=commander[i];
                break;
            }
    }
    for(int i=0;i<astronaut.size();i++){
            if(astronaut[i].name==psg_name && astronaut[i].ID==id){
                fl=1;
                psg=astronaut[i];
                break;
            }
}
    int tic_id;
    cout<<"Enter the ticket id you want to update: ";
    cin>>tic_id;
    Ticket upd_tic;
    for(int z=0;z<psg.list_of_tickets.size();z++){
       if(psg.list_of_tickets[z].ticket_id==tic_id){
        psg.list_of_tickets[z].update_ticket(planets,psg.list_of_tickets[z]);
       }
    }
       for(int l=0; l<all_tickets.size() ;l++){
        if(all_tickets[l].ticket_id==tic_id){
            all_tickets[l].update_ticket(planets,all_tickets[l]);
        }
       }
    
    
}
else if(func==5) {
    cout<<"Enter planet name(earth or mars or europa): ";
    string pla;
    cin>>pla;
    planet re_planet;
    for(int j=0;j<3;j++){
        if(pla==planets[j].planet_Name){
            re_planet=planets[j];

        }
    }
        re_planet.getCoordinates();
        re_planet.getAtmosphere();
        re_planet.getWater();
        re_planet.getinhabitants();
   
    }
else if(func==6){
    cout<<"Enter source planet: ";
    string plan;
    cin>>plan;
    cout<<"Enter destination planet: ";
    string plan2;
    cin>>plan2;
    planet pla1,pla2;
    if(plan=="earth"){
     pla1=planets[0];
    }
    else if(plan=="mars"){
     pla1=planets[1];
    }
    else if(plan=="europa"){
        pla1=planets[2];
    }
    if(plan2=="earth"){
        pla2=planets[0];
    }
    else if(plan2=="mars"){
        pla2=planets[1];
    }
    else if(plan2=="europa"){
        pla2=planets[2];
    }

    Ticket tic;
    cout<<"Enter your date of travel in dd/mm/yyyy format: ";
    int date,month,year;
     std::cin >> date; 
          if ( std::cin.get() != '/' ){
            std::cout << "expected /\n";

          }
         std::cin >> month; 
         if ( std::cin.get() != '/' ){
           std::cout << "expected /\n";
         }
         std::cin >> year;
    int tic_price=tic.getprice(pla1,pla2,month,date,year);
    cout<<"The ticket price will be "<<tic_price<<endl;


}
else if(func==7){
    cout<<"Enter your name: ";
    string comm_nam;
    cin>>comm_nam;
    Commander comm;
    for(int i=0;i<commander.size();i++){
        if(comm_nam==commander[i].name){
            comm=commander[i];
        }
    }
    cout<<"Your upcoming travels are : ";
    for(int i=0;i<stc.size();i++){
        int comm_id=stc[i].getcommander_id();
     if(comm.ID==comm_id){
        cout<< stc[i].initial_planet.planet_Name<<" to "<<stc[i].final_planet.planet_Name << " on the date "<< stc[i].date << "/"<<stc[i].month<<"/"<<stc[i].year<<endl;
     }
    }
}
else if(func==8){
   
    string psg_name="";
    cout<<"Enter your name: ";
    cin>>psg_name;
    int id;
    int siz=psg_name.length();
    cout<<"Enter your id";
    int fl=0;
    cin>>id;
    for(int i=0;i<passenger.size();i++){
            if(passenger[i].name==psg_name && passenger[i].ID==id){
                fl=1;
                psg=passenger[i];
                break;
            }
    }
    for(int i=0;i<commander.size();i++){
            if(commander[i].name==psg_name && commander[i].ID==id){
                fl=1;
                psg=commander[i];
                break;
            }
    }
    for(int i=0;i<astronaut.size();i++){
            if(astronaut[i].name==psg_name && astronaut[i].ID==id){
                fl=1;
                psg=astronaut[i];
                break;
            }
}
    int tic_id;
    cout<<"Enter the ticket id you want to update: ";
    cin>>tic_id;
    Ticket upd_tic;
    for(int z=0;z<psg.list_of_tickets.size();z++){
       if(psg.list_of_tickets[z].ticket_id==tic_id){
        psg.list_of_tickets[z].cancel_ticket(planets, psg.list_of_tickets[z],psg);
       }
    }
       for(int l=0; l<all_tickets.size() ;l++){
        if(all_tickets[l].ticket_id==tic_id){
            all_tickets.erase(all_tickets.begin()+(l-1),all_tickets.begin()+l);
        }
       }
    
    
}
else if(func==9){
    cout<<"These are following space travel classes"<<endl;
    for(int a=0;a<stc.size();a++){
        cout<<"space travel"<<a<<endl;
        cout<< "The space craft is travelling from " << stc[a].initial_planet.planet_Name <<" to "<< stc[a].final_planet.planet_Name <<" on " << stc[a].date << "/" << stc[a].month << "/" << stc[a].year <<endl;
        int astron_id=stc[a].getastronaut_id();
        int comman_id=stc[a].getcommander_id();
        cout<<"The commander id "<<comman_id<<endl;
        cout<<"The astronaut id "<<astron_id<<endl;

    }
}
else if(func==-1){
    cout<<"Please enter a valid number."<<endl;
}
}

}