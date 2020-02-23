#include "input_date.h"



int main() {
    setlocale(LC_ALL, "Russian");
    ofstream fout;
    fout.open("ololo.txt");
    WalPosition WP(fout);
    WP.equipmentCout(fout);
    fout.close();
}
