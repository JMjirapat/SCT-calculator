#include <iostream>
#include "../../include/mainCalculator/BasicCalculator.h"

using namespace std;

int main()
{
    string input;
    bool deg = true;
    double ans = nanf("");
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "  ____   ____ _____                     _            _       _             " << endl;
    cout << " / ___| / ___|_   _|           ___ __ _| | ___ _   _| | __ _| |_ ___  _ __  " << endl;
    cout << " \\___ \\| |     | |    _____   / __/ _` | |/ __| | | | |/ _` | __/ _ \\| '__| " << endl;
    cout << "  ___) | |___  | |   |_____| | (_| (_| | | (__| |_| | | (_| | || (_) | |    " << endl;
    cout << " |____/ \\____| |_|            \\___\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|    " << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "                               MAIN CALCULATOR                            " << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Type \"/help\" to display information that can help." << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    while (true){
        cout << ">> ";
        cin >> input;
        if(input == "/help"){
            cout << "Command : detail" << endl;
            cout << "extra : move to extra calculator" << endl;
            cout << "deg : change unit of angle to degree." << endl;
            cout << "rad : change unit of angle to radian." << endl;
            cout << "abs(_) : absolute value" << endl;
            cout << "ln(_) : the natural logarithm of a number is its logarithm to the mathematical constant e" << endl;
            cout << "log(_) : the logarithm base 10 is called the decimal or common logarithm" << endl;
            cout << "e : is a mathematical constant approximately equal to 2.71828" << endl;
            cout << "pi : is a mathematical constant approximately equal to 3.14159" << endl;
            cout << "sin(_) : to find sin value of that number" << endl;
            cout << "cos(_) : to find cos value of that number" << endl;
            cout << "tan(_) : to find tan value of that number" << endl;
            cout << "asin(_) : to find asin value of that number" << endl;
            cout << "acos(_) : to find acos value of that number" << endl;
            cout << "atan(_) : to find atan value of that number" << endl;
            cout << "fac(_) : to find factorial value of that number" << endl;
            cout << "ans : show answer" << endl;
        }else if(input == "deg"){
            deg = true;
            cout << "change unit of angle to degree." << endl;
        }else if(input == "rad"){
            deg = false;
            cout << "change unit of angle to radian." << endl;
        }else{
            ans = basic(input.c_str(), 0, input.length(), deg, &ans);
            cout << fixed << "= " << ans << "\n";
        }
    }
    return 0;
}