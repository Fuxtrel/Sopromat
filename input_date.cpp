#include "input_date.h"

InputDate::InputDate() {
    cin >> T;
    alf = (20 * 3.14) / 180;
    cin >> bt1 >> bt2;
    bt1 = (bt1 * 3.14) / 180;
    bt2 = (bt2 * 3.14) / 180;
    //cin >> w;
    cin >> dk1 >> dk2;
    cin >> fi1 >> fi2;
    fi1 = (fi1 * 3.14) / 180;
    fi2 = (fi2 * 3.14) / 180;
    cin >> l1 >> l2 >> l3 >> l4 >> l5;
    /*cin >> eta1 >> eta2 >> eta3;
    cin >> N1 >> N2 >> N3;*/
    Ft1 = T * 2 / dk1;
    Ft2 = T * 2 / dk2;
    Fr1 = Ft1 * (tan(alf)) / (cos(bt1));
    Fr2 = Ft2 * (tan(alf)) / (cos(bt2));
    Fx1 = Ft1 * tan(bt1);
    Fx2 = Ft2 * tan(bt2);
}


defXYZ::defXYZ() {
    sign = 0;
    //–асчЄт X1, Y1, Z1
    cout << "¬ведите знак перед слагаемым Fx1\n";
    cin >> sign;
    X1 = sign * Fx1;
    //cout << "¬ведите знак перед слагаемым Ft1\n";
    cin >> sign;
    Y1 += sign * Ft1 * sin(fi1);
    //cout << "¬ведите знак перед слагаемым Fr1\n";
    cin >> sign;
    Y1 += sign * Fr1 * cos(fi1);
    //cout << "¬ведите знак перед слагаемым Ft1\n";
    cin >> sign;
    Z1 += sign * Ft1 * cos(fi1);
    //cout << "¬ведите знак перед слагаемым Fr1\n";
    cin >> sign;
    Z1 += sign * Fr1 * sin(fi1);
    //cout << "¬ведите знак перед слагаемым My1\n";
    cin >> sign;
    My1 = sign * Fx1 * (dk1 / 2) * sin(fi1);
    //cout << "¬ведите знак перед слагаемым Mz1\n";
    cin >> sign;
    Mz1 = sign * Fx1 * (dk1 / 2) * cos(fi1);
    //–асчЄт X2, Y2, Z2
    //cout << "¬ведите знак перед слагаемым Fx2\n";
    cin >> sign;
    X2 = sign * Fx2;
    //cout << "¬ведите знак перед слагаемым Ft2\n";
    cin >> sign;
    Y2 += sign * Ft2 * sin(fi2);
    //cout << "¬ведите знак перед слагаемым Fr2\n";
    cin >> sign;
    Y2 += sign * Fr2 * cos(fi2);
    //cout << "¬ведите знак перед слагаемым Ft2\n";
    cin >> sign;
    Z2 += sign * Ft2 * cos(fi2);
    //cout << "¬ведите знак перед слагаемым Fr2\n";
    cin >> sign;
    Z2 += sign * Fr2 * sin(fi2);
    //cout << "¬ведите знак перед слагаемым My2\n";
    cin >> sign;
    My2 = sign * Fx2 * (dk2 / 2) * sin(fi2);
    //cout << "¬ведите знак перед слагаемым Mz2\n";
    cin >> sign;
    Mz2 = sign * Fx2 * (dk2 / 2) * cos(fi2);
}

