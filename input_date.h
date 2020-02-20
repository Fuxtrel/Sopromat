#ifndef SOPROMAT_INPUT_DATE_H
#define SOPROMAT_INPUT_DATE_H

#include <cmath>
#include <iostream>

using namespace std;

class InputDate {
public:
    //������� ��������� ������
    double T;
    //������� ��������� �������� ����������
    double alf, bt1, bt2;
    //������� �������� �������� ����
    //int w;
    //�������� �������� ����
   double dk1, dk2;
    //������� ���������� ����� ����������� �������� ����
    double fi1, fi2;
    //����� �������� ����
    int l1, l2, l3, l4, l5;
    //����������� ����������
    int eta1, eta2, eta3;
    //������������ ������� N
    int N1, N2, N3;
    double Ft1, Ft2, Fx1, Fx2, Fr1, Fr2;

    InputDate();

    void equipmentCout();
};


class defXYZ : public InputDate {
public:
    int sign;
    double X1, Y1, Z1, X2, Y2, Z2, My1, My2, Mz1, Mz2;

    defXYZ();

};

class WalPosition : public defXYZ{
public:
    double forces[7];
    double Ha, Ray, Raz, Rby, Rbz;

    WalPosition();
};

#endif //SOPROMAT_INPUT_DATE_H
