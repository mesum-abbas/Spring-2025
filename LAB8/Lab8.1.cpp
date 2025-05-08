#include<iostream>
using namespace std;

class Vehicle {
    protected:
 string make;
 string model;
 string color;
 int year;
 long milesdriven;

    public:
    Vehicle (string mak , string mod , string col , int yr , long mildrive  ) : make(mak) , model(mod) , color(col) ,year(yr) ,milesdriven(mildrive) {}

    virtual void display(){
        cout << " Make \n"<< make << " Model \n" << model << "Color \n" << color << " Year\n" << year << " Miles driven\n" << milesdriven << " (miles)"<< endl;

    }
};

class Gasvehicle : public Vehicle {
    protected :
    float tanksize;

    public:
    Gasvehicle (string mak , string mod , string col , int yr , long mildrive , float tanks) : Vehicle (mak ,mod , col ,yr , milesdriven ) , tanksize(tanks) {}
     
    void display () override{
        Vehicle::display();
        cout << "Tank size " << tanksize << endl;
     }
};

class Electricvehicle : public Vehicle {
    protected : 
    double energystorage;
    
    public : 
    Electricvehicle ( string mak , string mod , string col , int yr , long mildrive , double energy ) : Vehicle (mak ,mod , col ,yr , milesdriven ) , energystorage(energy) {}
    void display()override{
        Vehicle::display();
        cout << "Energy storage \n" << energystorage<< endl ;
    }
   };

class High_perfomance : public Vehicle {
    protected : 
    int  hoursepower;
    float topspeed;
    public :
    High_perfomance (string mak , string mod , string col , int yr , long mildrive , int hrpower , float topspd ) : Vehicle  ( mak ,mod , col ,yr , milesdriven ) , hoursepower(hrpower) , topspeed(topspd) {} 

    void display()override{
        Vehicle::display();
        cout << "Hourse power " << hoursepower << " Topspeed " << topspeed << endl;
    }
   };

   
class Heavy_vehicle : public Vehicle {
    protected :
    long maxweight;
    int number_of_wheels;
    double length; 

    public :
    Heavy_vehicle (string mak , string mod , string col , int yr , long mildrive , long maxwt , int wheels , double len ) : Vehicle (mak ,mod , col ,yr , milesdriven ) , maxweight(maxwt) , number_of_wheels(wheels), length(len){}

    void display ()override{
        Vehicle::display();
        cout << " Max weight " << maxweight << " number of wheeks " << number_of_wheels << " Length "<< length << endl;
    }
   };

   
class Sportscar: public High_perfomance {
    protected:
    string gearbox;
    string drive_system;

    public :
    Sportscar (string mak , string mod , string col , int yr , long mildrive , int hrpower , float topspd, string gbox , string drsystem) : High_perfomance (mak ,mod , col ,yr , milesdriven ,hrpower , topspd) , gearbox(gbox) , drive_system(drsystem) {}
    void display()override{
        High_perfomance::display();
        cout << " Gear box " << gearbox << " Drive system " << drive_system << endl;
    }
   };

   
class Constructiontruck : public Heavy_vehicle {
    protected:
    string constructiontype;

    public :
    Constructiontruck (string mak , string mod , string col , int yr , long mildrive ,long maxwt , int wheels , double len, string constype) : Heavy_vehicle (mak ,mod , col ,yr , milesdriven , maxwt ,wheels , len) , constructiontype(constype) {}

    void display()override{
        Heavy_vehicle::display();
        cout << "Construction type " << constructiontype <<  endl;
    }
   };

   
class Bus : public Heavy_vehicle{
    protected:
    int no_of_seats;
    public :
    Bus (string mak , string mod , string col , int yr , long mildrive ,long maxwt , int wheels , double len, int seats) : Heavy_vehicle (mak ,mod , col ,yr , milesdriven ,maxwt , wheels ,len) , no_of_seats(seats) {}

    void display() override{
        Heavy_vehicle::display(); 
        cout << " number of seats  " << no_of_seats << endl;
    }
   };



int main (){


    Sportscar mycar("BMW", "i7","black",2019,0,500,250,"mannual","all wheels");
    mycar.display();
    return 0;
}
