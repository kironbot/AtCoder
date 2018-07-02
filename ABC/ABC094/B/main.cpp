#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    int A[M];
    for (int i=0; i<M; i++){
        cin >> A[i];
    }
    
    int res1=0, res2=0;
    for (int i=0; i<M; i++) {
        if (X <= A[i]) res1++;
        else res2++;
    }

    cout << min(res1, res2) << endl;
}
