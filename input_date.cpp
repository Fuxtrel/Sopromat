#include "input_date.h"

InputDate::InputDate() {
    cin >> T;
    alf = (20 * 3.14) / 180;
    cin >> bt1 >> bt2;
    bt1 = (bt1 * 3.14) / 180;
    bt2 = (bt2 * 3.14) / 180;
    //cin >> w;
    cin >> dk1 >> dk2;
    /*cin >> fi1 >> fi2;
    fi1 = (fi1 * 3.14) / 180;
    fi2 = (fi2 * 3.14) / 180;
    cin >> l1 >> l2 >> l3 >> l4 >> l5;
    cin >> eta1 >> eta2 >> eta3;
    cin >> N1 >> N2 >> N3;*/
    Ft1 = T * 2 / dk1;
    Ft2 = T * 2 / dk2;
    Fr1 = Ft1 * (tan(alf)) / (cos(bt1));
    Fr2 = Ft2 * (tan(alf)) / (cos(bt2));
    Fx1 = Ft1 * tan(bt1);
    Fx2 = Ft2 * tan(bt2);
}

/*Forces::Forces() {
    dist2 = 0.5 * l2 + l3 + 0.5 * l4;
    dist3 = 0.5 * l4 + 0.5 * l5;
}*/

defXYZ::defXYZ() {
    sign = 0;
    //–асчЄт X1, Y1, Z1
    cout << "¬ведите знак перед слагаемым Fx1\n";
    cin >> sign;
    X1 = sign * Fx1;
    cout << "¬ведите знак перед слагаемым Ft1\n";
    cin >> sign;
    Y1 += sign * Ft1 * sin(fi1);
    cout << "¬ведите знак перед слагаемым Fr1\n";
    cin >> sign;
    Y1 += sign * Fr1 * cos(fi1);
    cout << "¬ведите знак перед слагаемым Ft1\n";
    cin >> sign;
    Z1 += sign * Ft1 * cos(fi1);
    cout << "¬ведите знак перед слагаемым Fr1\n";
    cin >> sign;
    Z1 += sign * Fr1 * sin(fi1);
    cout << "¬ведите знак перед слагаемым My1\n";
    cin >> sign;
    My1 = sign * Fx1 * sin(fi1);
    cout << "¬ведите знак перед слагаемым Mz1\n";
    cin >> sign;
    Mz1 = sign * Fx1 * cos(fi1);
    //–асчЄт X2, Y2, Z2
    cout << "¬ведите знак перед слагаемым Fx2\n";
    cin >> sign;
    X2 = sign * Fx2;
    cout << "¬ведите знак перед слагаемым Ft2\n";
    cin >> sign;
    Y2 += sign * Ft2 * sin(fi2);
    cout << "¬ведите знак перед слагаемым Fr2\n";
    cin >> sign;
    Y2 += sign * Fr2 * cos(fi2);
    cout << "¬ведите знак перед слагаемым Ft2\n";
    cin >> sign;
    Z2 += sign * Ft2 * cos(fi2);
    cout << "¬ведите знак перед слагаемым Fr2\n";
    cin >> sign;
    Z2 += sign * Fr2 * sin(fi2);
    cout << "¬ведите знак перед слагаемым My2\n";
    cin >> sign;
    My2 = sign * Fx2 * sin(fi2);
    cout << "¬ведите знак перед слагаемым Mz2\n";
    cin >> sign;
    Mz2 = sign * Fx2 * cos(fi2);
}