WalPosition::WalPosition() {
    dist[0] = 0.5 * l1 + 0.5 * l2;
    dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
    dist[2] = 0.5 * l4 + 0.5 * l5;
    cout << "¬ведите силы с лева направо, вместо реакций введите их пор€дковые номера";

    for (int &i : forces) {
        i = 0;
        cin >> i;
    }
    Ha = -X1 - X2;
    switch (forces[0]) {
        case 1:
            dist[1] += dist[0];
            dist[2] += dist[1];
            if (forces[1] == 3) {
                // Y1*d1  + Rny*d2 + Y2*d3 + Mz1 + Mz2 = 0
                Rby = (-dist[0] * Y1 - dist[2] * Y2 - Mz1 - Mz2) / dist[1];
                // -Y1*d1  + -Rny*d2 + -Y2*d3 + Mz1 + Mz2 = 0
                Rbz = (-dist[0] * Z1 - dist[2] * Z2 + My1 + My2) / dist[1];
            } else {
                // Y1*d1 + Y2*d2 + Rby*d3 + Mz1 + Mz2 = 0
                Rby = (-dist[0] * Y1 - dist[1] * Y2 - Mz1 - Mz2) / dist[2];
                // -Z1*d1 - Z2*d2 - Rbz*d3 + My1 + My2 = 0
                Rbz = (-dist[0] * Z1 - dist[1] * Z2 + My1 + My2) / dist[2];
            }
            if (forces[1] == 3) {
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[0] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                // -Ray*d1 - Y1*d2 + Y2*d3 + Mz1 + Mz2 = 0
                Ray = (dist[1] * Y1 - dist[2] * Y2 - Mz1 - Mz2) / dist[0];
                // Raz*d1 + Z1*d2 - Z2*d3 + My1 + My2 = 0
                Raz = (-dist[1] * Z1 + dist[2] * Z2 - My1 - My2) / dist[0];
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                // -Y2*d1 - Y1*2 - Ray*d3 + Mz1 + Mz2 = 0
                Ray = (-dist[1] * Y1 - dist[0] * Y2 + Mz1 + Mz2) / dist[2];
                // Z2*d1 + Z1*2 + Raz*d3 + My1 + My2 = 0
                Raz = (-dist[1] * Z1 - dist[0] * Z2 - My1 - My2) / dist[2];
            }
            break;
        case 2:
            dist[2] = 0.5 * l2 + l3 + 0.5 * l4 + 0.5 * l4 + 0.5 * l5;
            if (forces[1] == 3) {
                // -Y1*d1 + Rby*d2 + Y2*d3 + Mz1 + Mz2 = 0
                Rby = (dist[0] * Y1 - dist[2] * Y2 - Mz1 - Mz2) / dist[1];
                // Z1*d1 - Rbz*d2 - Z2*d3 + My1 + My2 = 0
                Rbz = (dist[0] * Z1 + dist[2] * Z2 + My1 + My2) / dist[1];
            } else {
                // -Y1*d1 + Rby*d3 + Y2*d2 + Mz1 + Mz2 = 0
                Rby = (dist[0] * Y1 - dist[2] * Y2 - Mz1 - Mz2) / dist[1];
                // Z1*d1 - Rbz*d3 - Z2*d2 + My1 + My2 = 0
                Rbz = (dist[0] * Z1 - dist[2] * Z2 + My1 + My2) / dist[1];
            }
            if (forces[1] == 3) {
                dist[0] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                // -Y1*d1 - Ray*d2 + Y2*d3 + Mz1 + Mz2 = 0
                Ray = (-dist[0] * Y1 + dist[2] * Y2 + Mz1 + Mz2) / dist[1];
                // Z1*d1 + Raz*d2 - Z2*d3 + My1 + My2 = 0
                Raz = (-dist[0] * Z1 + dist[2] * Z2 - My1 - My2) / dist[1];
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                // -Y1*d3 - Ray*d2 - Y2*d1 + Mz1 + Mz2 = 0
                Ray = (-dist[2] * Y1 - dist[0] * Y2 + Mz1 + Mz2) / dist[1];
                // Z1*d3 + Raz*d2 + Z2*d1 + My1 + My2 = 0
                Raz = (-dist[2] * Z1 - dist[0] * Z2 - My1 - My2) / dist[1];
            }
            break;
        default:
            break;
    }
}

