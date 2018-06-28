#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    int dp[110000];
    vector<int> coin;

    cin >> N;
    coin.push_back(1);
    for (int i=6; i<=N; i*=6) coin.push_back(i);
    for (int i=9; i<=N; i*=9) coin.push_back(i);

    fill(dp, dp+N+1, 1e8);
    dp[0] = 0;
    
    for (int i=0; i<=N; i++) {
        for (int j=0; j < coin.size(); j++) {
            if (i >= coin[j]) {
                dp[i] = min(dp[i], dp[i-coin[j]] + 1);
            }
        }
    }

    cout << dp[N] << endl;

}
