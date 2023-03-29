//
// Created by Jugglyuser on 13.12.2022.
//

#include "iostream"
#include "iomanip"
#include "cmath"
#include "fstream"
#include "string"

using namespace std;

void qsortRecursive(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i);
    }
}

int binSearch(int* A, int n, int T) {
    int l, r, o(0);
    l = 0;
    r = n - 1;
    while(l <= r){
        int m = floor((l + r) / 2);
        if (A[m] < T) {
            l = m + 1;
        }
        else if (A[m] > T) {
            r = m - 1;
        }
        else {
            o++;
        }
    }
    return o;
}
int chess(){
    int t, s, r(0);
    cin >> t;
    int* tea = new int[t];
    for(int i = 0; i < t; i++){
        cin >> tea[i];
    }
    cin >> s;
    int* stud = new int[s];
    for(int i = 0; i < s; i++){
        cin >> stud[i];
    }
    qsortRecursive(stud, s);
    for(int i = 0; i < t; i++){
        r += binSearch(stud, s, tea[i]);
    }
    cout << r;
}