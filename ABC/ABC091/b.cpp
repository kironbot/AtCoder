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
    int N, M;
    string s[110], t[110];
    cin >> N;
    for (int i=0; i<N; i++) cin >> s[i];
    cin >> M;
    for (int i=0; i<M; i++) cin >> t[i];

    int res=0;
    for (int i=0; i<N; i++) {
        int tmp_res=0;
        for (int j=0; j<N; j++) {
            if (s[i] == s[j]) tmp_res++;
        }
        for (int k=0; k<M; k++){
            if (s[i] == t[k]) tmp_res--;
        }
        res = max(res, tmp_res);
    }
    cout << res << endl;
}
