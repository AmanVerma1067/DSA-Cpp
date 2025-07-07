#include <iostream>
using namespace std;
class binary
{
    string s;
    // here s is by default private
private:
    void chkBin(void);
public:
    void read(void);
    void ones(void);
    void display(void);
};
void binary ::read(void)
{
    cout << "Enter a binary number " << endl;
    cin >> s;
}
void binary ::chkBin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '0' && s[i] != '1')
        {
            cout << "Incorrect Binary Format" << endl;
            exit(0);
        }
    }
}
void binary ::ones(void)
{
    chkBin();
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';
    }
}
void binary ::display(void)
{
    cout << "Displaying your bianry number " << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}

int main()
{
    binary b;
    b.read();
    // b.chkBin(); this function is private and thats why it is nested in ones function to be called
    // it cant be called like this
    b.display();
    b.ones();
    b.display();
    
    return 0;
}