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
    int dp[100005];
    int solve(int n){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];

        int ans = 1e9;
        for(int k=1; k*(k+1)/2 <= n; k++){
            ans = min(ans, k+1+solve(n-(k*(k+1)/2)));
        }

        return dp[n] = ans;
    }
    int minDays(int n) {
        memset(dp, -1, sizeof dp);
        return solve(n)-1;
    }
};


static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();