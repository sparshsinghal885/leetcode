#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vpll = vector<pll>;
using vpii = vector<pii>;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define b2e(v) v.begin(), v.end()
#define loop(i, a, b) for (ll i = (a); i <= (b); i++)
#define rloop(i, a, b) for (ll i = (a); i >= (b); i--)

const ll MOD = 1e9 + 7;
const ll INF = 1e15;

class Solution {
public:

    ll dp[1001][1001][2];

    ll solve(int i, int cnt, int n, int k, int started) {

        if (cnt > k)
            return 0;

        if (i == n)
            return cnt == k && started == 0;

        if (dp[i][cnt][started] != -1)
            return dp[i][cnt][started];

        ll ans = 0;

        if (!started) {

            ans += solve(i + 1, cnt, n, k, 0);

            ans += solve(i + 1, cnt, n, k, 1);

        } else {

            ans += solve(i + 1, cnt, n, k, 1);

            ans += solve(i, cnt + 1, n, k, 0);
        }

        return dp[i][cnt][started] = ans % MOD;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, n, k, 0);
    }
};

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();