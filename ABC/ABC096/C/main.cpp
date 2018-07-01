#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    char s[60][60];

    for (int i=0; i<60; i++){
        for (int j=0; j<60; j++) {
            s[i][j] = '.';
        }
    }

    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            cin >> s[i][j];
        }
    }

    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            if (s[i][j] == '#') {
                if ((s[i-1][j] == '.') &&
                    (s[i][j-1] == '.') &&
                    (s[i+1][j] == '.') &&
                    (s[i][j+1] == '.') ) {
                        cout << "No" << endl;
                        return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;

}