WalPosition::WalPosition() {
    forces[1] = 0.5 * l1 + 0.5 * l2;
    forces[3] = 0.5 * l2 + l3 + 0.5 * l4;
    forces[5] = 0.5 * l4 + 0.5 * l5;
    for (int i = 0; i < 7; i += 2) {
        cout << "¬ведите силы с лева направо, вместо реакций введите их пор€дковые номера";
        cin >> forces[i];
    }
    int place = 0;
    while (place < 7 && forces[place] != 1) {
        place += 2;
    }
    switch (place) {
        case 0:
            forces[3] += forces[1];
            forces[5] += forces[3];
            if (forces[4] == 2) {
                Rby = (-forces[1] * Y1 - forces[5] * Y2) / forces[3] - My1 - My2;
                Rbz = (-forces[1] * Z1 - forces[5] * Z2) / forces[3] - Mz1 - Mz2;
            } else {
                Rby = (-forces[1] * Y1 - forces[3] * Y2) / forces[5] - My1 - My2;
                Rbz = (-forces[1] * Z1 - forces[3] * Z2) / forces[5] - Mz1 - Mz2;
            }
            if (forces[4] == 2) {
                forces[3] = 0.5 * l2 + l3 + 0.5 * l4;
                forces[1] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                forces[5] = 0.5 * l4 + 0.5 * l5;
                Ray = (forces[3] * Y1 - forces[5] * Y2) / forces[1] - My1 - My2;
                Raz = (forces[3] * Z1 - forces[5] * Z2) / forces[1] - Mz1 - Mz2;
            } else {
                forces[1] = 0.5 * l4 + 0.5 * l5;
                forces[3] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                forces[5] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                Ray = (-forces[3] * Y1 - forces[1] * Y2) / forces[5] - My1 - My2;
                Raz = (-forces[3] * Z1 - forces[1] * Z2) / forces[5] - Mz1 - Mz2;
            }
            break;
        case 2:
            forces[5] = 0.5 * l2 + l3 + 0.5 * l4 + 0.5 * l4 + 0.5 * l5;
            if (forces[4] == 2) {
                Rby = (-forces[1] * Y1 + forces[5] * Y2) / forces[3] - My1 - My2;
                Rbz = (-forces[1] * Z1 + forces[5] * Z2) / forces[3] - Mz1 - Mz2;
            } else {
                Rby = (-forces[1] * Y1 - forces[5] * Y2) / forces[3] - My1 - My2;
                Rbz = (-forces[1] * Z1 - forces[5] * Z2) / forces[3] - Mz1 - Mz2;
            }
            if (forces[4] == 2) {
                forces[1] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                forces[3] = 0.5 * l2 + l3 + 0.5 * l4;
                forces[5] = 0.5 * l4 + 0.5 * l5;
                Ray = (forces[1] * Y1 - forces[5] * Y2) / forces[3] - My1 - My2;
                Raz = (forces[1] * Z1 - forces[5] * Z2) / forces[3] - Mz1 - Mz2;
            } else {
                forces[1] = 0.5 * l4 + 0.5 * l5;
                forces[3] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                forces[5] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                Ray = (-forces[5] * Y1 - forces[1] * Y2) / forces[3] - My1 - My2;
                Raz = (-forces[5] * Z1 - forces[1] * Z2) / forces[3] - Mz1 - Mz2;
            }
            break;
    }

}

void InputDate::equipmentCout() {
    cout << "Ft1 = T * 2 / dk1 = " << T << " * 2 " << " / " << dk1 << " = " << Ft1 << '\n';
    cout << "Ft2 = T * 2 / dk2 = " << T << " * 2 " << " / " << dk2 << " = " << Ft2 << '\n';
    cout << "Fr1 = Ft1 * (tan(alf)) / (cos(bt1)) = " << Ft1 << " * " << tan(alf) << " / " << cos(bt1) << " = " << Fr1
         << '\n';
    cout << "Fr2 = Ft2 * (tan(alf)) / (cos(bt2)) = " << Ft2 << " * " << tan(alf) << " / " << cos(bt2) << " = " << Fr2
         << '\n';
    cout << "Fx1 = Ft1 * tan(bt1) = " << Ft1 << " * " << tan(bt1) << " = " << Fx1 << '\n';
    cout << "Fx2 = Ft2 * tan(bt2) = " << Ft2 << " * " << tan(bt2) << " = " << Fx2 << '\n';
}