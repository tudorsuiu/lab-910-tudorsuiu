//
// Created by Tudor on 5/16/2022.
//

#include <cmath>

#ifndef LAB_910_TUDORSUIU_DOUBLECOMPARE_H
#define LAB_910_TUDORSUIU_DOUBLECOMPARE_H


class doubleCompare {
public:
    static bool equal(double a, double b) {
        return fabs(a - b) < 1e-6;
    }

    static bool notEqual(double a, double b) {
        return !equal(a, b);
    }

    static bool less(double a, double b) {
        return a < b && notEqual(a, b);
    }

    static bool lessOrEqual(double a, double b) {
        return a < b || equal(a, b);
    }

    static bool greater(double a, double b) {
        return a > b && notEqual(a, b);
    }

    static bool greaterOrEqual(double a, double b) {
        return a > b || equal(a, b);
    }
};

#endif //LAB_910_TUDORSUIU_DOUBLECOMPARE_H
