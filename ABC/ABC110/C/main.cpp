#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

int main() {
    string S, T;
    cin >> S >> T;
    bool ok = true;
    map<char, char> ma, ima;
    for (int i = 0; i < S.size(); i++) {
        char s = S[i], t = T[i];
        if (ma.count(s) && (ma[s] != t)) ok = false; 
        if (ima.count(t) && (ima[t] != s)) ok = false; 
        ma[s] = t;
        ima[t] = s;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl; 
}