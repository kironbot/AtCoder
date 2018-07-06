#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using namespace std;

int main() {
    string S;
    cin >> S;

    int ca=0, cb=0, cc=0;
    for(char c: S){
        if (c == 'a') ca++;
        else if (c == 'b') cb++;
        else if (c == 'c') cc++;
    }
    if (ca == 1 && cb == 1 && cc == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
