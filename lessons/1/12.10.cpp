//
// Created by Jugglyuser on 12.10.2022.
//

#include "iostream"
#include "cmath"

using namespace std;

//void swapn(int &, int &);
//
//void test(){
//    int a, b;
//    cin >> a >> b;
//    cout << a << " " << b << endl;
//    swapn(a, b);
//    cout << a << " " << b << endl;
//}
//
//void swapn(int &a, int &b){
//    int c;
//    c = a;
//    a = b;
//    b = c;
//}

//int* ReadArray(int);
//
//int main(){
//    int n;
//    int* a;
//    cin >> n;
//    a = ReadArray(n);
//}
//
//int* ReadArray(int n){
//    int* a = new int[n];
//    for(int i = 0; i < n; i++){
//        cin >> a[i];
//    }
//    return a;
//}

void quest(){
    int n;
    int l(0);
    cin >> n;
    int** a = new int*[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    while(l < n){
        for(int i = 0; i <= l; i++){
            cout << a[l-i][i] << " ";
        }
        l += 1;
    }
    l = 0;
    while(l < n){
        for(int i = 1; i < n-l; i++){
            cout << a[n-i][i+l] << " ";
        }
        l += 1;
    }

}
//   31       22       13       32         23         33
//n-1, 1 | n-2, 2 | n-3, 3 | n-1, 1+1 | n-2, 2+1 | n-1, 1+2