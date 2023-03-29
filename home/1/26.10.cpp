//
// Created by Jugglyuser on 25.10.2022.
//

#include "iostream"

using namespace std;

void hotel(){
    int n;
    cin >> n;
    int** arr = new int*[n];
    int k = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i] = new int[n];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            arr[i - j][j] = k;
            k++;
        }
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i <= n - 1 - j; i++) {
            arr[n-1-i][j+i] = k;
            k++;
        }
    }
    for (int i=0; i<n; i++) {
        for(int j=n-1; j>=0; j--) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////

