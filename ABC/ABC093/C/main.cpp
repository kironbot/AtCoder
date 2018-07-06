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
    int A, B, C;
    cin >> A >> B >> C;

    int M = max({A, B, C});
    int S = A + B + C;
    int res=0;
    if (M % 2 == S % 2){
        res = (3*M - S) / 2;
    }
    else{
        res = (3*(M+1) -S) / 2;     
    }

    cout << res << endl;
}
