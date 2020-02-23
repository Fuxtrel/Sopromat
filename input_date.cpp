#include "input_date.h"

InputDate::InputDate(ofstream &fout) {
    cin >> T;
    fout << "Внешний возвращающий момент: \\\\\n";
    fout << "T = " << T << "Нм\\\\\n";
    alf = (20 * 3.14) / 180;
    fout << "Угловые параметры зубчатых зацеплений: \\\\\n";
    fout << "\\alpha = " << 20 << "{\\circ}\\\\\n";
    cin >> bt1 >> bt2;
    fout << "\\beta_1 = " << bt1 << "{\\circ}\\\\\n";
    fout << "\\beta_2 = " << bt2 << "{\\circ}\\\\\n";
    bt1 = (bt1 * 3.14) / 180;
    bt2 = (bt2 * 3.14) / 180;
    cin >> w;
    fout << "Угловая скорость: \\\\\n";
    fout << "\\omega = " << w << "\\frac{рад}{с}\\\\\n";
    cin >> dk1 >> dk2;
    fout << "Диаметры зубчатых колёс: \\\\\n";
    fout << "\\d_{k1} = " << dk1 << "м\\\\\n";
    fout << "\\d_{k2} = " << dk2 << "м\\\\\n";
    cin >> fi1 >> fi2;
    fout << "Угловые координаты точек зацепления зубчатых колёс: \\\\\n";
    fout << "\\beta_2 = " << bt2 << "{\\circ}\\\\\n";
    fout << "\\beta_2 = " << bt2 << "{\\circ}\\\\\n";
    fi1 = (fi1 * 3.14) / 180;
    fi2 = (fi2 * 3.14) / 180;
    cin >> l1 >> l2 >> l3 >> l4 >> l5;
    fout << "Длины участков вала: \\\\\n";
    fout << "\\l_1 = " << l1 << "м\\\\\n";
    fout << "\\l_2 = " << l2 << "м\\\\\n";
    fout << "\\l_3 = " << l3 << "м\\\\\n";
    fout << "\\l_4 = " << l4 << "м\\\\\n";
    fout << "\\l_5 = " << l5 << "м\\\\\n";
    cin >> eta1 >> eta2 >> eta3;
    cin >> N1 >> N2 >> N3;
    fout << "Коэффициенты перегрузки \\\\\n";
    fout << "\\eta_1 = " << eta1 << "\\\\\n";
    fout << "\\eta_2 = " << eta2 << "\\\\\n";
    fout << "\\eta_3 = " << eta3 << "\\\\\n";
    fout << "Длительность ступени: \\\\\n";
    fout << "\\N_1 = " << N1 << "циклов\\\\\n";
    fout << "\\N_2 = " << N2 << "циклов\\\\\n";
    fout << "\\N_3 = " << N3 << "циклов\\\\\n";
    cin >> material;
    for(string &i : sootnoshenie){
        i += "d_";
        string tmp, tmp1;
        cin >> tmp >> tmp1;
        i += tmp + " = " + tmp1 + "d_";
        cin >> tmp;
        i += tmp;
    }
    for(string &i : otnoshenie){
        cin >> i;
    }
    Ft1 = T * 2 / dk1;
    Ft2 = T * 2 / dk2;
    Fr1 = Ft1 * (tan(alf)) / (cos(bt1));
    Fr2 = Ft2 * (tan(alf)) / (cos(bt2));
    Fx1 = Ft1 * tan(bt1);
    Fx2 = Ft2 * tan(bt2);
}


