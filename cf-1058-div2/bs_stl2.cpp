/*
https://codeforces.com/problemset/problem/1904/B
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
        vector<pair<ll, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        vector<ll> pref(n);
        pref[0] = a[0].first;
        for (int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i].first;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            // we can choose all elements before index i;
            int cnt = i;
            ll score = pref[i];
            int j = i;
            while (j < n) {
                int idx = lower_bound(a.begin(), a.end(), (pair<ll, int>){score+1, INT_MIN}) - a.begin();
                idx--;
                if (idx == j) break;
                cnt += (idx - j);
                score = pref[idx];
                j = idx;
            }
            b[a[i].second] = cnt;
        }
        for (int i = 0; i < n; i++) cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}