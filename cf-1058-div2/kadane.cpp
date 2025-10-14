/*
https://codeforces.com/problemset/problem/1899/C
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MINF -1001

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int max_sum = INT_MIN;
        int prev = MINF;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (prev == MINF) {
                temp = a[i];
                max_sum = max(max_sum, temp);
                if (temp <= 0) { // not carrying 0 too because of parity issue
                    temp = 0;
                    prev = MINF;
                }
                else prev = a[i];
            }
            else {
                if (((abs(a[i]) & 1) ^ (abs(prev) & 1)) == 1) {
                    // opposite parity
                    temp += a[i];
                    max_sum = max(max_sum, temp);
                    if (temp <= 0) {
                        temp = 0;
                        prev = MINF;
                    }
                    else prev = a[i];
                }
                else {
                    temp = a[i];
                    max_sum = max(max_sum, temp);
                    if (temp <= 0) {
                        temp = 0;
                        prev = MINF;
                    }
                    else prev = a[i];
                }
            }
        }
        cout << max_sum << endl;
    }
    return 0;
}