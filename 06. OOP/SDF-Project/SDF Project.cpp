#include<iostream>
#include<exception>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<chrono>
#include<thread>
using namespace std;
class Car
{
    private:
    int wheels;
    string engine;
    string colour;
    public:
    Car()
    {

    }
    ~Car()
    {

    }
};
class Sedan : public Car
{
    private:
    string comfort;
    public:
    Sedan()
    {

    }
    ~Sedan()
    {

    }
};
class Hatchback : public Car
{
    private:
    float bootspace;
    public:
    Hatchback()
    {

    }
    ~Hatchback()
    {

    }
};
class SUV : public Car
{
    private:
    int ground_clearance;
    float length;
    public:
    SUV()
    {

    }
    ~SUV()
    {

    }
};
class Compact_SUV : public Car
{
    private:
    int seats;
    public:
    Compact_SUV()
    {

    }
    ~Compact_SUV()
    {

    }
};
class Supercar : public Car
{
    private:
    string exhaust;
    int speed;
    public:
    Supercar()
    {

    }
    ~Supercar()
    {

    }
};
class Hypercar : public Car
{
    private:
    string performance;
    public:
    Hypercar()
    {

    }
    ~Hypercar()
    {

    }
};
void delay(int milliseconds) {
    //this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void printWithDelay(const string& str, int delayMs) {
    for (char c : str) {
        cout << c;
        cout.flush(); 
        delay(delayMs);
    }
}
int main()
{
    int a=0;
    char x='a';
    char y='b';
    cout << "\t\t\t**********************************************************";
    cout<<endl;
    delay(100);
    printWithDelay("\t\t\t\t\tWELCOME TO ARSY CAR DEALERSHIP\n", 50);
    delay(100);
    cout << "\t\t\t**********************************************************";
    cout<<endl;
    delay(100);
    cout << endl;
    cout<<"Enter service : ";
    cout<<endl;
    cout<<"1 : Car Dealing ";
    cout<<endl;
    cout<<"2 : Car Customisation";
    cout<<endl;
    cout<<endl;
    int n;
    cin>>n;
    try
    {  
        if(n!=1&&n!=2)
        {throw a;}
    }
    catch (int a)
    {
        cout<<"Invalid service opted!!";
        cout<<endl;
    };
    try 
    {
         if(n==1)
        throw x;
    }
    catch (char x)
    {
        cout<<"You have opted for Car Dealing!!";
        cout<<endl;
    }
     try 
    {
         if(n==2)
        throw y;
    }
    catch (char y)
    {
        cout<<"You have opted for Car Customization!!";
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    if(n==1)
    {
        cout<<"Available options are : ";
        cout<<endl;
        cout<<"1. Sedan";
        cout<<endl;
        cout<<"2. Hatchback";
        cout<<endl;
        cout<<"3. SUV";
        cout<<endl;
        cout<<"4. Compact SUV";
        cout<<endl;
        cout<<"5. Supercar";
        cout<<endl;
        cout<<"6. Hypercar";
        cout<<endl;
    }
    else if(n==2)
    {
            cout<<"Available options are : ";
            cout<<endl;
            cout<<"1. PPF";
            cout<<endl;
            cout<<"2. Wrap";
            cout<<endl;
            cout<<"3. Alloys";
            cout<<endl;
            cout<<"4. Seat covers";
            cout<<endl;
            cout<<"5. Coating";
            cout<<endl;
    }
   else
   {
        cout<<"Invalid service opted!!";
        cout<<endl;
    }
    int q;
    if(n==1)
    {
        cout<<endl;
        cout<<endl;
        cin>>q;
        if(q==1)
        {
            cout<<"Sedans available : ";
            cout<<endl;
            cout<<"1. Maruti Ciaz";
            cout<<endl;
            cout<<"2. Hyundai Verna";
            cout<<endl;
            cout<<"3. Volkswagen Virtus";
            cout<<endl;
            cout<<"4. Skoda Rapid";
            cout<<endl;
            cout<<"5. Honda City";
            cout<<endl;
        }
        else if(q==2)
        {
            cout<<"Hatchbacks available : ";
            cout<<endl;
            cout<<"1. Tata Nano";
            cout<<endl;
            cout<<"2. Hyundai i10";
            cout<<endl;
            cout<<"3. Honda Brio";
            cout<<endl;
            cout<<"4. Maruti WagonR";
            cout<<endl;
            cout<<"5. volkswagen Polo";
            cout<<endl;
        }
        else if(q==3)
        {
            cout<<"SUVs available : ";
            cout<<endl;
            cout<<"1. Ford Everest";
            cout<<endl;
            cout<<"2. Toyota Fortuner";
            cout<<endl;
            cout<<"3. MG Gloster";
            cout<<endl;
            cout<<"4. Tata Hexa";
            cout<<endl;
            cout<<"5. Mahindra XUV500";
            cout<<endl;
        }
        else if(q==4)
        {
            cout<<"Compact SUVs available : ";
            cout<<endl;
            cout<<"1. Maruti Brezza";
            cout<<endl;
            cout<<"2. Tata Punch";
            cout<<endl;
            cout<<"3. Mahindra XUV300";
            cout<<endl;
            cout<<"4. Hyundai Creat";
            cout<<endl;
            cout<<"5. Honda Elevate";
            cout<<endl;
        }
        else if(q==5)
        {
            cout<<"Supercars available : ";
            cout<<endl;
            cout<<"1. Audi R8";
            cout<<endl;
            cout<<"2. McLaren 750S";
            cout<<endl;
            cout<<"3. Ferrari 296GTB";
            cout<<endl;
            cout<<"4. Porsche 911";
            cout<<endl;
            cout<<"5. Aston Martin DBS";
            cout<<endl;
        }
        else if(q==6)
        {
           cout<<"Hypercars available : ";
            cout<<endl;
            cout<<"1. Ford GT";
            cout<<endl;
            cout<<"2. Bugatti Chiron";
            cout<<endl;
            cout<<"3. McLaren Senna";
            cout<<endl;
            cout<<"4. Porsche 918 Spyder";
            cout<<endl;
            cout<<"5. Ferrari Monza";
            cout<<endl; 
        }
        else
        {
            cout<<"Invalid car type entered!!";
        }
    }
    else if(n==2)
    {
        cout<<endl;
        cout<<endl;
        cin>>q;
        if(q==1)
        {
            cout<<"PPFs available : ";
            cout<<endl;
            cout<<"1. Garware TPH 150 micron";
            cout<<endl;
            cout<<"2. Garware TPU 200 micron";
            cout<<endl;
            cout<<"3. Paintguard TPH 175 micron ";
            cout<<endl;
            cout<<"4. Paintguard TPU 190 micron";
            cout<<endl;
            cout<<"5. Avery Dennison TPU 225 micron";
            cout<<endl;
        }
        else if(q==2)
        {
            cout<<"Wraps available : ";
            cout<<endl;
            cout<<"1. Glossy Wrap";
            cout<<endl;
            cout<<"2. Matte Wrap";
            cout<<endl;
            cout<<"3. Metallic Wrap";
            cout<<endl;
            cout<<"4. Carbon Wrap";
            cout<<endl;
            cout<<"5. Partial Wrap";
            cout<<endl;

        }
        else if(q==3)
        {
            cout<<"Alloys Available : ";
            cout<<endl;
            cout<<"1. Forged Alloys";
            cout<<endl;
            cout<<"2. Steel Alloys";
            cout<<endl;
            cout<<"3. Split Rims";
            cout<<endl;
            cout<<"4. Die Casting";
            cout<<endl;
        }
        else if(q==4)
        {
            cout<<"Seat covers available : ";
            cout<<endl;
            cout<<"1. Universal Seat Covers";
            cout<<endl;
            cout<<"2. Towel Seat Covers";
            cout<<endl;
            cout<<"3. Bucket Seat Covers";
            cout<<endl;
            cout<<"4. Textile seat covers";
            cout<<endl;
            cout<<"5. PU Seat Covers";
            cout<<endl;
            cout<<"6. Leather Seat Covers";
            cout<<endl;
            cout<<"7. Disposable Seat Covers";
            cout<<endl;
            cout<<"8. Neoprene Seat Covers";
            cout<<endl;
            cout<<"9. Ultra Comfort Seat Covers";
            cout<<endl;
        }
        else if(q==5)
        {
            cout<<"Coatings Available : ";
            cout<<endl;
            cout<<"1. Ceramic Coating";
            cout<<endl;
            cout<<"2. Graphene Coating";
            cout<<endl;
        }
        else
        {
            cout<<"Invalid customisation opted!!";
            cout<<endl;
        }
    }
    double  w;
    cout<<endl;
    cout<<"Enter Budget : ";
    if(n==1)
    {
        cout<<endl;
        if(q==1)
        {
            cin>>w;
            cout<<"Available options are : ";
            if(w<=800000 && w>500000)
            {
                cout<<"1. Maruti Ciaz";
                cout<<endl;
                cout<<"2. Honda City";
                cout<<endl;
            }
            else if(w>800000 && w<1300000)
            {
                cout<<"1. Hyundai Verna";
                cout<<endl;
                cout<<"2. Volkswagen Virtus";
                cout<<endl;
                cout<<"3. Skoda Rapid";
                cout<<endl;
            }
            else
            {
                cout<<"No option available!!";
                cout<<endl;
            }
        }
        else if(q==2)
        {
            cin>>w;
            if(w<=500000 && w>200000)
            {
                cout<<"1. Tata Nano";
                cout<<endl;
                cout<<"2. Hyundai i10";
                cout<<endl;
                cout<<"3. Honda Brio";
                cout<<endl;
            }
            else if(w>500000&&w<1000000)
            {
                cout<<"1. Maruti WagonR";
                cout<<endl;
                cout<<"2. Volkswagen Polo";
                cout<<endl;
            }
             else
            {
                cout<<"No option available!!";
                cout<<endl;
            }
        }
        else if(q==3)
        {
            cin>>w;
            if(w<=4500000 && w>3500000)
            {
                cout<<"1. Tata Hexa";
                cout<<endl;
                cout<<"2. Mahindra XUV500";
                cout<<endl;
            }
            else if(w>4500000 && w<5500000)
            {
                cout<<"1. Ford Everest";
                cout<<endl;
                cout<<"2. Toyota Fortuner";
                cout<<endl;
                cout<<"3. MG Gloster";
                cout<<endl;
            }
             else
            {
                cout<<"No option available!!";
                cout<<endl;
            }
        }
        else if(q==4)
        {
            cin>>w;
            if(w<=800000 && w>500000)
            {
                cout<<"1. Tata Punch";
                cout<<endl;
                cout<<"2. Maruti Brezza";
                cout<<endl;
                cout<<"3. Mahindra XUV300";
                cout<<endl;
            }
            else if(w>800000 && w<1500000)
            {
                cout<<"1. Honda Elevate";
                cout<<endl;
                cout<<"2. Hyundai Creta";
                cout<<endl;
            }
             else
            {
                cout<<"No option available!!";
                cout<<endl;
            }
        }
        else if(q==5)
        {
            cin>>w;
            if(w<=7500000 && w>7000000)
            {
                cout<<"1. Audi R8";
                cout<<endl;
                cout<<"2. Porsche 911";
                cout<<endl;
            }
            else if(w>7500000 && w<12000000)
            {
                cout<<"1. Ferrari 296GTB";
                cout<<endl;
                cout<<"2. McLaren 750S";
                cout<<endl;
                cout<<"3. Aston Martin DBS";
                cout<<endl;
            }
             else
            {
                cout<<"No option available!!";
                cout<<endl;
            }
        }
        else if(q==6)
        {
            cin>>w;
            if(w<=1200000&&w>1100000)
            {
                cout<<"1. Ford GT";
                cout<<endl;
                cout<<"2. Porsche 918 Spyder";
                cout<<endl;
                cout<<"3. McLaren Senna";
                cout<<endl;
            }
            else if(w>12000000 && w<15000000)
            {
                cout<<"1. Bugatti Chiron";
                cout<<endl;
                cout<<"2. Ferrari Monza";
                cout<<endl;
            }
             else
            {
                cout<<"No option available!!";
                cout<<endl;
            }
        }
    }
    int t;
    if(n==2)
    {
        cout<<endl;
        if(q==1)
        {
           cin>>t;
           if(t<=60000&&t>50000)
           {
            cout<<"1. Garware TPH 175 micron";
            cout<<endl;
            cout<<"2. Paintguard TPH 175 micron";
            cout<<endl;
           } 
           else if(t>60000&&t<80000)
           {
            cout<<"1. Garware TPU 200 micron";
            cout<<endl;
            cout<<"2. Paintguard TPU 190 micron";
            cout<<endl;
           }
           else if(t>80000 && t<100000)
           {
            cout<<"1. Avery Dennison TPU 225 micron";
            cout<<endl;
           }
           else
           {
            cout<<"No option available";
            cout<<endl;
           }
        }
        if(q==2)
        {
            cin>>t;
            if(t>30000 && t<50000)
            {
                cout<<"1. Glossy wrap";
                cout<<endl;
                cout<<"2. Matte wrap";
                cout<<endl;
                cout<<"3. Partial wrap";
                cout<<endl;
            }
            else if(t>50000&&t<80000)
            {
                cout<<"1. Metallic wrap";
                cout<<endl;
                cout<<"2. Carbon Fibre wrap";
                cout<<endl;
            }
            else
           {
            cout<<"No option available";
            cout<<endl;
           }
        }
        if(q==3)
        {
            cin>>t;
            if(t>10000 && t<20000)
            {
                cout<<"1. Steel Alloys";
                cout<<endl;
                cout<<"2. Forged Alloys";
                cout<<endl;
            }
            else if(t>20000 && t<30000)
            {
                cout<<"1. Split Rim Alloys";
                cout<<endl;
            }
            else if(t>30000 && t<45000)
            {
                cout<<"1. Die Casting Alloys";
                cout<<endl;
            }
            else
           {
            cout<<"No option available";
            cout<<endl;
           }
        }
        if(q==4)
        {
            cin>>t;
            if(t>=5000 && t<=10000)
            {
                cout<<"1. Universal Covers";
                cout<<endl;
                cout<<"2. Towel Covers";
                cout<<endl;
                cout<<"3. Disposable Covers";
                cout<<endl;
            }
            else if(t>10000 && t<20000)
            {
                cout<<"1. Bucket Covers";
                cout<<endl;
                cout<<"2. extile Covers";
                cout<<endl;
                cout<<"3. PU Covers";
                cout<<endl;
                cout<<"4. Neoprene Covers";
                cout<<endl;
            }
            else if(t>20000 && t<35000)
            {
                cout<<"1. Leather Covers";
                cout<<endl;
                cout<<"2. Ultracomfort Covers";
                cout<<endl;
            }
            else
           {
            cout<<"No option available";
            cout<<endl;
           }
        }
        if(q==5)
        {
            cin>>t;
            if(t>10000 && t<14000)
            {
                cout<<"1. Ceramic Coating";
                cout<<endl;
            }
            else if(t>14000 && t<17000)
            {
                cout<<"2. Graphene Coating";
                cout<<endl;
            }
            else
           {
            cout<<"No option available";
            cout<<endl;
           }
        }
    }
    return 0;
}
