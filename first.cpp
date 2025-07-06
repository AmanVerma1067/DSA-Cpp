// To run a program manually in Linux terminal, use these commands:
// $ g++ first.cpp -o first
// $ ./first
// first name then that command
#include<iostream>
using namespace std;
int main(){
    cout<<"hello aman"<<endl;
    int n;
    cout<<"Enter a Number: ";
    cin>>n;
    cout<<n<<endl;
//  int arr[7] = {1,2,3,4,5,6,7};
      vector <int> arr = {1,2,3,4,5,6,7};
// for (int i = 0; i < 7; i++)
    for( auto it: arr)
    {
// cout<<arr[i]*arr[i]<<endl;
          cout<<it*it<<endl;
    }
  
    return 0;
}
