#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>  // for sleep function
using namespace std;

void BuyCar();
string showAvailableCars();
void employee();
void customer();
void BuyBike();
string showAvailableBikes();
void showEmployeeOptions();                   
void showCustomerDetails();
void addNewCar();
void addNewBike();

class Vehicle{

protected:
    string engine;
    int wheels;
    string price;
    string model;
    string year;

public:
    Vehicle()
    {
        engine = "None";
        wheels = 0;
        price  = "0";
        model = "Unknown";
        year = "2023";
    }
    virtual void displayDetails() = 0;
};


class Car : public Vehicle{

private:
    string type;
    string seats;
    vector <string> features;

public:
    Car()
    {
        type = "None";
        seats = "0";
        features = {"0","0"};
    }
    Car(string engine,string price, string model, string year, string type, string seats, vector <string> features)
    {
        this->engine = engine;
        wheels = 4;
        this->price = price;
        this->model = model;
        this->year = year;
        this->features = features;
        this -> type = type;
        this -> seats = seats;
    }
    void displayDetails()
    {
        cout << "Model : " << model;
        cout << endl;
        cout << "Engine : " << engine;
        cout << endl;
        cout << "Year : " << year;
        cout << endl;
        cout << "Type : " << type;
        cout << endl;
        cout << "Seats : " << seats;
        cout << endl;
        cout << "Price : " << price;
        cout << endl;
        cout << "Special Features : ";
        cout << endl;
        for(int i = 0 ; i < features.size() ; i++){
            cout << features[i];
            cout << endl;
        }
    }
    string displayModel(){
        return model;
    }
};


class Bike : public Vehicle{

private:
    string type;
    vector <string> features;

public:
    Bike()
    {
        type = "None";
        features = {"0","0"};
    }

    Bike(string engine,string price, string model, string year, string type, vector <string> features)
    {
        this->engine = engine;
        wheels = 2;
        this->price = price;
        this->model = model;
        this -> type = type;
        this->year = year;
        this->features = features;
        this -> type = type;
    }
    void displayDetails()
    {
        cout << "Model : " << model;
        cout << endl;
        cout << "Engine : " << engine;
        cout << endl;
        cout << "Year : " << year;
        cout << endl;
        cout << "Type : " << type;
        cout << endl;
        cout << "Price : " << price;
        cout << endl;
        cout << "Special Features : ";
        cout << endl;
        for(int i = 0 ; i < features.size() ; i++){
            cout << features[i];
            cout << endl;
        }
    }

    string displayModel(){
        return model;
    }
};


void showCustomerDetails()
{
    fstream fin;
    string line;
    fin.open("customerDetails.txt",ios::in);
    while(fin){
        getline(fin,line);
        cout << line;
        cout << endl;
    }
    fin.close();
}


void showEmployeeOptions()
{
    while(true)
    {
        int opt5;
        cout << endl << "Employee options : ";
        cout << endl;
        cout << "1. View Customer Details.";
        cout << endl;
        cout << "2. View Available Cars.";
        cout << endl;
        cout << "3. View Available Bikes.";
        cout << endl;
        cout << "4. Add a new Car.";
        cout << endl;
        cout << "5. Add a new Bike.";
        cout << endl;
        cout << "6. Exit";
        cout << endl;
        cout << "-> ";
        cin >> opt5;
        if(opt5 == 6){
            break;
        }
        switch(opt5){
            case 1:
                showCustomerDetails();
                break;
            case 2:
                showAvailableCars();
                break;
            case 3:
                showAvailableBikes();
                break;
            case 4:
                addNewCar();
                break;
            case 5:
                addNewBike();
                break;
        }
    }
}


void employee()
{
    string emname;
    string emcode;
    while(true)
    {
        cout << endl <<"Welcome to employee portal";
        cout << endl;
        cout << "Please Authenticate your employee details.";
        cout << endl;
        cout << "Enter employee name : ";
        cin.ignore();
        getline(cin,emname);
        cout << "Enter employee code : ";
        cin >> emcode;
        string emnamecode = emname + " " + emcode;
        ifstream fin;
        string line;
        bool flag = false;
        fin.open("EmployeeDetails.txt",ios::in);
        while(fin){
            getline(fin,line);
            if(emnamecode == line) flag = true;
        }
        fin.close();
        if(flag){
            showEmployeeOptions();
        }
        else{
            cout << "Wrong Employee Details";
            cout << endl;
            break;
        }
    }
}


void customer()
{
    int opt2;
    while(true){
        cout << endl << "Welcome to customer portal.";
        cout << endl;
        cout << "Enter action you wish to perform: ";
        cout << endl;
        cout << "1. Buy cars.";
        cout << endl;
        cout << "2. Buy Bikes";
        cout << endl;
        cout << "3. Exit";
        cout << endl;
        cout << "-> ";
        cin >> opt2;
        if(opt2 == 1){
            BuyCar();
        }
        else if(opt2 == 2){
            BuyBike();
        }
        else if(opt2 == 3){
            break;
        }
        else{
            cout << "Wrong input";
            cout << endl;
        }
    }
}


