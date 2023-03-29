//
// Created by Jugglyuser on 14.12.2022.
//
#include "iostream"
#include "iomanip"
#include "cmath"
#include "fstream"
#include "string"

using namespace std;

void magicker(){
    int n, s, g(0);
    cin >> n >> s;
    int* wheel = new int[n];
    for(int i = 0; i < n; i++){
        cin >> wheel[i];
    }
    if(s >= n){
        s = s-n*(s/n);
    }
    for(int i = s; i < n; i++){
        if(g < 10){
            cout << wheel[i];
            g++;
        }
    }
    for(int i = 0; i < s; i++){
        if(g < 10){
            cout << wheel[i];
            g++;
        }
    }
}

void magickers_hat(){
    int n, si(0), hi(0), gi(0), ri(0);
    string str_n;
    getline(cin, str_n);
    n = stoi(str_n);
    string* s = new string[n];
    string* h = new string[n];
    string* g = new string[n];
    string* r = new string[n];
    for(int i = 0; i < n; i++){
        string name;
        string facility;
        getline(cin, name);
        getline(cin, facility);
        if(facility == "Slytherin"){
            s[si] = name;
            si++;
            continue;
        }
        if(facility == "Hufflepuff"){
            h[hi] = name;
            hi++;
            continue;
        }
        if(facility == "Gryffindor"){
            g[gi] = name;
            gi++;
            continue;
        }
        if(facility == "Ravenclaw"){
            r[ri] = name;
            ri++;
            continue;
        }
    }
    cout << "Slytherin:" << endl;
    for(int i = 0; i < si; i++){
        cout << s[i] << endl;
    }
    cout << endl;
    cout << "Hufflepuff:" << endl;
    for(int i = 0; i < hi; i++){
        cout << h[i] << endl;
    }
    cout << endl;
    cout << "Gryffindor:" << endl;
    for(int i = 0; i < gi; i++){
        cout << g[i] << endl;
    }
    cout << endl;
    cout << "Ravenclaw:" << endl;
    for(int i = 0; i < ri; i++){
        cout << r[i] << endl;
    }
}