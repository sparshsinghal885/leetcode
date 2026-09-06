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
    long long power(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD; 
            exp >>= 1;          
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
         
        int ans = 0;

        loop(i, 0, n-1){
            ll num = nums[i];
            int w = num % 10;
            ll d = num / 10;
            string s = to_string(d);

            int x = 0, y = 0;
            loop(j, 0, s.size()-1){
                int t = s[j] - '0';
                if(j < w){
                    x = (x*10) + t;
                }
                else{
                    y = (y*10) + t;
                }
            }
            ans = (ans + power(x, y)) % MOD;
        }
        return ans;
    }
};

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();