void BuyCar()
{
    char opt4;
    string model =  showAvailableCars();
    cout << "Do you wish to purchase this car? (Y/N)";
    cout << endl;
    cout << "-> ";
    cin >> opt4;
    if(opt4 == 'Y' || opt4 == 'y'){
        string Cname;
        string Cpno;
        string paymentMethod;
        cout << "Please Enter your name : ";
        cin.ignore();
        getline(cin,Cname);
        cout << "Please Enter your phone number: ";
        cin >> Cpno;
        cout << "Select payment method: ";
        cout << endl;
        cout << "1. Card";
        cout << endl;
        cout << "2. Cheque";
        cout << endl;
        cout << "3. Net Banking";
        cout << endl;
        cout << "-> ";
        int paymentOpt;
        cin >> paymentOpt;
        switch(paymentOpt){
            case 1:
                paymentMethod = "Card";
                break;
            case 2:
                paymentMethod = "Cheque";
                break;
            case 3:
                paymentMethod = "Net Banking";
                break;
            default:
                cout << "Invalid option";
                return;
        }
        cout << Cname << " : " << Cpno << " : " << model << " : " << paymentMethod;
        cout << endl;
        cout << "One of our employees will contact you soon. Thank you!" << endl << endl << endl;
        fstream fio;
        fio.open("customerDetails.txt",ios::app);
        fio << Cname << " : " << Cpno << " : " << model << " : " << paymentMethod << endl;
        fio.close();
    }
}


string showAvailableCars()
{
    cout << "Available Cars: ";
    cout << endl;
    int opt3;
    vector <string> features = {"360 degree camera view","Heated Seats","Multimedia touch display","Automatic/Manual","Petrol"};
    string line;
    fstream fin;
    vector <Car> vec;
    fin.open("CarDetails.txt",ios::in);
    int n = 1;
    while(fin){
        getline(fin,line);
        if(fin.eof()) break;
        string engine;
        string price;
        string model;
        string year;
        string seats;
        string type;
        int i;
        for(i = 0;line[i]!=',';i++){
            engine += line[i];
        }
        i++;
        for(;line[i]!=',';i++){
            price += line[i];
        }
        i++;
        for(;line[i]!=',';i++){
            model += line[i];
        }
        i++;
        for(;line[i]!=',';i++){
            year += line[i];
        }
        i++;
        for(;line[i]!=',';i++){
            type += line[i];
        }
        i++;
        for(;line[i]!='\0';i++){
            seats += line[i];
        }
        Car c1(engine,price,model,year,type,seats,features);
        vec.push_back(c1);
        cout << n++ << ". Model : " << model << endl;
    }
    cout << "-> ";
    cin >> opt3;
    vec[opt3-1].displayDetails();
    return vec[opt3-1].displayModel();
}


void addNewCar()
{
    fstream finout;
    vector <string> features = {"360 degree camera view","Heated Seats","Multimedia touch display","Automatic/Manual","Petrol"};
    string engine;
    string price;
    string model;
    string year;
    string type;
    string seats;
    finout.open("CarDetails.txt",ios::app);
    cout << "Enter Car Details.";
    cout << endl;
    cout << "Enter engine : ";
    cin.ignore();
    getline(cin,engine);
    cout << "Enter Price : ";
    getline(cin,price);
    cout << "Enter Model : ";
    getline(cin,model);
    cout << "Enter year : ";
    getline(cin,year);
    cout << "Enter Type : ";
    getline(cin,type);
    cout << "Enter number of seats : ";
    getline(cin,seats);
    string concat = engine + ","  + price + ","  + model + ","  + year + ","  + type + "," + seats;
    finout << concat << endl;
    Car c1(engine,price,model,year,type,seats,features);
    cout << "Added car." << endl;
}


void addNewBike()
{
    fstream finout;
    vector <string> features = {"Dual Channel ABS","Liquid cooling engine","Performance Tires"};
    string engine;
    string price;
    string model;
    string year;
    string type;
    finout.open("BikeDetails.txt",ios::app);
    cout << "Enter Bike Details." << endl;
    cin.ignore();
    cout << "Enter engine : ";
    getline(cin,engine);
    cout << "Enter Price : ";
    getline(cin,price);
    cout << "Enter Model : ";
    getline(cin,model);
    cout << "Enter year : ";
    getline(cin,year);
    cout << "Enter Type : ";
    getline(cin,type);
    string concat = engine + ","  + price + ","  + model + ","  + year + ","  + type;
    finout << concat << endl;
    Bike b1(engine,price,model,year,type,features);
    cout << "Added Bike." << endl;
}

