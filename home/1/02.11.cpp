//
// Created by Jugglyuser on 26.10.2022.
//

#include "iostream"
#include "string"
#include "cmath"

using namespace std;

bool isPrime(int x){
    for(int i = 2; i < sqrt(x)+1; i++){
        if(x%i == 0){return false;}
    }
    return true;
}

void primeNum(){
    int a[100000];
    a[1] = 2;
    a[2] = 3;
    for(int i = 3; i < 100000; i++){
        a[i] = a[i-1] + 2;
        while (not isPrime(a[i])){a[i] += 2;}
    }
    string s, x;
    getline(cin, s);
    int n = stoi(s);
    for(int i = 0; i < n; i++){
        getline(cin, x);
        int l = stoi(x);
        cout << a[l] << endl;
    }
}

///////////////////////////////////////////////////////

bool consistOf(string a, string b){
    bool f(false);
    for(int i = 0; i < a.length(); i++){
        for(int j = 0; j < b.length(); j++){
            if(a[i] == b[j]){
                f = true;
                break;
            }
        }
        if(f){
            f = false;
            continue;
        }
        return false;
    }
    return true;
}

void stars(){
    string s, result;
    int m(0);
    cin >> s;
    int p = s.length() + 1;
    for(int i = 0; i < p; i++){
        for(int j = i+1; j < p; j++){
            int amount = 0;
            string w1 = s.substr(i, j-i);
            for(int x = 0; x < p; x++){
                for(int y = x+1; y < p; y++){
                    string w2 = s.substr(x, y-x);
                    if(consistOf(w2, w1)){
                        amount += 1;
                    }
                }
            }
            if(amount == m){
                if(result.length() > w1.length()){
                    result = w1;
                }
            }
            if(amount > m){
                m = amount;
                result = w1;
            }
        }
    }
    cout << result << endl;
}

///////////////////////////////////////////////////////

void cypher(){
    string str;
    cin >> str;

    string s = "";
    s += str[0];

    int c = 1;
    for(int i = 1; i < str.length(); ++i){
        s = str[i] + s;
        int max = 0;

        int n = s.length();
        int *pi = new int[n]{};

        for (int i = 1; i < n; ++i) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])  ++j;
            if(j > max) max = j;
            pi[i] = j;
        }
        c += s.length() - max;
    }
    cout << c << endl;

}