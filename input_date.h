#ifndef SOPROMAT_INPUT_DATE_H
#define SOPROMAT_INPUT_DATE_H
//
class InputDate {
public:
    //Внешний вращающий момнет
    int T;
    //Угловые параметры зубчатых зацеплений
    double alf, bt1, bt2;
    //Угловая скорость вращения вала
    int w;
    //Диаметры зубчатых колёс
    int dk1, dk2;
    //Угловые координаты точек зацеплоения зубчатых колёс
    double fi1, fi2;
    //Длины участков вала
    int l1, l2, l3, l4, l5;
    //Коэффициент перегрузки
    int eta1, eta2, eta3;
    //Длительность ступени N
    int N1, N2, N3;

    InputDate(int t, int ALF, int BT1, int BT2, int W, int DK1, int DK2, int FI1, int FI2,
              int L1, int L2, int L3, int L4, int L5, int ETA1, int ETA2, int ETA3, int n1, int n2, int n3) {
        T = t;
        alf = (20 * 3.14) / 180;
        bt1 = (BT1 * 3.14) / 180;
        bt2 = (BT2 * 3.14) / 180;
        w = W;
        dk1 = DK1;
        dk2 = DK2;
        fi1 = (FI1 * 3.14) / 180;
        fi2 = (FI2 * 3.14) / 180;
        l1 = L1;
        l2 = L2;
        l3 = L3;
        l4 = L4;
        l5 = L5;
        eta1 = ETA1;
        eta2 = ETA2;
        eta3 = ETA3;
        N1 = n1;
        N2 = n2;
        N3 = n3;
    }

};

class Forces : public InputDate {
public:
    //Тангенциальная, осевая и радиальная силы
    double Ft, Fx, Fr;
    //Результирующие силы в зубчатых колёсах
    double X, Y, Z;
    //Реакции опор
    double Rx, Ry, Rz;
    //Моменты в зубчатых колёсах
    double My, Mz;
    double dist1, dist2, dist3;

};



#endif //SOPROMAT_INPUT_DATE_H
