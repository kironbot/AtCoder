#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N], cnt[N+10];
    for (int i=0; i<N; i++){
        cin >> a[i];
    }

    for (int i=0; i<N+10; i++) cnt[i] = 0;
    
    int ans=0;
    for (int i=0; i<N; i++) {
        cin >> a[i];
        if (a[i] > N) ans++;
        else cnt[a[i]]++;
    }
    
    for (int i=0; i<=N; i++) {
        if (cnt[i] != 0){
            if (cnt[i] > i) ans += cnt[i]-i;
            else if (cnt[i] < i) ans += cnt[i];
        }
    }

    cout << ans << endl;
}
