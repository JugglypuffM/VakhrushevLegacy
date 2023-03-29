//
// Created by Jugglyuser on 06.10.2022.
//

#include "iostream"

using namespace std;

void arrayIn(int* a, int n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void arrayPt(int* a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

void arrayRev(int* a, int n){
    for(int i = 0; i < n/2; i++){
        int tmp = a[i];
        a[i] = a[n - i-1];
        a[n - i-1] = tmp;
    }
}
