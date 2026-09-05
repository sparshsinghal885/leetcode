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
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vi dp(sum+1, INT_MAX);
        dp[0] = 0;
        
        loop(i, 0, n-1){
            vpii curr;
            int num = nums[i];

            ll x = num, count = 0;
            while(x <= sum){
                curr.pb({x, count});
                x *= 2;
                count++;
            }

            x = num;
            count = 0;
            while(x > 1){
                x /= 2;
                count++;
                if(x <= sum) curr.pb({x, count});
            }

            vi next = dp;
            for(int j=0; j<=sum; j++){
                if(dp[j] == INT_MAX) continue;

                for(auto& p : curr){
                    int x = p.ff, count = p.ss;
                    if(j + x <= sum){
                        next[j+x] = min(next[j+x], dp[j] + count);
                    }
                }
            }
            dp = next;
        }

        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};


static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();