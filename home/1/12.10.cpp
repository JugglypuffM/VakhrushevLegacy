//
// Created by Jugglyuser on 06.10.2022.
//В ноушене

#include "iostream"
#include "cmath"

using namespace std;

double cocks(double x, double e){
    double result(1), a(1);
    int c(2);
    while(abs(a) > e){
        a = a*x*x*(-1.0)/c/(c-1);
        c += 2;
        result += a;
    }
    return result;
}

int eucludus(int a, int b){
    int ost;
    do{
        if(a < b){ swap(a, b);}
        ost = a%b;
        a = b;
        b = ost;
    }while(ost != 0);
    return a;
}

int numSum(int x){
    int result(0);
    while(x != 0){
        result += x%10;
        x = x/10;
    }
    return result;
}

int numLen(int x){
    int result(0);
    while(x != 0){
        result += 1;
        x = x/10;
    }
    return result;
}

int tens(int m, int n){
    int result(0), h;
    for(int i = m; i < n+1; i++){
        cout << i << endl;
        for(int j = 1; j < 9*numLen(i); j++){
            if(i == i - j + numSum(i - j)){
                result++;
                cout << i-j << endl;
                cout << numSum(i-j) << endl;
                cout << "" << endl;
                break;
            }
        }
    }
    return result;
}