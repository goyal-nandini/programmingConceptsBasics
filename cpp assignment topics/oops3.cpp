//static and dynamic allocation
#include<iostream>
using namespace std;


class Cars{
    
    int health;
    char level;

    public:
    char getLevel(){
        return level;
    }
    int getHealth(){
        return health;
    }

    void setLevel(int l){
        level = l;
    }
    void setHealth(int h){
        health = h;
    }
};

int main(){
    //static
    Cars a;
    a.setHealth(80);
    a.setLevel('B');
    cout << "level is  " << a.getLevel() << endl;
    cout << " health is " << a.getHealth() << endl;

    //dynamicallly
    Cars *b = new Cars;
    b->setLevel('A');
    b->setHealth(70);
    cout << "level is  " << (*b).getLevel() << endl;
    cout << " health is " << (*b).getHealth() << endl;
    //OR
    cout << "level is  " << b->getLevel() << endl;
    cout << " health is " << b->getHealth() << endl;
    return 0;
}
