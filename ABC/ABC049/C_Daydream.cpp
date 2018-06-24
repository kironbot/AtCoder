#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string divide[4] = {"dream", "dreamer", "erase", "eraser"};
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    for (int i=0; i<4; ++i) reverse(divide[i].begin(), divide[i].end());

    bool isDiv = true;
    for (int i=0; i<S.size();){
        bool isDiv2 = false;
        for (int j=0; j<4; ++j){
            string d = divide[j];
            if (S.substr(i, d.size()) == d){
                isDiv2 = true;
                i += d.size();
            }
        }
        if (!isDiv2) {
            isDiv = false;
            break;
        }
    }

    if (isDiv) cout << "YES" << endl;
    else cout << "NO" << endl;
}
