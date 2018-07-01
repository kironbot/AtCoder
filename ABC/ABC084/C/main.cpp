#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    int C[510], S[510], F[510];
    for (int i=1; i<N; i++){
        cin >> C[i] >> S[i] >> F[i];
    }

    int ans[510];

    for (int i=1; i<N; i++){
        ans[i] = S[i];
        for (int j=i; j<N; j++){
            ans[i] = max((ans[i] + F[j] - 1)/F[j] * F[j], S[j]) + C[j];
        }
    }
    ans[N] = 0;

    for (int i=1; i<=N; i++) {
        cout << ans[i] << endl;
    }

}
