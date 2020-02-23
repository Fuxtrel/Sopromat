#include "input_date.h"
#include <fstream>


int main() {
    setlocale(LC_ALL, "Russian");
    ofstream fout;
    fout.open("text.txt");
    WalPosition WP;
    WP.equipmentCout();
    fout.close();
}
