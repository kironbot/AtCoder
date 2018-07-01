#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    int cnt[210000], A[210000];

    for (int i=0; i<210000; i++){
        cnt[i] = 0;
        A[i] = 0;
    }

    int uniq=0;
    for (int i=0; i<N; i++){
        cin >> A[i];
        if (cnt[A[i]] == 0) uniq++;
        cnt[A[i]]++;
    }

    sort(cnt, cnt+210000);

    if(uniq <= K){
        cout << 0 << endl;
    }
    else{
        int res=0, i=0, j=0;
        while(j < uniq-K){
            if (cnt[i] > 0){
                res += cnt[i];
                j++;
            }
            i++;
        }
        cout << res << endl;
    }

}
