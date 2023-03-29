//
// Created by Jugglyuser on 22.11.2022.
//

#include "iostream"

using namespace std;

bool figures(int a, int b){
    int fa(0), fb(0), x(a), y(b);
    bool f(false);
    if(a < b){
        swap(a, b);
        f = true;
    }
    while (a > 0){
        fa += a%10;
        a = a/10;
        if(b > 0){
            fb += b%10;
            b = b/10;
        }
    }
    if(fa == fb){
        return x > y;
    }
    if(fa > fb){
        if(f){
            return false;
        }
        return true;
    }
    if(f){
        return true;
    }
    return false;
}

bool dividers(int a, int b){
    int fa(0), fb(0), x(a), y(b);
    bool f(false);
    if(a < b){
        swap(a, b);
        f = true;
    }
    for(int i = 2; i < a/2 + 1; i++){
        if(a%i == 0){fa++;}
        if(b%i == 0){fb++;}
    }
    if(fa == fb){
        return x > y;
    }
    if(fa > fb){
        if(f){
            return false;
        }
        return true;
    }
    if(f){
        return true;
    }
    return false;
}

bool evens(int a, int b){
    int fa(1), fb(1), x(a), y(b);
    bool f(false);
    if(a < b){
        swap(a, b);
        f = true;
    }
    while (a > 0){
        if((a%10)%2 == 0){
            fa *= a%10;
        }
        a = a/10;
        if(b > 0){
            if((b%10)%2 == 0){
                fb *= b%10;
            }
            b = b/10;
        }
    }
    if(fa == fb){
        return x > y;
    }
    if(fa > fb){
        if(f){
            return false;
        }
        return true;
    }
    if(f){
        return true;
    }
    return false;
}

int smol(int a[], int s, int ln, bool (*f)(int a, int b)){
    int l = s;
    for(int i = s; i < ln; i++){
        if(f(a[i], a[l]))
            l = i;
    }
    return l;
}

bool big(int a, int b){
    return a < b;
}

void sort(int n, bool (*func)(int a, int b)){
    int*a = new int[n];
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int l = smol(a, i, n, func);
        swap(a[i], a[l]);
    }
    for(int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}

////////////////////////////////////////////////////////////////

string* horsea(string*r, int**a, int x, int y, int c, int n){
    string alph = "abcdefghjk";
    if((x >= 0) and (y >= 0)){
        if(x+2 < n){
            if(y+1 < n){
                if(a[x+2][y+1] == 0){
                    r[c] = alph[x] + to_string(y);
                    c++;
                    a[x+2][y+1] = 1;
                    horsea(r, a, x + 2, y + 1, c, n);
                }
            }
            else if(y-1 < n){
                if(a[x+2][y-1] == 0) {
                    r[c] = alph[x] + to_string(y);
                    c++;
                    a[x + 2][y - 1] = 1;
                    horsea(r, a, x + 2, y - 1, c, n);
                }
            }
        }
        if(x-2 < n){
            if(y+1 < n){
                if(a[x-2][y+1] == 0){
                    r[c] = alph[x] + to_string(y);
                    c++;
                    a[x-2][y+1] = 1;
                    horsea(r, a, x - 2, y + 1, c, n);
                }
            }
            else if(y-1 < n){
                if(a[x-2][y-1] == 0) {
                    r[c] = alph[x] + to_string(y);
                    c++;
                    a[x - 2][y - 1] = 1;
                    horsea(r, a, x - 2, y - 1, c, n);
                }
            }
        }
        if(x+1 < n){
            if(y+2 < n){
                if(a[x+1][y+2] == 0){
                    r[c] = alph[x] + to_string(y);
                    c++;
                    a[x+1][y+2] = 1;
                    horsea(r, a, x + 1, y + 2, c, n);
                }
            }
            else if(y-2 < n){
                if(a[x+1][y-2] == 0) {
                    r[c] = alph[x] + to_string(y);
                    c++;
                    a[x + 1][y - 2] = 1;
                    horsea(r, a, x + 1, y - 2, c, n);
                }
            }
        }
        if(x-1 < n){
            if(y+2 < n){
                if(a[x-1][y+2] == 0){
                    r[c] = alph[x] + to_string(y);
                    c++;
                    a[x-1][y+2] = 1;
                    horsea(r, a, x - 1, y + 2, c, n);
                }
            }
            else if(y-2 < n){
                if(a[x-1][y-2] == 0) {
                    r[c] = alph[x] + to_string(y);
                    c++;
                    a[x - 1][y - 2] = 1;
                    horsea(r, a, x - 1, y - 2, c, n);
                }
            }
        }
    }
    if(c == n*n-1){
        r[c] = alph[x] + to_string(y);
        return r;
    }
    if(c == 0){
        cout << "IMPOSSIBLE";
        r = new string[n*n];
        return r;
    } else{
        r[c] = "";
        a[x][y] = 0;
    }
}