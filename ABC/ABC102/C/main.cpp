#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N], B[N];
    
    for (int i=0; i<N; i++){
        cin >> A[i];
        B[i] = A[i]-i-1;
    }
    sort(B, B+N);
    long long b = B[N/2];

    long long res=0;
    for (int i=0; i<N; i++){
        res += abs(B[i] - b);
    }
    
    cout << res << endl;
}
