//
// Created by Jugglyuser on 20.12.2022.
//

#include "home.h"

using namespace std;

int nod(int a, int b){
    while (a && b)
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    return a+b;
}


int nok(int a, int b){
    return (a*b)/nod(a, b);
}