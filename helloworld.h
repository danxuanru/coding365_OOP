#include <iostream>
using namespace std;

string PrintHelloWorld()
{
    return "Hello World! \n";
}

string HelloWorld(string name)
{
    string output = "Hello World, ";
    output += name;
    output += "!";
    return output;
}