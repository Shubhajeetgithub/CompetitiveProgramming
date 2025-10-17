/*
https://codeforces.com/problemset/problem/1881/D

calculate total exponenet of all primes and that must be divisible by n
because in one step, we can basically shift a divisor from one place to another
*/

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];

void solve() {
    int n; cin >> n;
    READ_VEC(a, n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) {
            mp[2]++;
            a[i] /= 2;
        }
        for (int j = 3; j * j <= a[i]; j += 2) {
            while (a[i] % j == 0) {
                mp[j]++;
                a[i] /= j;
            }
        }
        if (a[i] > 1) mp[a[i]]++;
    }
    for (auto& [_, cnt] : mp) {
        if (cnt % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
    }
    return 0;
}