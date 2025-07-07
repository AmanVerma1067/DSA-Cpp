#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{

    map<int, vector<int> > factors;
    int ch, number, i;
    cout<<"Enter 0 to exit and any other number to continue: "<<endl;
    cin>>ch;
    while(ch)
    {
        cout<<"Enter any positive integer: "<<endl;
        cin>>number;
        int flag = 0;

        map<int, vector<int> > :: iterator itr;
        for(itr = factors.begin(); itr != factors.end(); ++itr)
        {
            if(number == itr->first)
            {
                flag++;
            }
        }
        if(!flag)
        {
            for(i = 1; i <= number/2; i++)
            {
                if(number%i == 0)
                {
                    factors[number].push_back(i);
                }
            }
            factors[number].push_back(number);
        }
        else
        {
            cout<<"Key already exists!"<<endl;
        }
        cout<<"Enter 0 to exit and any other number to continue: "<<endl;
        cin>>ch;
    }
    map<int, vector<int> > :: iterator itr;
    for(itr = factors.begin(); itr != factors.end(); ++itr)
    {
        cout<<"The factors of "<<itr->first<<" are: ";
        vector<int> :: iterator itr2;
        for(itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
        {
            cout<<" "<<*itr2;
        }
        cout<<endl;
    }

    return 0;
}