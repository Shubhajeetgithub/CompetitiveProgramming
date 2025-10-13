/*
https://codeforces.com/problemset/problem/1725/B
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll d;
    cin >> n >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int count = 0;
    int i = n-1;
    int j = 0;
    while (j <= i) {
        int k = (d / a[i]) + 1;
        if (k+j-1 <= i) count++;
        i--;
        j += (k-1);
    }
    cout << count << endl;
    return 0;
}