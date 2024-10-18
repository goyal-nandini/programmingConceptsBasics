#include <iostream>
using namespace std;

int main()
{
    bool flag = true;
    cout << "flag is: " << flag << endl;
    flag = false;
    cout << "flag is: " << flag << endl;

    string user;
    enum semester
    {
        winter = 76,
        monsoon,
        summer
    };
    semester seasons;
    seasons = winter;
    cout << seasons << "\n";
    
    cout << "The use of enum in a loop: \n";
    for (int i = winter; i <= summer; i++)
    {
        cout << i << " ";
    }

    return 0;
}