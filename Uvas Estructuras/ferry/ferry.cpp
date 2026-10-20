
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i) {
        int l, n, largoCarro, viajes = 0;
        string ladoPuente, ladoBarco = "left";
        cin >> l >> n;
        l *= 100;

        queue<int> left, right;
        for (int j = 0; j < n; ++j) {
            cin >> largoCarro >> ladoPuente;
            if (ladoPuente == "right") {
                right.push(largoCarro);
            } else {
                left.push(largoCarro);
            }
        }

        while (!right.empty() || !left.empty()) {
            int espacioDisponible = l;
            int carrosABordo = 0;

            if (ladoBarco == "left") {
                while (!left.empty() && left.front() <= espacioDisponible) {
                    espacioDisponible -= left.front();
                    left.pop();
                    carrosABordo++;
                }
            } else {
                while (!right.empty() && right.front() <= espacioDisponible) {
                    espacioDisponible -= right.front();
                    right.pop();
                    carrosABordo++;
                }
            }

            if (carrosABordo > 0) {
                viajes++;
                if (ladoBarco == "left") {
                    ladoBarco = "right";
                } else {
                    ladoBarco = "left";
                }
            }
        }

        cout << viajes << endl;
    }

    return 0;
}