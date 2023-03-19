#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long int number = 0, temp = 0;
int main()
{
    int factor = 2, inf = 0, len = 0, first = 0;
    cin >> number;
    inf = sqrt(number)+1;
    vector<int> ans;
    for(factor=2;factor<inf;factor++)
    {
        int j, temp = 1;
        for(j=factor;j<=inf;j++)
        {
            temp *= j;
            if (number%temp != 0) break;
        }
        if(j-factor>len)
        {
            len = j - factor;
            first = factor;
        }
    }
    if (first == 0) cout << 1 << endl << number;
    else
    {
        cout << len << endl;
        for(int i=0;i<len;i++)
        {
            cout << first + i;
            if (i != len - 1) cout << "*";
        }
    }
    return 0;
}
