//
// Created by Jugglyuser on 26.10.2022.
//

#include "iostream"
#include "string"

using namespace std;

bool isInArray(string*a, int n, string x){
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            return true;
        }
    }
    return false;
}

void bayanas(){
    int result(0);
    string x, s;
    getline(cin, s);
    int n = stoi(s);
    string* a = new string[n];
    for(int i = 0; i < n; i++){
        getline(cin, x);
        (isInArray(a, i, x)) ? result++ : result;
        a[i] = x;
    }
    cout << result;
}


