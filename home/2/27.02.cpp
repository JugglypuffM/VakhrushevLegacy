//
// Created by Jugglyuser on 26.02.2023.
//

#include "iostream"
#include "LinkenMethods.h"

using namespace std;

struct int_node{
    int prev, next;
};

int mono(){
    int n;
    cin >> n;

    int_node **nodes = new int_node*[n + 2];
    for(int i = 0; i < n + 2; ++i)
        nodes[i] = new int_node{i - 1, i + 1};

    int l = 0;

    for(int i = 0; i < n; ++i){
        int value;
        cin >> value;

        int_node* node = nodes[value];
        nodes[value] = nullptr;

        if(value < l || value > n || node == nullptr){
            cout << "Cheater" << endl;
            return 0;
        }

        l = node->prev;
        nodes[node->next]->prev = node->prev;
        nodes[node->prev]->next = node->next;
    }

    cout << "Not a proof" << endl;
    return 0;
}

void linken_test(){
    int n = 10, k = 3;
    ptr top = nullptr;
    for (int i = 0; i < n; i++)
        add_box(init_box(i), top);
    print(top);
    cout << box_length(top) << endl;
    delete_box(k, top);
    print(top);
    cout << box_length(top) << endl;
    sort_box(top);
    print(top);
}