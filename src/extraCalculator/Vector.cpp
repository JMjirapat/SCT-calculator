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

double dot(double x1,double y1, double z1, double x2,double y2, double z2){
    double result;
    result = (x1*x2)+(y1*y2)+(z1*z2);
    cout << "(" << x1 << " " << y1 << " " << z1 << ")";
    cout << ".";
    cout << "(" << x2 << " " << y2 << " " << z2 << ")";
    cout << " = ";
    cout << result;
    return 0;
}

void cross(){
    double a,b,c;
    double d,e,f;
    double result1;
    double result2;
    double result3;
    cout << "| i j k |\n";
    cout << "| a b c |\n";
    cout << "| d e f |\n";
    cout << "input (a b c): \n";
    cin >> a >> b >> c;
    cout << "input (d e f): \n";
    cin >> d >> e >> f;
    result1 = ((b*f)-(c*e));
    result2 = ((c*d)-(a*f));
    result3 = ((a*e)-(b*d));
    cout << "| i j k |\n";
    cout << "| " << a << " " << b << " " << c << " | =   (" << result1 << ")i+(" << result2 << ")j+(" << result3 << ")k\n";
    cout << "| " << d << " " << e << " " << f << " |";

}

double mag(double a, double b, double c){
    double result;
    result = sqrt(pow(a,2)+pow(b,2)+pow(c,2));
    cout << "| "<< a << " " << b << " " << c << " | = " << result;
    return result;
}
/*
void ang(){
    double result1;
    double result2;
    double result3;
    double result4;
    double x1,y1,z1;
    double x2,y2,z2;
    cout << "input (x1 y1 z1): \n";
    cin >> x1 >> y1 >> z1;
    cout << "input (x2 y2 z2): \n";
    cin >> x2 >> y2 >> z2;
    result1 = dot(x1,y1,z1,x2,y2,z2);
    cout << endl;
    result2 = mag(x1,y1,z1);
    cout << endl;
    result3 = mag(x2,y2,z2);
    cout << endl;
    result4 = acos((result1)/(result2*result3));
    cout << result4/(M_PI / 180);
}*/

void unit(){
    double x1,y1,z1;
    double result;
    cout << "input (x1 y1 z1): \n";
    cin >> x1 >> y1 >> z1;
    result = mag(x1,y1,z1);
    cout << endl;
    cout << "( " << x1 << "/" << result << " " << y1 << "/" << result << " " << z1 << "/" << result << " )" ;
}

void proj(){

}

/*void sproj(){

}
*/

int main(){
    ang();
    return 0;
}