#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main()
{
    map <int, string> student;
    student[1] = "Aman Verma";
    student[2] = "Vipin Kumar";
    student[3] = "Prashant Khatri";
    student[4] = "Vivek Awasthi";
    map <int, string> :: iterator itr;
    itr = student.begin();
    while(itr != student.end()){
        cout<<"The Name of Student "<< itr->first<<" is: "<<itr->second<<endl;
        itr++;
    }

    return 0;
}