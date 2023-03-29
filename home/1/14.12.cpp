//
// Created by Jugglyuser on 13.12.2022.
//

#include "iostream"
#include "iomanip"
#include "cmath"
#include "fstream"
#include "string"
#include "vector"
#include "set"

using namespace std;

int air() {
    int n;
    cin >> n;
    string *A = new string[n];
    for (int i=0; i<n; i++) cin >> A[i];

    vector<int> answer;
    for (int i=1; i <= n; i++) {
        if (n%i!=0) continue;

        bool good = true;
        set<string> S;
        for (int j=0; j<n/i && good; j++) {
            string current = "unknown";
            for (int k=0; k<i; k++) {
                if (current == "unknown") {
                    if (A[j*i+k] != "unknown") {
                        current = A[j*i+k];
                        if (S.find(current) == S.end()) {
                            S.insert(current);
                        } else {
                            good = false;
                            break;
                        }
                    }
                } else if(A[j*i+k] != "unknown" && A[j*i+k]!=current) {
                    good = false;
                    break;
                }
            }
        }
        if (good) {
            answer.push_back(n/i);
        }
    }
    if (answer.size()==0) {
        cout << "Igor is wrong.";
    } else {
        for (int i=answer.size()-1; i>=0; i--) {
            cout << answer[i] << " ";
        }
    }
    return 0;
}

void qsortRecursive(int* example, string* mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = example[size / 2];
    do {
        while(example[i] < mid) {
            i++;
        }
        while(example[j] > mid) {
            j--;
        }
        if (i <= j) {
            string tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            int tmp1 = example[i];
            example[i] = example[j];
            example[j] = tmp1;

            i++;
            j--;
        }
    } while (i <= j);
    if(j > 0) {
        qsortRecursive(example, mas, j + 1);
    }
    if (i < size) {
        qsortRecursive(&example[i], &mas[i],  size - i);
    }
}

void sixth_sort(){
    string string_n, string_s;
    getline(cin, string_s);
    char s = string_s[0];
    getline(cin, string_n);
    int n = stoi(string_n);
    string* text = new string[n];
    int* sort = new int[n];
    for(int i = 0; i < n; i++){
        getline(cin, text[i]);
    }
    int c(0), m(0);
    bool f(false);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < text[i].length(); j++){
            if(text[i][j] == ' '){
                if(c >= m){
                    m = c;
                }
                c = 0;
                continue;
            }
            if(text[i][j] == s){
                f = true;
            }
            c++;
        }
        if(c >= m){
            m = c;
        }
        if(f){
            sort[i] = m;
            f = false;
        } else{
            sort[i] = 0;
        }
        c = 0;
        m = 0;
    }
    qsortRecursive(sort, text, n);
    for(int i = n-1; i > -1; i--){
        if(sort[i] != 0){
            cout << text[i] << endl;
            f = true;
        }
    }
    if(!f){
        for(int i = 0; i < n; i++){
            cout << text[i] << endl;
        }
    }
}