void WalPosition::equipmentCout() {
    cout << "Ft1 = T * 2 / dk1 = " << T << " * 2 " << " / " << dk1 << " = " << Ft1 << '\n';
    cout << "Ft2 = T * 2 / dk2 = " << T << " * 2 " << " / " << dk2 << " = " << Ft2 << '\n';
    cout << "Fr1 = Ft1 * (tan(alf)) / (cos(bt1)) = " << Ft1 << " * " << tan(alf) << " / " << cos(bt1) << " = " << Fr1
         << '\n';
    cout << "Fr2 = Ft2 * (tan(alf)) / (cos(bt2)) = " << Ft2 << " * " << tan(alf) << " / " << cos(bt2) << " = " << Fr2
         << '\n';
    cout << "Fx1 = Ft1 * tan(bt1) = " << Ft1 << " * " << tan(bt1) << " = " << Fx1 << '\n';
    cout << "Fx2 = Ft2 * tan(bt2) = " << Ft2 << " * " << tan(bt2) << " = " << Fx2 << '\n';
    dist[0] = 0.5 * l1 + 0.5 * l2;
    dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
    dist[2] = 0.5 * l4 + 0.5 * l5;
    d1 = "0.5 * l1 + 0.5 * l2";
    d2 = "0.5 * l2 + l3 + 0.5 * l4";
    d3 = "0.5 * l4 + 0.5 * l5";
    cout << "Ha + X1 + X2 = 0\n";
    cout << Ha;
    switch (forces[0]) {
        case 1:
            dist[1] = 0.5 * l1 + l2 + l3 + 0.5 * l4;
            dist[2] = 0.5 * l1 + l2 + l3 + l4 + 0.5 * l5;
            d2 = "0.5 * l1 + l2 + l3 + 0.5 * l4";
            d3 = "0.5 * l1 + l2 + l3 + l4 + 0.5 * l5";
            if (forces[1] == 3) {
                // Y1*d1  + Rny*d2 + Y2*d3 + Mz1 + Mz2 = 0
                cout << "Y1 * " << d1 << " + Rny * " << d2 << " + Y2 * " << d3 << " + Mz1 + Mz2 = 0\n";
                cout << "Rby = " << Rby << endl;
                // -Z1*d1 - Rbz*d2 - Z2*d3 + My1 + My2 = 0
                cout << "-Z1 * " << d1 << " - Rbz * " << d2 << " - Z2 * " << d3 << " + My1 + My2 = 0\n";
                cout << "Rbz = " << Rbz << endl;
            } else {
                // Y1*d1 + Y2*d2 + Rby*d3 + Mz1 + Mz2 = 0
                cout << "Y1 * " << d1 << " + Y2 * " << d2 << "+ Rby * " << d3 << " + Mz1 + Mz2 = 0\n";
                cout << "Rby = " << Rby << endl;
                // -Z1*d1 - Z2*d2 - Rbz*d3 + My1 + My2 = 0
                cout << "-Z1 * " << d1 << " - Z2 * " << d2 << " - Rbz * " << d3 << " + My1 + My2 = 0\n";
                cout << "Rbz = " << Rbz << endl;
            }
            if (forces[1] == 3) {
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[0] = 0.5 * l1 + l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                d1 = "0.5 * l1 + l2 + l3 + 0.5 * l4";
                d2 = "0.5 * l2 + l3 + 0.5 * l4";
                d3 = "0.5 * l4 + 0.5 * l5";
                // -Ray*d1 - Y1*d2 + Y2*d3 + Mz1 + Mz2 = 0
                cout << "-Ray * " << d1 << " - Y1 * " << d2 << " + Y2 * " << d3 << " + Mz1 + Mz2 = 0\n";
                cout <<"Ray = " << Ray << endl;
                // Raz*d1 + Z1*d2 - Z2*d3 + My1 + My2 = 0
                cout << "Raz * " << d1 << " + Z1 * " << d2 << " - Z2 * " << d3 << " + My1 + My2 = 0\n";
                cout << "Raz = " << Raz << endl;
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l2 + l3 + l4 + 0.5 * l5;
                dist[2] = 0.5 * l1 + l2 + l3 + l4 + 0.5 * l5;
                d1 = "0.5 * l4 + 0.5 * l5";
                d2 = "0.5 * l2 + l3 + l4 + 0.5 * l5";
                d3 = "0.5 * l1 + l2 + l3 + l4 + 0.5 * l5";
                // -Y2*d1 - Y1*2 - Ray*d3 + Mz1 + Mz2 = 0
                cout << "-Y2 * " << d1 << " - Y1 * " << d2 << " - Ray * " << d3 << " + Mz1 + Mz2 = 0\n";
                cout << "Ray = " << Ray << endl;
                // Z2*d1 + Z1*2 + Raz*d3 + My1 + My2 = 0
                cout << "Z2 * " << d1 << " + Z1 * " << d2 << " + Raz * " << d3 << " + My1 + My2 = 0\n";
                cout << "Raz = " << Raz << endl;
            }
            break;
        case 2:
            dist[2] = 0.5 * l2 + l3 + 0.5 * l4 + 0.5 * l4 + 0.5 * l5;
            d3 = "0.5 * l2 + l3 + l4 + 0.5 * l5";
            if (forces[1] == 3) {
                // -Y1*d1 + Rby*d2 + Y2*d3 + Mz1 + Mz2 = 0
                cout << "-Y1 * " << d1 << " + Rby * " << d2 << " + Y2 * " << d3 << " + Mz1 + Mz2 = 0\n";
                cout << "Rby = " << Rby << endl;
                // Z1*d1 - Rbz*d2 - Z2*d3 + My1 + My2 = 0
                cout << "Z1 * " << d1 << " - Rbz * " << d2 << " - Z2 * " << d3 << " + My1 + My2 = 0\n";
                cout << "Rbz = " << Rbz << endl;
            } else {
                // -Y1*d1 + Rby*d3 + Y2*d2 + Mz1 + Mz2 = 0
                cout << "-Y1 * " << d1 << " + Rby * " << d3 << " + Y2 * " << d2 << " + Mz1 + Mz2 = 0\n";
                cout << "Rby = " << Rby << endl;
                // Z1*d1 - Rbz*d3 - Z2*d2 + My1 + My2 = 0
                cout << "Z1 * " << d1 << " - Rbz * " << d3 << " - Z2 * " << d2 << " + My1 + My2 = 0\n";
                cout << "Rbz = " << Rbz << endl;
            }
            if (forces[1] == 3) {
                dist[0] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                d1 = "0.5 * l1 + l2 + l3 + 0.5 * l4";
                d2 = "0.5 * l2 + l3 + 0.5 * l4";
                d3 = "0.5 * l4 + 0.5 * l5";
                // -Y1*d1 - Ray*d2 + Y2*d3 + Mz1 + Mz2 = 0
                cout << "-Y1 * " << d1 << " - Ray * " << d2 << " + Y2 * " << d3 << " + Mz1 + Mz2 = 0\n";
                cout << "Ray = " << Ray << endl;
                // Z1*d1 + Raz*d2 - Z2*d3 + My1 + My2 = 0
                cout << "Z1 * " << d1 << " + Raz * " << d2 << " - Z2 * " << d3 << " + My1 + My2 = 0\n";
                cout << "Raz = " << Raz << endl;
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                d1 = "0.5 * l4 + 0.5 * l5";
                d2 = "0.5 * l2 + l3 + l4 + 0.5 * l5";
                d3 = "0.5 * l1 + l2 + l3 + l4 + 0.5 * l5 ";
                // -Y1*d3 - Ray*d2 - Y2*d1 + Mz1 + Mz2 = 0
                cout << "-Y1 * " << d3 << "- Ray * " << d2 << " - Y2 * " << d1 << " + Mz1 + Mz2 = 0\n";
                cout << "Ray" << Ray << endl;
                // Z1*d3 + Raz*d2 + Z2*d1 + My1 + My2 = 0
                cout << "Z1 * " << d3 << " + Raz * " << d2 << " + Z2 * " << d1 << " + My1 + My2 = 0\n";
                cout << "Raz" << Raz << endl;
            }
            break;
    }

}