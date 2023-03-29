//
// Created by Jugglyuser on 20.02.2023.
//
#include "iostream"

using namespace std;

int nod(int x, int y);
int nok(int x, int y);
typedef struct fraction{
    fraction() = default;
    fraction(int a, int b){
        this->nominator = a;
        if(b == 0){
            this->denominator = 1;
        }else{
            this->denominator = b;
        }
        reduce(this->nominator, this->denominator);
    }

    static void reduce(int &x, int &y){
        int n = nod(x, y);
        x = x/n;
        y = y/n;
    }

    void print() const{
        cout << this->nominator << "/" << this->denominator << endl;
    }

    fraction operator+(const fraction a) const{
        int n = nok(a.denominator, denominator);
        return {a.nominator*(n/a.denominator) + nominator*(n/denominator), n};
    }

    fraction operator-(const fraction a) const{
        int n = nok(a.denominator, denominator);
        return {a.nominator*(n/a.denominator) - nominator*(n/denominator), n};
    }

    fraction operator*(const fraction a) const{
        return {nominator*a.nominator, denominator*a.denominator};
    }

    fraction operator/(const fraction a) const{
        return {nominator*a.denominator, denominator*a.nominator};
    }

    int nominator = 0;
    int denominator = 1;
} frac;