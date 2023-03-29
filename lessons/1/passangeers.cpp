//
// Created by Jugglyuser on 29.09.2022.
//

#include "iostream"

using namespace std;

double comfort(double h, double v, double t, double x){
    double tm, tn;
    if(x > h/t){
        tm = 0;
        tn = h/(x);
    }
    else{
        tm = (h - t*x)/(v-x);
        tn = t;
    }
    cout << tm << " " << tn << endl;
    return 0;
}