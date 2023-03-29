//
// Created by Jugglyuser on 27.02.2023.
//
#pragma once
#include "LinkenNode.h"

ptr init_box(int i) {
    ptr root = new Box();
    root->prev = nullptr;
    root->num = i;
    return root;
}

void add_box(ptr el, ptr& root) {
el->prev = root;
root = el;
}

void print(ptr root) {
while (root != nullptr) {
cout << root->num << ' ';
root = root->prev;
}
cout << endl;
}

void delete_box(int k, ptr& root) {
    ptr curr, pr;
    curr = pr = root;
    if (curr->num == k)
        root = root->prev;
    else {
        curr = root->prev;
        while (curr != nullptr) {
            if (curr->num == k) {
                pr->prev = curr->prev;
                break;
            }
            else {
                pr = curr;
                curr = curr->prev;
            }
        }
    }
    if(curr != nullptr) delete curr;
}

int box_length(ptr root){
    int res = 0;
    while(root != nullptr){
        root = root->prev;
        res++;
    }
    return res;
}

void sort_box(ptr root){
    int i, j;
    int n = box_length(root);
    for (i = 0; i < n - 1; i++) {
        ptr iroot = root;
        for (j = 0; j < n - i - 1; j++) {
            if ((*iroot).num > (*((*iroot).prev)).num) {
                int tmp = (*((*iroot).prev)).num;
                (*((*iroot).prev)).num = (*iroot).num;
                (*iroot).num = tmp;
            }
            iroot = (*iroot).prev;
        }
    }
}
