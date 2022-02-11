#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

void sub(){
    double x1,y1,z1;
    double x2,y2,z2;
    double x3,y3,z3;
    char x;
    while(x != '+' && x != '-'){
    cout << "input + or -" << endl;
    cin >> x;
    }
    cout << "input (x1 y1 z1): ";
    cin >> x1 >> y1 >> z1;
    cout << "input (x2 y2 z2): ";
    cin >> x2 >> y2 >> z2;
    cout << "(" << x1 << " " << y1 << " " << z1 << ")";
    if(x == '+'){
        cout << " + ";
        x3 = x1+x2;
        y3 = y1+y2;
        z3 = z1+z2;
    }else if(x == '-'){
        cout << " - ";
        x3 = x1-x2;
        y3 = y1-y2;
        z3 = z1-z2;
    }
    cout << "(" << x2 << " " << y2 << " " << z2 << ")";
    cout << " = ";
    cout << "(" << x3 << " " << y3 << " " << z3 << ")";
}


void mul(){
    double num;
    double x1,y1,z1;
    double x2,y2,z2;
    char x;
    while(x != '*' && x != '/'){
    cout << "input * or /" << endl;
    cin >> x;
    }
    cout << "input num: ";
    cin >> num;
    cout << "input (x y z): ";
    cin >> x1 >> y1 >> z1;
    cout << "(" << x1 << " " << y1 << " " << z1 << ")";
    if(x == '*'){
        cout << " * ";
        x2 = x1*num;
        y2 = y1*num;
        z2 = z1*num;
    }else if(x == '/'){
        cout << " / ";
        x2 = x1/num;
        y2 = y1/num;
        z2 = z1/num;
    }
    cout << num << " = (" << x2 << " " << y2 << " " << z2 << ")"; ;
}
/*
double dot(){

}

double cross(){

}

double mag(){

}

double ang(){

}

double unit(){

}

double proj(){

}

double sproj(){

}
*/

int main(){
    mul();
    return 0;
}