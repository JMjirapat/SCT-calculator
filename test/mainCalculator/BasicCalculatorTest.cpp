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
            cout << "abs(_) : brah brah" << endl;
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