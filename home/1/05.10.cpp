//
// Created by Jugglyuser on 06.10.2022.
//1192, 1489, 1068

#include "iostream"
#include "cmath"

using namespace std;

double ball(double v, double a, double k){
    double r, pi;
    pi = 3.1415926535;
    r = (a/180)*pi;
    return round(((v*v*sin(2*r)*k)/(10*(k-1)))*100)/100.0;
}

double coords(int a, int b, int c, double x1, double y1, double x2, double y2){
    double result(0), z1, z2, f[2];
    int cs;
    bool inX, inY;
    inX = (x1 <= c + a) and (x1 >= c);
    inY = (y1 <= 2 * b + c) and (y1 >= b + c);
    (inX and (y1 <= b) and (y1 >= 0)) ? cs = 0 : 0;
    (inX and (y1 <= b + c) and (y1 >= b)) ? cs = 1 : 0;
    (inX and inY) ? cs = 0 : 2;
    (inX and (y1 <= 2 * (b + c)) and (y1 >= 2 * b + c)) ? cs = 3 : 0;
    (inY and (x1 <= c) and (x1 >= 0)) ? cs = 4 : 0;
    (inY and (x1 <= 2 * c + a) and (x1 >= c + a)) ? cs = 5 : 0;
    switch(cs){
        case 0:
            z1 = 0;
            y1 = b - y1;
            x1 = x1 - c;
            cout << "0" << endl;
            break;
        case 1:
            x1 = x1 - c;
            z1 = y1 - b;
            y1 = 0;
            cout << "1" << endl;
            break;
        case 2:
            z1 = c;
            y1 = y1 - (b+c);
            x1 = x1 - c;
            cout << "2" << endl;
            break;
        case 3:
            x1 = x1 - c;
            z1 = y1 - b;
            y1 = b;
            cout << "3" << endl;
            break;
        case 4:
            z1 = x1;
            y1 = y1 - (b+c);
            x1 = 0;
            cout << "4" << endl;
            break;
        case 5:
            z1 = 2*c + a - x1;
            y1 = y1 - (b+c);
            x1 = a;
            cout << "5" << endl;
            break;
    }
    inX = (x2 <= c + a) and (x2 >= c);
    inY = (y2 <= 2 * b + c) and (y2 >= b + c);
    (inX and (y2 <= b) and (y2 >= 0)) ? cs = 0 : 0;
    (inX and (y2 <= b + c) and (y2 >= b)) ? cs = 1 : 0;
    (inX and inY) ? cs = 0 : 2;
    (inX and (y2 <= 2 * (b + c)) and (y2 >= 2 * b + c)) ? cs = 3 : 0;
    (inY and (x2 <= c) and (x2 >= 0)) ? cs = 4 : 0;
    (inY and (x2 <= 2 * c + a) and (x2 >= c + a)) ? cs = 5 : 10;
    switch(cs){
        case 0:
            z2 = 0;
            y2 = b - y2;
            x2 = x2 - c;
            cout << "0" << endl;
            break;
        case 1:
            x2 = x2 - c;
            z2 = y2 - b;
            y2 = 0;
            cout << "1" << endl;
            break;
        case 2:
            z2 = c;
            y2 = y2 - (b + c);
            x2 = x2 - c;
            cout << "2" << endl;
            break;
        case 3:
            x2 = x2 - c;
            z2 = y2 - b;
            y2 = b;
            cout << "3" << endl;
            break;
        case 4:
            z2 = x2;
            y2 = y2 - (b + c);
            x2 = 0;
            cout << "4" << endl;
            break;
        case 5:
            z2 = 2 * c + a - x2;
            y2 = y2 - (b + c);
            x2 = a;
            cout << "5" << endl;
            break;
    }
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
}

int summ(){
    int n;
    cin >> n;
    (n > 0) ? cout << ((1+n)*n)/2 : cout << ((1+n)*(abs(n)+2))/2;
    return 0;
}
