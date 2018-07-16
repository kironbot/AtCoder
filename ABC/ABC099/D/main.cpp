#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

int main() {
    int N, C;
    cin >> N >> C;

    int D[40][40];
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> D[i][j];
        }
    }

    int c[510][510];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> c[i][j];
        }
    }

    int t[3][30];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            t[(i+j)%3][c[i][j]]++;
        }
    }
    
    ll res = 1e10;
    for (int X = 1; X <= C; X++) {
        for (int Y = 1; Y <= C; Y++) {
            if (X != Y) for (int Z = 1; Z <= C; Z++) {
                if (Z != X && Z != Y) {
                    ll tmp = 0;
                    for (int l = 1; l <= C; l++) tmp += D[l][X] * t[0][l];
                    for (int l = 1; l <= C; l++) tmp += D[l][Y] * t[1][l];
                    for (int l = 1; l <= C; l++) tmp += D[l][Z] * t[2][l];

                    res = min (res, tmp);
                }
            }
        }
    }
    
    cout << res << endl;

}
