//
// Created by Jugglyuser on 18.10.2022.
//

#include "iostream"

using namespace std;

void printArray(int*a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

///////////////////////////////////////////////////

void unrealStory(){
    int n, result(0);
    cin >> n;
    int k[n];
    for(int i = 0; i < n+1; i++){
        k[i] = 0;
    }
    for(int i = 0; i < n+1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        k[a-1] += c;
        k[b] -= c;
    }
    for(int i = 0; i < n; i ++){
        result += k[i];
        cout << result << " ";
    }
}

////////////////////////////////////////////////////

void countDiff(){
    int n, result(0);
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            (a[i] != a[j]) ? result++ : 0;
        }
    }
    cout << result;
}

//////////////////////////////////////////////////

bool mutuallyPrime(int a, int b){
    for(int i = 2; i < min(a, b)/2 + 1; i++){
        if((a%i == 0) and (b%i == 0)){
            return false;
        }
    }
    return true;
}

bool everyMutuallyPrime(int*k, int a, int b, int c){
    for(int i = a; i < b; i++){
        if(not mutuallyPrime(k[i], c)){
            return false;
        }
    }
    return true;
}

void maxSubSum(){
    int n, result(0), sum(0), s(0), e;
    cin >> n;
    e = n-1;
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        sum += a[i];
        e = i;;
        if(everyMutuallyPrime(a, s, e, a[i])) {
            result = max(result, sum);
        }else {
            sum = a[i];
            s = i;
        }
    }
    result = max(result, sum);
    cout << result << endl;
    for(int i = s; i < e+1; i++){
        cout << a[i] << " ";
    }
}