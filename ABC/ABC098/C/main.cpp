#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int res = N;
    int sle=0, slw=0, sre=0, srw=0;

    for (char c: S) {
        if (c == 'E') sre++;
        else srw++;
    }

    for (char c : S) {
        if (c == 'E') {
            res = min(res, slw+sre-1);
            sle++, sre--;
        }
        else {
            res = min(res, slw+sre);
            slw++, srw--;
        }
    }
    cout << res << endl;

}
