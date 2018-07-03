#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i=0; i<N; i++) cin >> A[i];

    int res=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            res = max(res, abs(A[i] - A[j]));
        }
    }
    
    cout << res << endl;
}
