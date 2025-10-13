#include <bits/stdc++.h>
using namespace std;
#define int long long
class MyData {
public:
    int r;
    int i;
    MyData(int r = 0, int i = 0): r{r}, i{i} {}
    bool operator < (const MyData& o1) {
        if (r != o1.r) return r > o1.r;
        else return i < o1.i;
    }
};
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<MyData> a(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int t = (x % k == 0) ? k : x % k;
            a[i] = MyData(t, i+1);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) cout << a[i].i << " ";
        cout << endl;
    }
    return 0;
}