#include <bits/stdc++.h>
using namespace std;
#define int long long

struct dsu {
    vector<int> par, sz;
    dsu(int n): par(n), sz(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int root(int a) {
        if (a == par[a]) return a;
        return par[a] = root(par[a]);
    }
    void merge(int a, int b) {
        a = root(a);
        b = root(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};

vector<int> connectedCities(int n, int g, vector<int> from, vector<int> to) {
    dsu d(n);
    for (int k = g + 1; k <= n; k++) {
        for (int x = 2 * k; x <= n; x += k) {
            d.merge(x - 1, x - k - 1);
        }
    }

    int m = from.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        ans.push_back(d.root(from[i] - 1) == d.root(to[i] - 1));
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    int g;
    cin >> g;
    int originCities_cnt;
    cin >> originCities_cnt;
    vector<int> originCities(originCities_cnt);
    for(int originCities_i = 0; originCities_i < originCities_cnt; originCities_i++){
    	cin >> originCities[originCities_i];
    }
    int destinationCities_cnt;
    cin >> destinationCities_cnt;
    vector<int> destinationCities(destinationCities_cnt);
    for(int destinationCities_i = 0; destinationCities_i < destinationCities_cnt; destinationCities_i++){
    	cin >> destinationCities[destinationCities_i];
    }
    vector <int> res = connectedCities(n, g, originCities, destinationCities);
    for (ssize_t i = 0; i < res.size(); i++) {
        cout << res[i] << (i != res.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
