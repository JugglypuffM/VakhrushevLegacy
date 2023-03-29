//
// Created by Jugglyuser on 19.03.2023.
//

#include "iostream"
#include "map"
#include "list"
#include "vector"
#include "cmath"

using namespace std;

class VahVector{
public:
    VahVector() = default;
    VahVector(int first, int second){
        x = first;
        y = second;
    }
    int x, y;

    double length() const{
        return sqrt(x*x + y*y);
    }
};

class VahSection{
public:
    VahSection() = default;
    VahSection(int x1, int y1, int x2, int y2){
        VahVector first(x1, y1);
        VahVector second(x2, y2);
        a = first;
        b = second;
    }
    VahSection(VahVector first, VahVector second){
        a = first;
        b = second;
    }
    VahVector a;
    VahVector b;

    double length() const{
        return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    }

    bool contains(int x, int y){
        VahVector n(x, y);
        return ((sqrt((a.x-n.x)*(a.x-n.x) + (a.y-n.y)*(a.y-n.y)) + sqrt((n.x-b.x)*(n.x-b.x) + (n.y-b.y)*(n.y-b.y))) == this->length());
    }
};

//----------------------------------------------------------------------------------

struct matrix{
    int m, n;
    double** table;

    matrix() = default;
    matrix(int dim1, int dim2){
        this->m = dim1;
        this->n = dim2;
    }
    matrix(matrix &matrix): n(matrix.m), m(matrix.n){
        table = new double*[n];
        double *old, *copy;
        for(int i = 0; i < n; ++i){
            old = matrix.table[i];
            copy = new double[n];
            for(int j = 0; j < m; ++j)
                copy[j] = old[j];
            table[i] = copy;
        }
    }
    ~matrix(){
        for(int i = 0; i < n; ++i)
            delete[] table[i];
        delete[] table;
    }

    void define(){
        table = new double*[n];
        for (int i = 0; i < m; ++i) {
            table[i] = new double[n];
            for (int j = 0; j < n; ++j) {
                cin >> table[i][j];
            }
        }
    }

    void print() const{
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
    }

    double* operator[](int index) const{
        return table[index];
    }

    double zeroize(int bi, int bj) const{
        double mlt = 1;
        for(int i = bi + 1; i < n; ++i){
            if(table[i][bj] != 0){
                for(int j = bj + 1; j < m; ++j)
                    table[i][j] = table[bi][bj] * table[i][j] - table[i][bj] * table[bi][j];

                mlt *= table[bi][bj];
                table[i][bj] = 0;
            }
        }
        return mlt;
    }

    double stairize(int bi, int bj){
        for(int j = bj; j < m; ++j){
            if(table[bi][j] != 0){
                return zeroize(bi, j) * stairize(bi + 1, j + 1);
            }
            for(int i = bi + 1; i < n; ++i){
                if(table[i][j] != 0){
                    swap(table[bi], table[i]);
                    return zeroize(bi, j) * stairize(bi + 1, j + 1) * (-1);
                }
            }

        }
        return 1;
    }

    double stairize(){
        return stairize(0, 0);
    }

    double determinant(){
        if(n != m)
            return -1;

        matrix tmp = *this;
        double a = 1;
        double b = tmp.stairize(0, 0);
        for(int k = 0; k < n; ++k){
            double v = table[k][k];

            if(v == 0)
                return 0;

            a *= table[k][k];
        }

        return a / b;
    }
};

matrix operator +(matrix &a, matrix &b){
    if(a.m != b.m or a.n != b.n){
        return {0, 0};
    }
    matrix res(a.n, a.m);
    res.table = new double*[a.n];
    for(int i = 0; i < res.n; ++i){
        res.table[i] = new double[a.n];
        for(int j = 0; j < res.m; ++j){
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    return res;
}

matrix operator -(matrix &a, matrix &b){
    if(a.m != b.m or a.n != b.n){
        return {0, 0};
    }
    matrix res(a.n, a.m);
    res.table = new double*[a.n];
    for(int i = 0; i < res.n; ++i){
        res.table[i] = new double[a.n];
        for(int j = 0; j < res.m; ++j){
            res[i][j] = a[i][j] - b[i][j];
        }
    }
    return res;
}

bool operator ==(matrix &a, matrix &b){
    if(a.m != b.m or a.n != b.n){
        return false;
    }
    double *la, *lb;
    for(int i = 0; i < a.n; ++i){
        la = a[i];
        lb = b[i];
        for(int j = 0; j < a.m; ++j){
            if(la[j] != lb[j])
                return false;
        }
    }
    return true;
}

matrix operator *(matrix &a, matrix &b){
    if(a.n != b.m){
        return {0, 0};
    }
    matrix res(a.n, b.m);
    res.table = new double*[a.n];
    for(int i = 0; i < res.n; ++i){
        res.table[i] = new double[a.n];
        for(int j = 0; j < res.m; ++j){
            res[i][j] = 0;

            for(int k = 0; k < a.m; ++k)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
    return res;
}

//--------------------------------------------------------------

struct Vector{
    int x, y;
    Vector(){}
    Vector(int x, int y): x(x), y(y){}
    Vector(string &s){
        int point = s.find(' ');
        x = stoi(s.substr(0, point));
        y = stoi(s.substr(point + 1, s.length())); y = stoi(s.erase(point + 1));
    }
};

Vector operator +(Vector a, Vector b){
    return Vector(a.x + b.x, a.y + b.y);
}

istream& operator >>(istream &f, Vector& v){
    f >> v.x;
    f >> v.y;
    return f;
}

ostream& operator << (ostream &os, Vector &v){
    return os << v.x << " " << v.y;
}

bool table[12][12];
void convert_positions(int n){
    Vector begin;
    cin >> begin;
    cout << begin << endl;

    table[begin.x][begin.y] = true;

    Vector v;
    while(cin >> v){
        table[v.x][v.y] = true;
    }

    pair<char, Vector>p4[]{{'R', {1, 0}}, {'T', {0, 1}}, {'L', {-1, 0}}, {'B', {0, -1}}};
    list<Vector>check{begin};
    for(list<Vector>::iterator i = check.begin(); i != check.end(); ++i){
        Vector center = *i;
        table[center.x][center.y] = false;

        for(pair<char, Vector>p : p4){
            Vector shift = center + p.second;

            if(table[shift.x][shift.y]){
                check.push_back(shift);
                table[shift.x][shift.y] = false;
                cout << p.first;
            }

        }

        if(i == --check.end())
            break;

        cout << ',' << endl;
    }

    cout << '.' << endl;
}

void convert_directions(Vector begin){
    map<char, Vector>p4{{'R', {1, 0}}, {'T', {0, 1}}, {'L', {-1, 0}}, {'B', {0, -1}}};
    list<Vector>check{begin};

    for(list<Vector>::iterator i = check.begin(); i != check.end(); ++i){
        Vector center = *i;
        table[center.x][center.y] = true;

        for(char c = cin.get(); c != ',' && c != '.'; c = cin.get())
            check.push_back(center + p4[c]);
        cin.get();
    }

    cout << check.size() << endl;

    for(int i = 1; i <= 10; ++i)
        for(int j = 1; j <= 10; ++j)
            if(table[i][j])
                cout << i << " " << j << endl;
}

void coding() {
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            table[i][j] = false;

    string s = "";
    getline(cin, s);

    if (s.find(' ') != string::npos)
        convert_directions(Vector(s));
    else
        convert_positions(stoi(s));
}
