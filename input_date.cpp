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
    My1 = sign * Fx1 * sin(fi1);
    //cout << "¬ведите знак перед слагаемым Mz1\n";
    cin >> sign;
    Mz1 = sign * Fx1 * cos(fi1);
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
    My2 = sign * Fx2 * sin(fi2);
    //cout << "¬ведите знак перед слагаемым Mz2\n";
    cin >> sign;
    Mz2 = sign * Fx2 * cos(fi2);
}

WalPosition::WalPosition() {
    dist[0] = 0.5 * l1 + 0.5 * l2;
    dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
    dist[2] = 0.5 * l4 + 0.5 * l5;
    cout << "¬ведите силы с лева направо, вместо реакций введите их пор€дковые номера";
    for (int i : forces) {
        cin >> i;
    }
    switch (forces[0]) {
        case 1:
            dist[1] += dist[0];
            dist[2] += dist[1];
            if (forces[1] == 3) {
                Rby = (-dist[0] * Y1 - dist[2] * Y2) / dist[1] - My1 - My2;
                Rbz = (-dist[0] * Z1 - dist[2] * Z2) / dist[1] - Mz1 - Mz2;
            } else {
                Rby = (-dist[0] * Y1 - dist[1] * Y2) / dist[2] - My1 - My2;
                Rbz = (-dist[0] * Z1 - dist[1] * Z2) / dist[2] - Mz1 - Mz2;
            }
            if (forces[1] == 3) {
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[0] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                Ray = (dist[1] * Y1 - dist[2] * Y2) / dist[0] - My1 - My2;
                Raz = (dist[1] * Z1 - dist[2] * Z2) / dist[0] - Mz1 - Mz2;
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                Ray = (-dist[1] * Y1 - dist[0] * Y2) / dist[2] - My1 - My2;
                Raz = (-dist[1] * Z1 - dist[0] * Z2) / dist[2] - Mz1 - Mz2;
            }
            break;
        case 2:
            dist[2] = 0.5 * l2 + l3 + 0.5 * l4 + 0.5 * l4 + 0.5 * l5;
            if (forces[1] == 3) {
                Rby = (-dist[0] * Y1 + dist[2] * Y2) / dist[1] - My1 - My2;
                Rbz = (-dist[0] * Z1 + dist[2] * Z2) / dist[1] - Mz1 - Mz2;
            } else {
                Rby = (-dist[0] * Y1 - dist[2] * Y2) / dist[1] - My1 - My2;
                Rbz = (-dist[0] * Z1 - dist[2] * Z2) / dist[1] - Mz1 - Mz2;
            }
            if (forces[1] == 3) {
                dist[0] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                Ray = (dist[0] * Y1 - dist[2] * Y2) / dist[1] - My1 - My2;
                Raz = (dist[0] * Z1 - dist[2] * Z2) / dist[1] - Mz1 - Mz2;
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                Ray = (-dist[2] * Y1 - dist[0] * Y2) / dist[1] - My1 - My2;
                Raz = (-dist[2] * Z1 - dist[0] * Z2) / dist[1] - Mz1 - Mz2;
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
    switch (forces[0]) {
        case 1:
            dist[1] += dist[0];
            dist[2] += dist[1];
            if (forces[1] == 3) {
                cout << "Rby = (" << -dist[0] << " * Y1 - " << dist[2] << " * Y2) / " << dist[1]
                     << " - My1 - My2 = " << Rby << '\n';
                cout << "Rbz = (" << -dist[0] << " * Z1 - " << dist[2] << " * Z2) / " << dist[1]
                     << " - Mz1 - Mz2 = " << Rbz << '\n';
            } else {
                cout << "Rby = (" << -dist[0] << " * Y1 - " << dist[1] << " * Y2) / " << dist[2]
                     << "- My1 - My2 = " << Rby << '\n';
                cout << "Rbz = (" << -dist[0] << "* Z1 - " << dist[1] << " * Z2) / " << dist[2]
                     << "- Mz1 - Mz2 = " << Rbz << '\n';
            }
            if (forces[1] == 3) {
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[0] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                cout << "Ray = (" << dist[1] << "* Y1 - " << dist[2] << " * Y2) / " << dist[0] << "- My1 - My2 = "
                     << Ray << '\n';
                cout << "Raz = (" << dist[1] << "* Z1 - " << dist[2] << " * Z2) / " << dist[0] << "- Mz1 - Mz2 = "
                     << Raz << '\n';
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                cout << "Ray = (" << -dist[1] << " * Y1 - " << dist[0] << " * Y2) / " << dist[2]
                     << " - My1 - My2 = " << Ray << '\n';
                cout << "Raz = (" << -dist[1] << " * Z1 - " << dist[0] << " * Z2) / " << dist[2]
                     << " - Mz1 - Mz2 = " << Raz << '\n';
            }
            break;
        case 2:
            dist[2] = 0.5 * l2 + l3 + 0.5 * l4 + 0.5 * l4 + 0.5 * l5;
            if (forces[1] == 3) {
                Rby = (-dist[0] * Y1 + dist[2] * Y2) / dist[1] - My1 - My2;
                Rbz = (-dist[0] * Z1 + dist[2] * Z2) / dist[1] - Mz1 - Mz2;
            } else {
                Rby = (-dist[0] * Y1 - dist[2] * Y2) / dist[1] - My1 - My2;
                Rbz = (-dist[0] * Z1 - dist[2] * Z2) / dist[1] - Mz1 - Mz2;
            }
            if (forces[1] == 3) {
                dist[0] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                Ray = (dist[0] * Y1 - dist[2] * Y2) / dist[1] - My1 - My2;
                Raz = (dist[0] * Z1 - dist[2] * Z2) / dist[1] - Mz1 - Mz2;
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                Ray = (-dist[2] * Y1 - dist[0] * Y2) / dist[1] - My1 - My2;
                Raz = (-dist[2] * Z1 - dist[0] * Z2) / dist[0] - Mz1 - Mz2;
            }
            break;
    }

}