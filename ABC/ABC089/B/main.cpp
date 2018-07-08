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
    char s[110];
    cin >> N;
    for (int i=0; i<N; i++) cin >> s[i];

    int cnt=0;
    for (int i=0; i<N; i++){
        if (s[i] == 'Y') cnt++;
    }

    puts(cnt >=1 ? "Four" : "Three");
}
