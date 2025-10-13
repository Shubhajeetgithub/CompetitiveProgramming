/*
https://codeforces.com/problemset/problem/1715/B
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
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        if (s < b * k || s > ((b+1)*k - 1 + (k-1) * (n-1))) {
            cout << -1 << endl;
            continue;
        }
        vector<ll> a(n, 0);
        ll start = 0, end = k-1;
        ll ans = k;
        while (start <= end) {
            ll mid = start + (end-start)/2;
            if (s <= b*k + mid + (n-1) * (k-1)) {
                ans = mid;
                end = mid-1;
            }
            else start = mid + 1;
        }
        a[n-1] = b * k + ans;
        ll curr = s - a[n-1];
        for (ll i = n-2; i >= 0; i--) {
            if (curr > k-1) {
                a[i] = k-1;
                curr -= (k-1);
            }
            else {
                a[i] = curr;
                curr = 0;
                break;
            }
        }
        for (ll i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}