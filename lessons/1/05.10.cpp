//
// Created by Jugglyuser on 05.10.2022.
//

#include "iostream"
#include "cmath"

using namespace std;

int secondMax(){
    int a, max, max2;
    cin >> a;
    max = a;
    do{
        cin >> a;
        if(max <= a){
            max2 = max;
            max = a;
        } else if(max2 <= a){
            max2 = a;
        }
    }while(a != 0);
    return max2;
}

double sus(double x, double e){
    double result(x), a(x);
    int c(3);
    while(abs(a) > e){
        a = a*x*x*(-1.0)/c/(c-1);
        c += 2;
        result += a;
    }
    return result;
}

