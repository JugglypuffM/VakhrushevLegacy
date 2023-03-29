//
// Created by Jugglyuser on 29.11.2022.
//

#include "iostream"
#include "iomanip"
#include "fstream"

using namespace std;

int up(int a, int b){
    if(a%b == 0){
        return a/b;
    } else{
        return a/b +1;
    }
}

void bubbleSort(int list[], int listLength){
    while(listLength--){
        bool swapped = false;
        for(int i = 0; i < listLength; i++){
            if(list[i] > list[i + 1]){
                swap(list[i], list[i + 1]);
                swapped = true;
            }
        }
        if(!swapped){break;}
    }
}

void democracy(){
    int k, res(0);
    cin >> k;
    int* q = new int[k];
    for(int i = 0; i < k; i++) {
        cin >> q[i];
    }
    bubbleSort(q, k);
    for(int i = 0; i < up(k,2); i++){
        res += up(q[i],2);
    }
    cout << res;
}

///////////////////////////////////////////////////////////

double size(double x1, double x2, double ah, double bh){
    double PI = 3.14159265358979323846;
    return PI*ah*ah*((x2 - x1) + 1/(3.0*bh*bh)*(x1*x1*x1 - x2*x2*x2));
}

void anas(){
    double a, b, r;
    int n;
    cin >>a >> b >> n;
    double dx = b/n;
    double x = -b/2 + dx;
    while (x <= b/2 + 0.000001){
        cout << fixed << setprecision(6) << size(x-dx, x, a/2, b/2) << endl;
        x += dx;
    }
}

/////////////////////////////////////////////////////////////

void form(){
    ifstream fin(R"(C:\things\CLion\home\30.11(in).txt)");
    ofstream fout(R"(C:\things\CLion\home\30.11(out).txt)");
    string s, text, tmp;
    int n, j(0), l(0);
    fin >> n;
    do{
        fin >> s;
        text += s + " ";
    }while(!fin.eof());
    string* words = new string[text.length()];
    for(int i = 0; i < text.length(); i++){
        if(text[i] == ' '){
            words[j] = tmp;
            tmp = "";
            j++;
        }else{
            tmp += text[i];
        }
    }
    for(int i = 0; i < j; i++){
        if(l + words[i].length() > n){
            fout << tmp.substr(0, tmp.length()-1) + '\n';
            tmp = words[i] + " ";
            l = words[i].length() + 1;
        }else{
            tmp += words[i] + " ";
            l += words[i].length() + 1;
        }
    }
    fout << tmp.substr(0, tmp.length()-1);
}