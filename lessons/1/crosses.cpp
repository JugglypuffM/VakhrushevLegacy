//
// Created by Jugglyuser on 28.09.2022.
//

#include "iostream"

using namespace std;

int InterS(int a, int b, int c, int d){
    int r;
    if (a>c){
        swap(a, c);
        swap(b, d);
    }
    (b<c) ? r=-1 : (b==c) ? r=0 : r = b-c;
    return r;
}

int main(){
    cout << InterS(1, 2, 3, 4) << endl;
    cout << InterS(1, 2, 2, 3) << endl;
    cout << InterS(1, 3, 2, 4) << endl;
    cout << InterS(1, 4, 2, 3) << endl;
    cout << InterS(2, 4, 1, 3) << endl;
    cout << InterS(2, 4, 1, 2) << endl;
    cout << InterS(3, 4, 1, 2) << endl;
}
