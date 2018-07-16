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
    ll A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    /* しゃくとり法 */
    ll res = 0;
    int right = 0;
    int sum = 0;
    for (int left = 0; left < N; left++) {
        while (right < N && (sum ^ A[right]) == (sum + A[right])) {
            sum += A[right];
            right++;
        }
        res += right - left;
        if (left == right) right++;
        else sum -= A[left];
    }
    cout << res << endl;
}
