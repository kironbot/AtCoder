#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int cnt=0;
    string S;
    cin >> S;

    for (int i=0; i<S.size(); i++) {
        if (S[i] == 'o') cnt++;
    }

    cout << 700 + cnt * 100 << endl;

}
