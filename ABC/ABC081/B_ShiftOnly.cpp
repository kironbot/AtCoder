#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    int A[210], cnt[210];

    cin >> N;
    for (int i=0; i<N; ++i) cin >> A[i];

    int res = 1e9;

    for (int i=0; i<N; ++i){
        cnt[i] = 0;
        int x = A[i];
        while (true) {
           if ((x % 2 == 0) and (x != 0)) {
               cnt[i]++;
               x = x / 2;
           }
           else{
               break;
           }
        }
        res = min(res, cnt[i]);
    }

    cout << res << endl;

}
