#ifndef SOPROMAT_INPUT_DATE_H
#define SOPROMAT_INPUT_DATE_H

#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

class InputDate {
public:
    //������� ��������� ������
    double T;
    //������� ��������� �������� ����������
    double alf, bt1, bt2;
    //������� �������� �������� ����
    int w;
    //�������� �������� ����
    double dk1, dk2;
    //������� ���������� ����� ����������� �������� ����
    double fi1, fi2;
    //����� �������� ����
    double l1, l2, l3, l4, l5;
    //����������� ����������
    int eta1, eta2, eta3;
    //������������ ������� N
    int N1, N2, N3;
    double Ft1, Ft2, Fx1, Fx2, Fr1, Fr2;
    string material, sootnoshenie[4], otnoshenie[4];

    explicit InputDate(ofstream &fout);

};


class defXYZ : public InputDate {
public:
    int sign;
    double X1, Y1, Z1, X2, Y2, Z2, My1, My2, Mz1, Mz2;

    explicit defXYZ(ofstream &fout);

};

class WalPosition : public defXYZ{
public:
    int forces[2];
    double dist[3];
    string d1, d2, d3;
    double Ha, Ray, Raz, Rby, Rbz;
    explicit WalPosition(ofstream &fout);
    void equipmentCout(ofstream &fout);
};

#endif //SOPROMAT_INPUT_DATE_H
