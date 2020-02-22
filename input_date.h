#ifndef SOPROMAT_INPUT_DATE_H
#define SOPROMAT_INPUT_DATE_H

#include <cmath>
#include <iostream>

using namespace std;

class InputDate {
public:
    //Внешний вращающий момнет
    double T;
    //Угловые параметры зубчатых зацеплений
    double alf, bt1, bt2;
    //Угловая скорость вращения вала
    //int w;
    //Диаметры зубчатых колёс
   double dk1, dk2;
    //Угловые координаты точек зацеплоения зубчатых колёс
    double fi1, fi2;
    //Длины участков вала
    double l1, l2, l3, l4, l5;
    //Коэффициент перегрузки
    int eta1, eta2, eta3;
    //Длительность ступени N
    int N1, N2, N3;
    double Ft1, Ft2, Fx1, Fx2, Fr1, Fr2;

    InputDate();

};


class defXYZ : public InputDate {
public:
    int sign;
    double X1, Y1, Z1, X2, Y2, Z2, My1, My2, Mz1, Mz2;

    defXYZ();

};

class WalPosition : public defXYZ{
public:
    int forces[2];
    double dist[3];
    string d1, d2, d3;
    double Ha, Ray, Raz, Rby, Rbz;

    WalPosition();
    void equipmentCout();
};

#endif //SOPROMAT_INPUT_DATE_H
