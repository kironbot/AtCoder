#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int X;
    cin >> X;

    if (X == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int n = X; n >= 1; n--) {
        for (int b = 1; b <= sqrt(n); b++) {
            for (int p = 2; p <= log2(n); p++) {
                if (n == int(pow(b, p))) {
                    cout << n << endl;
                    return 0;
                }
            }
        }
    }

}
