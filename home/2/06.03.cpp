//
// Created by Jugglyuser on 27.02.2023

#include "iostream"
#include "stack"

using namespace std;

class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* insert(int x, node* t)
    {
        if(t == nullptr)
        {
            t = new node;
            t->data = x;
            t->left = t->right = nullptr;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    void inorder(node* t) {
        if(t == nullptr)
            return;
        inorder(t->right);
        inorder(t->left);
        cout << t->data << " ";
    }

    node* find(node* t, int x) {
        if(t == nullptr)
            return nullptr;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

void parlamem(){
    BST tree;
    int n, v;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> v;
        a[i] = v;
    }
    for (int i = n-1; i > -1; --i) {
        tree.insert(a[i]);
    }
    tree.display();
}

string operators[]{"NOT", "AND", "OR", "TRUE", "FALSE"};

string extract(int &i, const string &str){
    int n = str.length();

    for(string s : operators){
        int l = s.length();
        if(i + l <= n && str.substr(i, l) == s){
            i += l;
            return s;
        }
    }
    return {str[i++]};
}

bool is_register(const string &str){
    return str.length() == 1 && str[0] >= 'A' && str[0] <= 'Z';
}

int priority(const string &str){
    if(str == "NOT")
        return 4;
    else if(str == "AND")
        return 3;
    else if(str == "OR")
        return 2;
    else
        return 1;
}

string change(stack<string> &s){
    string r = s.top();
    s.pop();
    return r;
}

stack<string> notate(const string& formula){
    stack<string> stack, notation;

    int n = formula.length();
    int top, arg;
    for(int i = 0; i < n;){
        string curr = extract(i, formula);

        if(curr == " "){
            continue;
        }

        if(curr == "("){
            stack.push(curr);
        }

        else if(curr == "TRUE"){
            stack.push(curr);
        }

        else if(curr == "FALSE"){
            stack.push(curr);
        }

        else if(is_register(curr)){
            notation.push(curr);
        }

        else if(curr == ")"){
            while(stack.top() != "("){
                notation.push(change(stack));
            }
            stack.pop();
        }

        else{
            if(stack.empty()){
                stack.push(curr);
            }
            else{
                top = priority(stack.top());
                arg = priority(curr);
                while(top > arg){
                    notation.push(change(stack));
                    if(!stack.empty()){
                        top = priority(stack.top());
                    } else{
                        top = -1;
                    }
                }
                stack.push(curr);
            }
        }
    }

    while(!stack.empty()){
        notation.push(stack.top());
        stack.pop();
    }

    return notation;
}

void robot(){
    string formula;
    getline(cin, formula);
    stack<string> notation = notate(formula);
    int length = notation.size();
    string* a = new string[length];
    for (int i = 0; i < length; ++i) {
        a[i] = notation.top();
        notation.pop();
    }
    for (int i = length-1; i > -1; --i) {
        cout << a[i];
    }
}