defXYZ::defXYZ(ofstream &fout) {
    sign = 0;
    //Расчёт X1, Y1, Z1
    //fout << "Введите знак перед слагаемым Fx1\n";
    cin >> sign;
    X1 = sign * Fx1;
    //fout << "Введите знак перед слагаемым Ft1\n";
    cin >> sign;
    Y1 += sign * Ft1 * sin(fi1);
    //fout << "Введите знак перед слагаемым Fr1\n";
    cin >> sign;
    Y1 += sign * Fr1 * cos(fi1);
    //fout << "Введите знак перед слагаемым Ft1\n";
    cin >> sign;
    Z1 += sign * Ft1 * cos(fi1);
    //fout << "Введите знак перед слагаемым Fr1\n";
    cin >> sign;
    Z1 += sign * Fr1 * sin(fi1);
    //fout << "Введите знак перед слагаемым My1\n";
    cin >> sign;
    My1 = sign * Fx1 * (dk1 / 2) * sin(fi1);
    //fout << "Введите знак перед слагаемым Mz1\n";
    cin >> sign;
    Mz1 = sign * Fx1 * (dk1 / 2) * cos(fi1);
    //Расчёт X2, Y2, Z2
    //fout << "Введите знак перед слагаемым Fx2\n";
    cin >> sign;
    X2 = sign * Fx2;
    //fout << "Введите знак перед слагаемым Ft2\n";
    cin >> sign;
    Y2 += sign * Ft2 * sin(fi2);
    //fout << "Введите знак перед слагаемым Fr2\n";
    cin >> sign;
    Y2 += sign * Fr2 * cos(fi2);
    //fout << "Введите знак перед слагаемым Ft2\n";
    cin >> sign;
    Z2 += sign * Ft2 * cos(fi2);
    //fout << "Введите знак перед слагаемым Fr2\n";
    cin >> sign;
    Z2 += sign * Fr2 * sin(fi2);
    //fout << "Введите знак перед слагаемым My2\n";
    cin >> sign;
    My2 = sign * Fx2 * (dk2 / 2) * sin(fi2);
    //fout << "Введите знак перед слагаемым Mz2\n";
    cin >> sign;
    Mz2 = sign * Fx2 * (dk2 / 2) * cos(fi2);
}

