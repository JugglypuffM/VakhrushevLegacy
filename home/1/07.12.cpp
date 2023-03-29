//
// Created by Jugglyuser on 07.12.2022.
//

#include <bits/stdc++.h>

using namespace std;

int sort(){}

void army() {
    int n;
    cin >> n;
    int army[n*n];
    int formation[n][n];
    int c = 0;
    int delta = n/2;
    for (int i = 0; i < n*n; i++) {
        cin >> army[i];
    }
    sort(army, army + n*n, [](int a, int b) { return b < a; });
    int y = delta;
    for (int j = 0; j < n; j++){
        int x = delta;
        y += (y > delta ? -j : j);
        for (int i = 0; i < n; i++) {
            x += (x > delta ? -i : i);
            formation[x][y] = army[c++];
        }
    }
    for(int j=0; j < n; j++){
        for(int i=0; i < n; i++)
            cout << formation[i][j] << " ";
        cout << endl;
    }
}

void cheeses(){
    string s, a, b, c, result;
    int mode(-2), n(0), k(1);
    getline(cin, s);
    string* r = new string[s.length()];
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '{'){
            mode = 1;
            continue;
        }else if(s[i] == '('){
            mode = 2;
            continue;
        }else if(s[i] == '['){
            mode = 3;
            continue;
        } else if(mode == -2){
            r[n] = s[i];
            n++;
        }
        switch (mode) {
            case 1:
                if(s[i] != '}'){
                    a += s[i];
                } else{
                    mode = -1;
                }
                break;
            case 2:
                if(s[i] != ')'){
                    b += s[i];
                }else{
                    mode = -1;
                }
                break;
            case 3:
                if(s[i] != ']'){
                    c += s[i];
                }else{
                    mode = -1;
                }
                break;
        }
        if(mode == -1){
            r[n] = to_string(k);
            k++;
            if(k == 4){
                for(int j = 0; j < s.length(); j++){
                    if(r[j] == "1"){
                        r[j] = a;
                        a = "";
                    }
                    if(r[j] == "2"){
                        r[j] = b;
                        b = "";
                    }
                    if(r[j] == "3"){
                        r[j] = c;
                        c = "";
                    }
                }
                k = 1;
            }
            n++;
            mode = -2;
        }
    }
    int i = 0;
    while(!r[i].empty()){
        result += r[i] ;
        i++;
    }
    cout << (char)toupper(result[0]);
    for(int j = 1; j < result.length(); j++){
        cout << (char)tolower(result[j]);
    }
}