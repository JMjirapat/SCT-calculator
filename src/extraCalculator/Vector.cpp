#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;


double sub(){
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
    return x3,y3,z3;
}

double mul(){
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
    return x2,y2,z2;
}

double dot(){
    double x1,y1,z1,x2,y2,z2;
    double result;
    cout << "input (x1 y1 z1): ";
    cin >> x1 >> y1 >> z1;
    cout << "input (x2 y2 z2): ";
    cin >> x2 >> y2 >> z2;
    result = (x1*x2)+(y1*y2)+(z1*z2);
    cout << "(" << x1 << " " << y1 << " " << z1 << ")";
    cout << ".";
    cout << "(" << x2 << " " << y2 << " " << z2 << ")";
    cout << " = ";
    cout << result;
    return result;
}

double cross(){
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
    return result1, result2, result3;
}

double mag(){
    double x,y,z;
    double result;
    cout << "input | x y z |: \n";
    cin >> x >> y >> z;
    result = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    cout << "| "<< x << " " << y << " " << z << " | = " << result;
    return result;
}

double ang(){
    double result1;
    double result2;
    double result3;
    double result4;
    double result5;
    double x1,y1,z1;
    double x2,y2,z2;
    cout << "input (x1 y1 z1): \n";
    cin >> x1 >> y1 >> z1;
    cout << "input (x2 y2 z2): \n";
    cin >> x2 >> y2 >> z2;
    result1 = (x1*x2)+(y1*y2)+(z1*z2);
    result2 = sqrt(pow(x1,2)+pow(y1,2)+pow(z1,2));
    result3 = sqrt(pow(x2,2)+pow(y2,2)+pow(z2,2));
    result4 = acos((result1)/(result2*result3));
    result5 = result4/(M_PI / 180);
    cout << result5 << " degrees";
    return result5;

}

double unit(){
    double x1,y1,z1;
    double x2,y2,z2;
    double result;
    cout << "input (x1 y1 z1): \n";
    cin >> x1 >> y1 >> z1;
    result = sqrt(pow(x1,2)+pow(y1,2)+pow(z1,2));
    cout << endl;
    cout << "( " << x1 << "/" << result << " " << y1 << "/" << result << " " << z1 << "/" << result << " )";
    x2 =  x1/result;
    y2 =  y1/result;
    z2 =  z1/result;
    double x2,y2,z2;
}

double proj(){
    double x1,y1,z1,x2,y2,z2;
    double result1, result2, result3;
    cout << "input v=(x1 y1 z1): ";
    cin >> x1 >> y1 >> z1;
    cout << "input u=(x2 y2 z2): ";
    cin >> x2 >> y2 >> z2;
    cout << "proj u(v) =";
    result1 = ((x1*x2)+(y1*y2)+(z1*z2))/(pow(sqrt(pow(x2,2)+pow(y2,2)+pow(z2,2)),2))*x2;
    result2 = ((x1*x2)+(y1*y2)+(z1*z2))/(pow(sqrt(pow(x2,2)+pow(y2,2)+pow(z2,2)),2))*y2;
    result3 = ((x1*x2)+(y1*y2)+(z1*z2))/(pow(sqrt(pow(x2,2)+pow(y2,2)+pow(z2,2)),2))*z2;
    cout << "(" << result1 << " " << result2 << " " << result3 << ")";
    return result1, result2, result3;
}

int main(){
    return 0;
}