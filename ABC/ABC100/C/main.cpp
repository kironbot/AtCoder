#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    int a[11000];
    cin >> N;

    int res = 0;
    for (int i = 0; i<N; i++) {
        cin >> a[i];
        while (a[i] > 1) {
            if (a[i] % 2 == 0) {
                ++res;
                a[i] /= 2;
            }
            else break;
        }
    }
    
    cout << res << endl;

}
