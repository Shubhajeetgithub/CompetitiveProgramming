/*
https://codeforces.com/problemset/problem/1899/B
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
        vector<ll> pref(n+1);
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pref[i+1] = pref[i] + a[i];
        }
        ll max_diff = LLONG_MIN;
        for (int k = 1; k <= n/2; k++) {
            if (n % k != 0) continue; // does not divide
            ll maxi = LLONG_MIN;
            ll mini = LLONG_MAX;
            for (int i = k; i <= n; i += k) {
                ll sum = pref[i] - pref[i-k];
                maxi = max(maxi, sum);
                mini = min(mini, sum);
            }
            max_diff = max(max_diff, maxi - mini);
        }
        if (max_diff == LLONG_MIN) max_diff = 0;
        cout << max_diff << endl;
    }
    return 0;
}