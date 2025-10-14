/*
https://codeforces.com/problemset/problem/1891/B
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
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<ll> x(q);
        for (int i = 0; i < q; i++) cin >> x[i];
        // finding the effective sequence
        vector<ll> x_eff;
        x_eff.push_back(x[0]);
        ll prev = x[0];
        for (int i = 1; i < q; i++) {
            if (x[i] < prev) {
                x_eff.push_back(x[i]);
                prev = x[i];
            }
        }
        int q1 = x_eff.size();
        vector<ll> suff(q1);
        suff[q1 - 1] = 1 << (x_eff[q1-1] - 1);
        for (int i = q1-2; i >= 0; i--) suff[i] = suff[i+1] + (1 << (x_eff[i] - 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < q1; j++) { // even if two loops, still TC O(30*n) because of the strictly decreasing nature of x_eff
                ll num = 1 << x_eff[j];
                if (a[i] % num != 0) continue;
                a[i] += suff[j];
                break;
            }
        }
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}