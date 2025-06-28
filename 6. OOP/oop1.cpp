#include<iostream>
using namespace std;

class employee{
    private:
    int a,b,c;
    public:
    int d,e;
    void setData(int x, int y, int z);
    void getData(){
        cout<<"The Value of a is "<<a<<endl;
        cout<<"The Value of b is "<<b<<endl;
        cout<<"The Value of c is "<<c<<endl;
        cout<<"The Value of d is "<<d<<endl;
        cout<<"The Value of e is "<<e<<endl;
    }
};
void employee :: setData(int x, int y, int z){
    a=x;
    b=y;
    c=z;
}
int main()
{
    employee aman;
    aman.d = 34;
    aman.e = 67;
    // the values of a,b,c cant be changed like the above ones, because these are private.
    // they can only be changed or accessed by a virtual function inside that class like setdata.

    aman.setData(1,2,4);
    aman.getData();

    return 0;
}