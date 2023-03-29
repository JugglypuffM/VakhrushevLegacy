//
// Created by Jugglyuser on 29.09.2022.
//Найти расстояние от точки c до отрезка ab

#include "iostream"
#include "cmath"

using namespace std;

double vectorLength(double x1, double x2, double y1, double y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

double calcDist(double ax, double ay, double bx, double by, double cx, double cy){
    double abx = bx - ax;
    double aby = by - ay;
    double acx = cx - ax;
    double acy = cy - ay;
    double bcx = cx - bx;
    double bcy = cy - by;
    double res;
    (acx*abx + acy*aby < 0) ? res = vectorLength(cx, cy, ax, ay) : 0;
    ((-abx)*bcx + (-aby)*bcy < 0) ? res = vectorLength(cx, cy, bx, by) : res = (abs((-aby)*acx + abx*acy)/sqrt(aby*aby + abx*abx));
    return res;
}