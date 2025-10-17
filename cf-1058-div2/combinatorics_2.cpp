/*
https://codeforces.com/problemset/problem/1931/D

NOTE
Use map instead of array because of space optimisation
when you see x > 10^7 , use map
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        ll x, y; cin >> x >> y;
        READ_VEC(a, n);
        map<ll, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            ll r = a[i] % y;
            mp[r].push_back(i);
        }
        ll ans = 0;
        for (auto& [r, B] : mp) {
            map<ll, ll> mp1;
            for (const int& b : B) mp1[a[b] % x]++;
            for (auto& [rA, cnt]: mp1) {
                if (rA == 0 || 2 * rA == x) ans += (cnt * (cnt - 1))/2;
                else {
                    ans += (cnt * mp1[x - rA]);
                    mp1[x-rA] = 0;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}