#include <iostream>
#include "helloworld.h"
using namespace std;

int main()
{
    cout << "please enter your name: ";
    string name;
    cin >> name;
    cout << HelloWorld(name) << endl;
    //cout << PrintHelloWorld();
    return 0;
}