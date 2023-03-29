//
// Created by Jugglyuser on 06.03.2023.
//

#include "iostream"
#include "vector"
#include "list"
#include "cmath"

using namespace std;

struct Sack{
    int values[100];
    int length = 0;
    int max = 0;

    void push(int c){
        max = (length == 0) ? c : ((c > max) ? c : max);
        values[length++] = c;
    }

    void pop(){
        --length;
    }

    int top(){
        return values[length - 1];
    }
};

class Clone{
public:
    Clone() = default;
    Clone(list<int> i, list<int> r){
        this->instructions = std::move(i);
        this->rolled = std::move(r);
    }
    void learn(int n){
        instructions.push_front(n);
    }

    void rollback(){
        rolled.push_front(instructions.front());
        instructions.pop_front();
    }

    void relearn(){
        instructions.push_front(rolled.front());
        rolled.pop_front();
    }

    void check(){
        if(instructions.empty()){
            cout << "basic" << endl;
        } else{
            cout << instructions.front() << endl;
        }
    }

    Clone do_clone(){
        Clone new_one = *new Clone(this->instructions, this->rolled);
        return new_one;
    }

private:
    list<int> instructions;
    list<int> rolled;
};

void clowns(){
    vector<Clone> army;
    army.push_back(*new Clone);

    int n, m, a, b;
    string command;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "learn"){
            cin >> a >> b;
            army[a-1].learn(b);
        } else if (command == "rollback"){
            cin >> a;
            army[a-1].rollback();
        } else if(command == "relearn"){
            cin >> a;
            army[a-1].relearn();
        } else if(command == "Clone"){
            cin >> a;
            army.push_back(army[a-1].do_clone());
        } else if(command == "check"){
            cin >> a;
            army[a-1].check();
        }
    }
}

class Section{
    Section() = default;
    Section(int x1, int y1, int x2, int y2){
        this->a1 = x1;
        this->a2 = y1;
        this->b1 = x2;
        this->b2 = y2;
    }

    double length() const{
        double a = (b1-a1);
        double b = (b2-a2);
        return sqrt(a*a+b*b);
    }

    bool contains(int x, int y) const{
        double t1 = (a1-x)/(x-b1);
        double t2 = (a2-y)/(y-b2);
        if(((x == b1) and (y == b2)) or ((t1 == t2) and (t1 > 0)) or ((x == a1) and (y == a2))){
            return true;
        } else{
            return false;
        }
    }
    double a1, a2, b1, b2;
};

class Vector{
    Vector() = default;
    Vector(int x, int y){
        this->a1 = x;
        this->a2 = y;
    }
    int a1, a2;
};

