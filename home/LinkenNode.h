//
// Created by Jugglyuser on 27.02.2023.
//

#pragma once

#include <iostream>

using namespace std;

typedef struct Node {
    int num;
    Node* prev;
} Box;

typedef Box* ptr;

ptr init_box(int);

void add_box(ptr, ptr&);

void print(ptr);

void delete_box(int, ptr&);

void sort_box(ptr);

int box_length(ptr);

