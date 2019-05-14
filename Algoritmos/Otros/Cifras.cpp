//Halla la cantidad de cifras de un número sabiendo que:
// logba (log en base b de a) + 1 = cant de cifras
//Coder: Daniel E. Cordovés Borroto
//10mo grado IPVCE Che Guevara
#include <iostream>
#include <cmath>
using namespace std;

int num, b;

int lb(int a, int b = 10) {
    return log(a) / log(b);
}

int main() {
    cin >> num >> b;
    cout << lb(num, b) + 1 << endl;

    return 0;
}
