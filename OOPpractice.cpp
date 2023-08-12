#include<iostream>
using namespace std;
//abstract class
class iF1{
    virtual void confirmF1() =0;
};
//base class Car
class Car:iF1{

//private:
protected:
    int Price;

public:
    string Brand;
    string Model;
    int Year;

    void startSound(){
        cout<<"Bhooooom"<<endl;
    }

    void carIntro(){
        cout<<Brand<<" Model "<<Model<<" Released in "<<Year<<" Costs "<<Price<<endl;
    }


     void setPrice(int p){
         Price = p;
     }
     int  getPrice(){
         return Price;
     }

     void confirmF1(){
         if(Price > 5000) cout<<"Compatible for F1"<<endl;
         else cout<<"Not compatible for F1"<<endl;
     }

    virtual void carDetails(){
        cout<<Brand<<" is a hybrid car"<<endl;
     }
    Car(string brand, string model, int year,int price);

};
//constructor definition outside the class
    Car:: Car(string brand, string model, int year,int price){
            Brand = brand;
            Model = model;
            Year = year;
            Price = price;
}
//a sub Electric class that inherits superclass Car
    class Electric:public Car{
        public:
        string Motor;
        Electric(string brand, string model, int year,int price,string motor)
           :Car(brand,model,year,price)
        {
            Motor = motor;
        }
        void printPrice(){
            //cout<<getPrice(); //when Price is Private
            cout<<Price; //When Price is Protected
        }

        void carDetails(){
            cout<<Brand<<" is a electric car"<<endl;
        }


    };
    class Gas: public Car{
         public:
        int Capacity;
        Gas(string brand, string model, int year,int price,int capacity)
           :Car(brand,model,year,price)
        {
            Capacity = capacity;
        }
        void carDetails(){
            cout<<Brand<<" is a gas car"<<endl;
         }


    };


int main(){
     //Car car1 = Car("BMW","M5",2001,6000); //way 1 to create an object using constractor
     //Car car1("BMW","M5",2001); //way 2 to create an object using constractor
//    Car car1;  //way 3 to create an object using constractor
//    car1.Brand = "BMW";
//    car1.Model = "X5";
//    car1.Year = 1997;
//    car1.setPrice(6000);

//    car1.startSound();
//    car1.carIntro();
//    car1.confirmF1();


     Electric tesla("Tesla","X",2014,40000,"M3");
     tesla.carIntro();
     //tesla.carDetails();
     //tesla.confirmF1();
     //tesla.printPrice();

     Gas toyota("Toyota","Corolla",2013,10000,5);
     toyota.carIntro();
     //toyota.carDetails();

     Car* p1 = &tesla;
     Car* p2 = &toyota;

     p1->carDetails();
     p2->carDetails();



}
