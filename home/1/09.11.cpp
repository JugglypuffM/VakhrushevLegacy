//
// Created by Jugglyuser on 08.11.2022.
//

#include <fstream>
#include "iostream"
#include "string"

using namespace std;

int* parseString(string a){
    int*r = new int[2];
    for(int i = 0; i < a.length(); i++){
        if(a[i] == ' '){
            r[0] = stoi(a.substr(0, i));
            r[1] = stoi(a.substr(i+1));
            break;
        }
    }
    return r;
}

void logs(){
    string s;
    getline(cin, s);
    int n = stoi(s);
    cout << "+------------------------------+--------+-------------+\n"
            "|Contest name                  |Date    |ABCDEFGHIJKLM|\n"
            "+------------------------------+--------+-------------+" << endl;
    while(n != 0){
        string result;
        getline(cin, s);
        result = "|" + s + "                              ";
        result = result.substr(0, 31);
        getline(cin, s);
        result += "|" + s + "|";
        getline(cin, s);
        int*a = parseString(s);
        string alph = "ABCDEFGHIJKLM";
        string comp = ".............";
        string emp = "            ";
        comp = comp.substr(0, a[0]) + emp.substr(0, 13 - a[0]);
        for(int i = 0; i < a[1]; i++){
            getline(cin, s);
            if(s.substr(2) == "A"){
                comp[alph.find(s[0])] = 'o';
            } else if(comp[alph.find(s[0])] != 'o'){
                comp[alph.find(s[0])] = 'x';
            }
        }
        result += comp + "|\n";
        result += "+------------------------------+--------+-------------+";
        cout << result << endl;
        n--;
    }
}

////////////////////////////////////////////////////////////////////////////////////
int dv(int a, int b){
    if(a%b == 0){return a/b;} else{return (a/b)+1;}
}

void columns(){
    string c, emp("    ");
    int n, k;
    cin >> n >> k;
    string*s = new string[n];
    for(int i = 0; i < n; i++){
        cin >> c;
        s[i] = emp.substr(0, 3 - c.length()) + c;
    }
    string**res = new string*[k];
    int f(0);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < dv(n, k); j++){
            res[i] = new string[dv(n, k)];
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < dv(n, k); j++){
            if(f < n){
                res[i][j] = s[f];
                f++;
            }
            else{
                res[i][j] = "";
            }
        }
    }
    for(int j = 0; j < dv(n, k); j++){
        for(int i = 0; i < k; i++){
            cout << " " << res[i][j];
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////

void ier(){
    int n;
    cin >> n;
    string h;
    string*s = new string[n];
    for(int i = 0; i < n; i++){
        cin >> h;
        s[i] = h;
    }
    char c;
    cin >> c;
    for(int i = 0; i < n; i++){
        char x = s[i][0];
        if(x == c){
            cout << s[i] << endl;
        }
    }
}

////////////////////////////////////////////////////////
string fill(string s, int n){
    string res(s);
    for(int i = 0; i < n-s.length(); i++){
        res = "0" + res;
    }
    return res;
}

void s0mBigMafsPlus(){
    string n, m, r, x, y;
    ifstream fin(R"(C:\things\CLion\home\09.11(in).txt)");
    ofstream fout(R"(C:\things\CLion\home\09.11(out).txt)");
    fin >> n >> m;
    fin.close();
    if(n.length() < m.length()){ swap(n, m);};
    m = fill(m, n.length());
    int ext = 0;
    for(int i = m.length()-1; i > 0; i--){
        x = n[i];
        y = m[i];
        int tmp = stoi(x) + stoi(y) + ext;
        r = to_string(tmp%10) + r;
        ext = tmp/10;
    }
    x = n[0];
    y = m[0];
    r = to_string(stoi(x) + stoi(y) + ext) + r;
    fout << r;
}

string replaceZero(string s){
    string a;
    a = s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != '0'){break;}
        a = a.substr(1);
    }
    return a;
}

void s0mBigMafsMinus(){
    bool flag(false);
    string n, m, r, x, y, o;
    ifstream fin(R"(C:\things\CLion\home\09.11(in).txt)");
    ofstream fout(R"(C:\things\CLion\home\09.11(out).txt)");
    fin >> n >> m;
    fin.close();
    if(stoi(n) < stoi(m)){
        swap(n, m);
        flag = true;
    }
    m = fill(m, n.length());
    int ext = 0;
    for(int i = m.length()-1; i > 0; i--){
        x = n[i];
        y = m[i];
        if(stoi(x) - ext < stoi(y)){
            ext = 1;
            int temp = 10 + stoi(x) - stoi(y) - ext;
            r = to_string(temp) + r;
        } else{
            ext = 0;
            int temp = stoi(x) - stoi(y) - ext;
            r = to_string(temp) + r;
        }
    }
    x = n[0];
    y = m[0];
    r = to_string(abs(stoi(x) - ext - stoi(y))) + r;
    if(r[0] == '0'){r = replaceZero(r);}
    if(flag){r = "-" + r;}
    fout << r;
}