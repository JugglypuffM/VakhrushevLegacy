//
// Created by Jugglyuser on 02.11.2022.
//

#include "iostream"
#include "fstream"

using namespace std;

int** read(string s){
    int n, m;
    ifstream fin(s);
    fin >> n >> m;
    int** a = new int*[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[m];
        for(int j = 0; j < m; j++){
            fin >> a[i][j];
        }
    }
    return a;
}

void gensh(){
    int n, m;
    string s;
    cin >> s;
    int** a = read(s);
}