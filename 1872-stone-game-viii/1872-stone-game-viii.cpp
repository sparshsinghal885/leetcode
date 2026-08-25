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
    vi prefix;
    int n;
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        prefix = vi(n);
        prefix[0] = stones[0];
        vi dp(n);
        loop(i, 1, n - 1) prefix[i] = prefix[i - 1] + stones[i];

        dp[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            int take = prefix[i] - dp[i+1];
            int not_take = dp[i+1];

            dp[i] = max(take, not_take);
        }

        return dp[1];
    }
};

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();