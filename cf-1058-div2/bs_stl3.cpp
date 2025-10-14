/*
https://codeforces.com/problemset/problem/1873/E
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
        ll x; cin >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<ll> pref(n);
        pref[0] = 0;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + a[i-1];
        }
        vector<ll> vol(n);
        for (int i = 0; i < n; i++) vol[i] = i * a[i] - pref[i];
        // it can be proved that vol is sorted if a is sorted
        int idx = upper_bound(vol.begin(), vol.end(), x) - vol.begin();
        idx--;
        if (idx == n-1) {
            // can create larger height also
            // n * h = pref[n-1] + a[n-1] + x
            ll h = (pref[n-1] + a[n-1] + x) / n;
            cout << h << endl;
        }
        else {
            // try heights h >= a[idx] and < a[idx+1]
            // (idx + 1) * h - pref[idx] - a[idx] = x
            ll h = (pref[idx] + a[idx] + x) / (idx + 1);
            if (h >= a[idx+1] || h < a[idx]) {
                cout << a[idx] << endl;
            }
            else {
                cout << h << endl;
            }

        }
    }
    return 0;
}