WalPosition::WalPosition(ofstream &fout) {
    dist[0] = 0.5 * l1 + 0.5 * l2;
    dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
    dist[2] = 0.5 * l4 + 0.5 * l5;
    fout << "Введите силы с лева направо, вместо реакций введите их порядковые номера";

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

void WalPosition::equipmentfout(ofstream &fout) {
    //Вывод начальных данных
    fout << "Материал вала - " << material << "\\\\\n";
    fout << "Соотношения между диаметрами ступеней вала: \\\\\n";
    for(string &i : sootnoshenie){
        fout << i << "\\\\\n";
    }
    fout << "Отношение радиусов кривизны галтелей к диаметрам вала: \\\\\n";
    for(int i = 0; i < 4; i++){
        fout << "frac{r_" << ++i << "}{d_" << ++i << "} = " << otnoshenie[i] << "\\\\\n";
    }

    fout << "\\begin{math}\\label{eq:reactiomEquation}\n";
    fout << "F_{t1} = T\\frac{2}{d_{k1}} = " << T << "\\frac{2}{" << dk1 << "} = " << Ft1 << "\\nonumber \\\\\n";
    fout << "F_{t2} = T\\frac{2}{d_{k2}} = " << T << "\\frac{2}{" << dk2 << "} = " << Ft2 << "\\nonumber \\\\\n";
    fout << "F_{r1} = F_{t1}\\frac{tan(\\alpha)}{cos(\\beta_1)} = " << Ft1 << "\\frac{" << tan(alf) << "}{" << cos(bt1)
         << "} = "
         << Fr1 << "\\nonumber \\\\\n";
    fout << "F_{r2} = F_{t2}\\frac{tan(\\alpha)}{cos(\\beta_2)} = " << Ft2 << "\\frac{" << tan(alf) << "}{" << cos(bt2)
         << "} = "
         << Fr2 << "\\nonumber \\\\\n";
    fout << "F_{x1} = F_{t1}tan(\\beta_1) = " << Ft1 << " * " << tan(bt1) << " = " << Fx1 << "\\nonumber \\\\\n";
    fout << "F_{x2} = F_{t2}tan(\\beta_2) = " << Ft2 << " * " << tan(bt2) << " = " << Fx2 << "\\nonumber \\\\\n";
    dist[0] = 0.5 * l1 + 0.5 * l2;
    dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
    dist[2] = 0.5 * l4 + 0.5 * l5;
    d1 = "(0.5l_1 + 0.5l_2)";
    d2 = "(0.5l_2 + l_3 + 0.5l_4)";
    d3 = "(0.5l_4 + 0.5l_5)";
    fout << "H_a + X_1 + X_2 = 0\\nonumber \\\\\n";
    fout << "H_a = " << Ha << "\\nonumber \\\\\n";
    switch (forces[0]) {
        case 1:
            dist[1] = 0.5 * l1 + l2 + l3 + 0.5 * l4;
            dist[2] = 0.5 * l1 + l2 + l3 + l4 + 0.5 * l5;
            d2 = "(0.5l_1 + l_2 + l_3 + 0.5l_4)";
            d3 = "(0.5l_1 + l_2 + l_3 + l_4 + 0.5l_5)";
            if (forces[1] == 3) {
                // Y1*d1  + Rny*d2 + Y2*d3 + Mz1 + Mz2 = 0
                fout << "Y_1" << d1 << " + R_{by}" << d2 << " + Y_2" << d3 << " + M_{z1} + M_{z2} = 0\\nonumber\\\\\n";
                fout << "R_{by} = " << Rby << "\\nonumber \\\\\n";
                // -Z1*d1 - Rbz*d2 - Z2*d3 + My1 + My2 = 0
                fout << "-Z_1" << d1 << " - R_{bz}" << d2 << " - Z_2" << d3 << " + M_{y1} + M_{y2} = 0\\nonumber\\\\\n";
                fout << "R_{bz} = " << Rbz << "\\nonumber \\\\\n";
            } else {
                // Y1*d1 + Y2*d2 + Rby*d3 + Mz1 + Mz2 = 0
                fout << "Y_1" << d1 << " + Y_2" << d2 << "+ R_{by}" << d3 << " + M_{z1} + M_{z2} = 0\\nonumber\\\\\n";
                fout << "R_{by} = " << Rby << "\\nonumber \\\\\n";
                // -Z1*d1 - Z2*d2 - Rbz*d3 + My1 + My2 = 0
                fout << "-Z_1" << d1 << " - Z_2" << d2 << " - R_{bz}" << d3 << " + M_{y1} + M_{y2} = 0\\nonumber\\\\\n";
                fout << "R_{bz} = " << Rbz << "\\nonumber \\\\\n";
            }
            if (forces[1] == 3) {
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[0] = 0.5 * l1 + l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                d1 = "(0.5l_1 + l_2 + l_3 + 0.5l_4)";
                d2 = "(0.5l_2 + l_3 + 0.5l_4)";
                d3 = "(0.5l_4 + 0.5l_5)";
                // -Ray*d1 - Y1*d2 + Y2*d3 + Mz1 + Mz2 = 0
                fout << "-R_{ay}" << d1 << " - Y_1" << d2 << " + Y_2" << d3 << " + M_{z1} + M_{z2} = 0\\nonumber\\\\\n";
                fout << "R_{ay} = " << Ray << "\\nonumber \\\\\n";
                // Raz*d1 + Z1*d2 - Z2*d3 + My1 + My2 = 0
                fout << "R_{az}" << d1 << " + Z_1" << d2 << " - Z_2" << d3 << " + M_{y1} + M_{y2} = 0\\nonumber\\\\\n";
                fout << "R_{az} = " << Raz << "\\nonumber \\\\\n";
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l2 + l3 + l4 + 0.5 * l5;
                dist[2] = 0.5 * l1 + l2 + l3 + l4 + 0.5 * l5;
                d1 = "(0.5l_4 + 0.5l_5)";
                d2 = "(0.5l_2 + l_3 + l_4 + 0.5l_5)";
                d3 = "(0.5l_1 + l_2 + l_3 + l_4 + 0.5l_5)";
                // -Y2*d1 - Y1*2 - Ray*d3 + Mz1 + Mz2 = 0
                fout << "-Y_2" << d1 << " - Y_1" << d2 << " - R_{ay}" << d3 << " + M_{z1} + M_{z2} = 0\\nonumber\\\\\n";
                fout << "R_{ay} = " << Ray << "\\nonumber \\\\\n";
                // Z2*d1 + Z1*2 + Raz*d3 + My1 + My2 = 0
                fout << "Z_2" << d1 << " + Z_1" << d2 << " + R_{az}" << d3 << " + M_{y1} + M_{y2} = 0\\nonumber\\\\\n";
                fout << "R_{az} = " << Raz << "\\nonumber \\\\\n";
            }
            break;
        case 2:
            dist[2] = 0.5 * l2 + l3 + 0.5 * l4 + 0.5 * l4 + 0.5 * l5;
            d3 = "0.5l_2 + l_3 + l_4 + 0.5l_5";
            if (forces[1] == 3) {
                // -Y1*d1 + Rby*d2 + Y2*d3 + Mz1 + Mz2 = 0
                fout << "-Y_1" << d1 << " + R_{by}" << d2 << " + Y_2" << d3 << " + M-{z1} + M_{z2} = 0\\nonumber\\\\\n";
                fout << "Rby = " << Rby << "\\nonumber \\\\\n";
                // Z1*d1 - Rbz*d2 - Z2*d3 + My1 + My2 = 0
                fout << "Z_1" << d1 << " - R_{bz}" << d2 << " - Z_2" << d3 << " + M_{y1} + M_{y2} = 0\\nonumber\\\\\n";
                fout << "R_{bz} = " << Rbz << "\\nonumber \\\\\n";
            } else {
                // -Y1*d1 + Rby*d3 + Y2*d2 + Mz1 + Mz2 = 0
                fout << "-Y_1" << d1 << " + R_{by}" << d3 << " + Y_2" << d2 << " + M_{z1} + M_{z2} = 0\\nonumber\\\\\n";
                fout << "R_{by} = " << Rby << "\\nonumber \\\\\n";
                // Z1*d1 - Rbz*d3 - Z2*d2 + My1 + My2 = 0
                fout << "Z_1" << d1 << " - R_{bz}" << d3 << " - Z_2" << d2 << " + M_{y1} + M_{y2} = 0\\nonumber\\\\\n";
                fout << "R_{bz} = " << Rbz << "\\nonumber \\\\\n";
            }
            if (forces[1] == 3) {
                dist[0] = 0.5 * l1 + 0.5 * l2 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[1] = 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l4 + 0.5 * l5;
                d1 = "(0.5l_1 + l_2 + l_3 + 0.5l_4)";
                d2 = "(0.5l_2 + l_3 + 0.5l_4)";
                d3 = "(0.5l_4 + 0.5l_5)";
                // -Y1*d1 - Ray*d2 + Y2*d3 + Mz1 + Mz2 = 0
                fout << "-Y_1" << d1 << " - R_{ay}" << d2 << " + Y_2" << d3 << " + M_{z1} + M_{z2} = 0\\nonumber\\\\\n";
                fout << "R_{ay} = " << Ray << "\\nonumber \\\\\n";
                // Z1*d1 + Raz*d2 - Z2*d3 + My1 + My2 = 0
                fout << "Z_1" << d1 << " + R_{az}" << d2 << " - Z_2" << d3 << " + M_{y1} + M_{y2} = 0\\nonumber\\\\\n";
                fout << "R_{az} = " << Raz << "\\nonumber \\\\\n";
            } else {
                dist[0] = 0.5 * l4 + 0.5 * l5;
                dist[1] = 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                dist[2] = 0.5 * l1 + 0.5 * l2 + 0.5 * l4 + 0.5 * l5 + 0.5 * l2 + l3 + 0.5 * l4;
                d1 = "(0.5l_4 + 0.5l_5)";
                d2 = "0.5l_2 + l_3 + l_4 + 0.5l_5)";
                d3 = "(0.5l_1 + l_2 + l_3 + l_4 + 0.5l_5)";
                // -Y1*d3 - Ray*d2 - Y2*d1 + Mz1 + Mz2 = 0
                fout << "-Y_1" << d3 << "- R_{ay}" << d2 << " - Y_2" << d1 << " + M_{z1} + M_{z2} = 0\\nonumber\\\\\n";
                fout << "R_{ay}" << Ray << "\\nonumber \\\\\n";
                // Z1*d3 + Raz*d2 + Z2*d1 + My1 + My2 = 0
                fout << "Z_1" << d3 << " + R_{az}" << d2 << " + Z_2" << d1 << " + M_{y1} + M_{y2} = 0\\nonumber\\\\\n";
                fout << "R_{az}" << Raz << "\\nonumber \\\\\n";
            }
            break;
    }
    fout << "\\end{math}";
}