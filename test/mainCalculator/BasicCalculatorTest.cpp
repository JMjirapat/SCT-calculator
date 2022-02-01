#include <iostream>
#include "../../include/mainCalculator/BasicCalculator.h"

using namespace std;

int main()
{
    string input;
    float ans = nanf("");
    while (1){
        cin >> input;
        ans = basic(input.c_str(), 0, input.length(), &ans);
        cout << "\t\t\t= " << ans << "\n\n";
    }
}