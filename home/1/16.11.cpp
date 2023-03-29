//
// Created by Jugglyuser on 15.11.2022.
//

#include "iostream"
#include "cmath"
#include "iomanip"

using namespace std;

void doge(){
    int n;
    cin >> n;
    double x0, y0, s(0);
    double xp, yp, xl, yl;
    cin >> xp >> yp;
    x0 = xp;
    y0 = yp;
    for(int i = 0; i < n-1; i++){
        cin >> xl >> yl;
        s += ((yl+yp)*(xl-xp))/2;
        xp = xl;
        yp = yl;
    }
    s += ((yl+y0)*(xl+x0))/2;
    if(s > 0){
        cout << "cw";
    }else{
        cout << "ccw";
    }
}

///////////////////////////////////////////////////////

void de_can(){
    double h, w ,x ,y ,r;
    cin >> h >> w >> x >> y >> r;
    x = fabs(x);
    y = fabs(y);
    if ( y > x ) x = y;
    cout << fixed << setprecision(5) << h * w * w / 3.0 - h * 3.14159265358979 * r * r * ( w/2 - x ) / (w/2);
}

/////////////////////////////////////////////////////////

void alpha(){
    string s, a("abcdefghigklmnopqrstuvwxyz");
    cin >> s;
    int j(0), b(0), e(0), l(0), m(0), n(0);
    for(int i = 0; i < s.length(); i++){
        if(s[i] == a[j]){
            j++;
        }else{
            e = i;
            if(l < e - b){
                m = b;
                n = e;
                l = e - b;
            }
            if(s[i] == 'a'){
                j = 1;
                b = i;
            } else{
                j = 0;
                b = i+1;
            }
        }
    }
    cout << s.substr(m, n-m) << endl;
    cout << m << " " << n;
}