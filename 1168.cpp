
#include <iostream>
#include <math.h>

using namespace std;


#include <sstream>
string doubleToString(const double &val)
{
    char* chCode;
    chCode = new char[20];
    sprintf(chCode, "%.2lf", val);
    std::string str(chCode);
    delete[]chCode;
    return str;
}


int main(int argc, char** argv) {
    //使用convertToString
    cout<<doubleToString(1.2);
}
