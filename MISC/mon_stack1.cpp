#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    /*
    (sum of max values over all subsegments) - (sum of min values over all subsegments)
    (sum of max values) = sum_{i=0}^{n} a[i] * (# subsegments where a[i] is max)
    (sum of min values) = sum_{i=0}^{n} a[i] * (# subsegments where a[i] is min)
    
    to find # subsegments where a[i] is max -> 
    a0 a1 a2 a3 a4 a5 a6 a7
    l        i  r
    a[r] > a[i], a[l] >= a[i], 
    # subsegments with a[i] max = (i-l) * (r-i)
    l and r can be found using monotonic stack

    to find # subsegments where a[i] is min -> 
    a[r] < a[i], a[l] <= a[i], -> (i-l) * (r-i), similarly using monotonic stack
    */
    
    // finding sum of max values
    ll max_sum = 0;
    std::vector<int> l(n, -1), r(n, n);
    std::stack<int> st;
    for (int i = 0; i < n; i++) {
        if (st.empty()) st.push(i);
        else {
            while (!st.empty() && a[st.top()] < a[i]) st.pop();
            if (!st.empty()) l[i] = st.top();
            st.push(i);
        }
    }
    st = std::stack<int>();
    for (int i = n-1; i >= 0; i--) {
        if (st.empty()) st.push(i);
        else {
            while (!st.empty() && a[st.top()] <= a[i]) st.pop();
            if (!st.empty()) r[i] = st.top();
            st.push(i);
        }
    }
    for (int i = 0; i < n; i++) max_sum += (a[i] * (i - l[i]) * (r[i] - i));

    // finding sum of min values
    ll min_sum = 0;
    l.assign(n, -1); r.assign(n, n); st = std::stack<int>();
    for (int i = 0; i < n; i++) {
        if (st.empty()) st.push(i);
        else {
            while (!st.empty() && a[st.top()] > a[i]) st.pop();
            if (!st.empty()) l[i] = st.top();
            st.push(i);
        }
    }
    st = std::stack<int>();
    for (int i = n-1; i >= 0; i--) {
        if (st.empty()) st.push(i);
        else {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (!st.empty()) r[i] = st.top();
            st.push(i);
        }
    }
    for (int i = 0; i < n; i++) min_sum += (a[i] * (i - l[i]) * (r[i] - i));

    std::cout << max_sum - min_sum << '\n';
    return 0;
}