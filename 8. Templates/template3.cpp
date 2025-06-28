#include <iostream>
using namespace std;
 
template <class T1 = int, class T2 = float, class T3 = char>
class myClass
{
public:
    T1 data1;
    T2 data2;
    T3 data3;
 
    myClass(T1 a, T2 b, T3 c)
    {
        data1 = a;
        data2 = b;
        data3 = c;
    }
    void display()
    {
        cout << "The value of a is " << data1 << endl;
        cout << "The value of b is " << data2 << endl;
        cout << "The value of c is " << data3 << endl;
    }
};
 
int main()
{
    myClass<> obj1(1, 4.3, 'C');
    obj1.display();
}