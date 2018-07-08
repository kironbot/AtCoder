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
    int N;
    cin >> N;
    vector<string> S;
    string s;
    for (int i=0; i<N; i++) {
        cin >> s;
        S.push_back(s);
    }
    
    ll cnt[5];
    for (int i=0; i<5; i++){
        cnt[i] = 0;
    }

    for (int i=0; i<N; i++) {
        if (S[i][0] == 'M') cnt[0]++;
        else if (S[i][0] == 'A') cnt[1]++;
        else if (S[i][0] == 'R') cnt[2]++;
        else if (S[i][0] == 'C') cnt[3]++;
        else if (S[i][0] == 'H') cnt[4]++;
    }

    ll res=0;
    for (int i=0; i<3; i++){
        for (int j=i+1; j<4; j++){
            for (int k=j+1; k<5; k++){
                res += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << res << endl; 
}
