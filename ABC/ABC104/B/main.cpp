#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;

    bool flg = true;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++){
        if (i == 0) {
            if (s[i] != 'A') flg = false;
            else flg = true;
        }
        else if (1 <= i && i <= s.size() -2) {
            if (s[i] == 'C') cnt++;
            else if ('A' <= s[i] && s[i] <= 'Z') flg = false;
        }
        else {
            if ('A' <= s[i] && s[i] <= 'Z') flg = false;
        }
    }
    
    flg = (cnt == 1) && flg;
    if (flg) cout << "AC" << endl;
    else cout << "WA" << endl;
}
