#include <bits/stdc++.h>
using namespace std;
template<class T>
class vec{
public:
T a, b ,c, f;
vec(){}
vec(T x, T y, T z, T p){
    a = x;
    b = y;
    c = z;
    f = p;
    }
vec operator *(){
vec t;
t.a = f*a;
t.b = f*b;
t.c = f*c;
return t;
}
void display(){
cout<<endl<<"The scalar is "<<f<<endl;
cout<<endl<<"The vector is "<<a<<"i "<<b<<"j "<<c<<"k "<<endl;
}
void display2(){
cout<<endl<<"The resultant vector is "<<a<<"i "<<b<<"j "<<c<<"k "<<endl;
}
};

int main() {
    vec<float> v1(2.5,4.2,5.7,5.5);
    v1.display();
    vec<float> v2;
    v2 = *v1;
    v2.display2();


	return 0;
}