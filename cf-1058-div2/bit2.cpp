/*
https://codeforces.com/problemset/problem/1909/B
Note that unlike other questions, here there is no constraint over the sum of n in all test cases
so, if for one test case TC is O(n^2), then overall it is O(t * n^2).
cf perform 10^8 operations in 1s, 500 * 100 * 100 = 5 * 10^6 which is good

Key insight---->
1) num % 2^i gives the number formed by last i digits in the binary representation of num
2) to find number of distinct numbers, often using set is better for memory reasons
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int d = 1; d <= 63; d++) {
            ll div = 1LL << d;
            set<ll> rems;
            for (int i = 0; i < n; i++) {
                ll r = a[i] % div;
                rems.insert(r);
                if (rems.size() > 2) break; 
            }
            if (rems.size() == 2) {
                cout << div << endl;
                break;
            }
        }
    }
    return 0;
}