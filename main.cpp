#include <iostream>
#include <fstream>
#include "src/mainCalculator/BasicCalculator.cpp"
#include "src/extraCalculator/Vector.cpp"
#include "src/extraCalculator/LE.cpp"
#include "src/extraCalculator/complex.cpp"

using namespace std;

void extraCal();

void mainCal(bool &mainMode)
{
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "                             MAIN CALCULATOR                               " << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    string input;
    bool deg = true;
    double ans = nanf("");
    while (true)
    {
        cout << ">> ";
        cin >> input;
        if (input == "/help")
        {
            ifstream source("utils/help.txt");
            string textline;
            while (getline(source, textline))
            {
                cout << textline << endl;
            }
            source.close();
        }
        else if (input == "extra")
        {
            mainMode = false;
            break;
        }
        else if (input == "deg")
        {
            deg = true;
            cout << "change unit of angle to degree." << endl;
        }
        else if (input == "rad")
        {
            deg = false;
            cout << "change unit of angle to radian." << endl;
        }
        else
        {
            ans = basic(input.c_str(), 0, input.length(), deg, &ans);
            cout << fixed << "= " << ans << "\n";
        }
    }
}

void extraCal(bool &mainMode)
{
    char mode;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "                            EXTRA CALCULATOR                               " << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    ifstream source("utils/extra.txt");
    string textline;
    while (getline(source, textline))
    {
        cout << textline << endl;
    }
    source.close();
    cout << "Select the mode: ";
    cin >> mode;
    switch (mode)
    {
    case '1':
        break;
    case '2':
        mainVector();
        break;
    case '3':
        mainLE();
        break;
    case '4':
        mainComplex();
        break;
    case '5':
        mainMode = true;
        break;
    default:
        cout << endl
            << "Wrong mode!!" << endl;
        break;
    }
}

int main()
{
    ifstream source("utils/topic.txt");
    string textline;
    bool mainMode = true;
    while (getline(source, textline))
    {
        cout << textline << endl;
    }
    source.close();
    while (true)
    {
        if (mainMode)
            mainCal(mainMode);
        else
            extraCal(mainMode);
    }

    return 0;
}
