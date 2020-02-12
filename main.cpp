#include <iostream>
#include "input_date.h"
using namespace std;

int main() {
    int t, ALF, BT1, BT2, W, DK1, DK2, FI1, FI2, L1,  L2, L3, L4, L5, ETA1, ETA2, ETA3, n1, n2, n3;
    cin >> t >> ALF >> BT1 >> BT2 >> W >> DK1 >> DK2 >> FI1 >> FI2 >> L1 >> L2 >> L3 >> L4 >> L5 >> ETA1 >> ETA2 >>
    ETA3 >> n1 >> n2 >> n3;
InputDate InpD(t, ALF, BT1, BT2, W, DK1, DK2, FI1, FI2, L1,  L2, L3, L4, L5, ETA1, ETA2, ETA3, n1, n2, n3);
}
