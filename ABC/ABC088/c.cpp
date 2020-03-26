#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int c[4][4];
    
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++) cin >> c[i][j];
    }

    for (int i=1; i<=2; i++){
        if ((c[i][1] - c[i+1][1] != c[i][2] - c[i+1][2]) || (c[i][1] - c[i+1][1] != c[i][3] - c[i+1][3])) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int j=1; j<=2; j++){
        if ((c[1][j] - c[1][j+1] != c[2][j] - c[2][j+1]) || (c[1][j] - c[1][j+1] != c[3][j] - c[3][j+1])) {
            cout << "No" << endl;
            return 0;
        }
    }

        cout << "Yes" << endl;

}