string showAvailableBikes()
{
    cout << "Available Bikes: " << endl;
    int opt3;
    vector <string> features = {"Dual Channel ABS","Liquid cooling engine","Performance Tires"};
    string line;
    fstream fin;
    vector <Bike> v1;
    fin.open("BikeDetails.txt",ios::in);
    int n = 1;
    while(fin){
        getline(fin,line);
        if(fin.eof()) break;
        string engine;
        string price;
        string model;
        string year;
        string type;
        int i;
        for(i = 0;line[i]!=',';i++){
            engine += line[i];
        }
        i++;
        for(;line[i]!=',';i++){
            price += line[i];
        }
        i++;
        for(;line[i]!=',';i++){
            model += line[i];
        }
        i++;
        for(;line[i]!=',';i++){
            year += line[i];
        }
        i++;
        for(;line[i]!='\0';i++){
            type += line[i];
        }
        Bike b1(engine,price,model,year,type,features);
        v1.push_back(b1);
        cout << n++ << ". Model : " << model << endl;
    }
    cout << "-> ";
    cin >> opt3;
    v1[opt3-1].displayDetails();
    return v1[opt3-1].displayModel();
}


void BuyBike()
{
    string model = showAvailableBikes();
    char opt4;
    cout << "Do you wish to purchase this Bike? (Y/N)";
    cout << endl;
    cout << "-> ";
    cin >> opt4;
    if(opt4 == 'Y' || opt4 == 'y'){
        string Cname;
        string Cpno;
        string paymentMethod;
        cout << "Please Enter your name : ";
        cin.ignore();
        getline(cin,Cname);
        cout << "Please Enter your phone number: ";
        cin >> Cpno;
        cout << "Select payment method: ";
        cout << endl;
        cout << "1. Card";
        cout << endl;
        cout << "2. Cheque";
        cout << endl;
        cout << "3. Net Banking";
        cout << endl;
        cout << "-> ";
        int paymentOpt;
        cin >> paymentOpt;
        switch(paymentOpt){
            case 1:
                paymentMethod = "Card";
                break;
            case 2:
                paymentMethod = "Cheque";
                break;
            case 3:
                paymentMethod = "Net Banking";
                break;
            default:
                cout << "Invalid option";
                return;
        }
        cout << Cname << " : " << Cpno << " : " << model << " : " << paymentMethod;
        cout << endl;
        cout << "One of our employees will contact you soon. Thank you!" << endl << endl << endl;
        fstream fio;
        fio.open("customerDetails.txt",ios::app);
        fio << Cname << " : " << Cpno << " : " << model << " : " << paymentMethod << endl;
        fio.close();
    }
}

int main()
{
    int opt1;
    cout << "\t\t\t*********************************************************";
    cout << endl;
    usleep(300000);
    cout << "\t\t\t\t\tW";
    usleep(300000);
    cout<<"E";
    usleep(300000);
    cout<<"L";
    usleep(300000);
    cout<<"C";
    usleep(300000);
    cout<<"O";
    usleep(300000);
    cout<<"M";
    usleep(300000);
    cout<<"E";
    usleep(300000);
    cout<<" ";
    usleep(300000);
    cout<<"T";
    usleep(300000);
    cout<<"O";
    usleep(300000);
    cout<<" ";
    usleep(300000);
    cout<<"A";
    usleep(300000);
    cout<<"R";
    usleep(300000);
    cout<<"S";
    usleep(300000);
    cout<<"Y";
    usleep(300000);
    cout<<" ";
    usleep(300000);
    cout<<"C";
    usleep(300000);
    cout<<"A";
    usleep(300000);
    cout<<"R";
    usleep(300000);
    cout<<" ";
    usleep(300000);
    cout<<"D";
    usleep(300000);
    cout<<"E";
    usleep(300000);
    cout<<"A";
    usleep(300000);
    cout<<"L";
    usleep(300000);
    cout<<"E";
    usleep(300000);
    cout<<"R";
    usleep(300000);
    cout<<"S";
    usleep(300000);
    cout<<"H";
    usleep(300000);
    cout<<"I";
    usleep(300000);
    cout<<"P";
    usleep(300000);
    cout<<"\n";
    usleep(300000);
    cout << "\t\t\t*********************************************************";
    cout << endl;
    sleep(1);

    while(true)
    {
        cout << endl << "Enter option: ";
        cout << endl;
        cout << "1. Employee Portal.";
        cout << endl;
        cout << "2. Customer Portal.";
        cout << endl;
        cout << "3. Exit";
        cout << endl;
        cout << "-> ";
        cin >> opt1;
        if(opt1 == 1){
            employee();
        }
        else if (opt1 == 2){
            customer();
        }
        else if (opt1 == 3){
            break;
        }
        else{
            cout << "Wrong Input";
            cout << endl;
        }
    }

    return 0;
}
