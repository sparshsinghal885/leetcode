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

const int N = 1e5 + 10;
vector<bool> prime(N, true);
vvi factors(N);

bool precompute(){
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }

    return true;
}
bool compute(){
    for(int num = 2; num < N; num++){
        int n = num;
        for(int i=2; i*i<=n; i++){
            if(n % i == 0) factors[num].pb(i);
            while(n % i == 0) n/=i;
        }
        if(n > 1) factors[num].pb(n);
    }

    return false;
}

bool t = precompute();
bool c=compute();

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> freq;

        int i=0, j=0, ans = 0;
        while(j < n){
            for(auto& f : factors[nums[j]]){
                freq[f]++;
            }

            while(freq.size() > k){
                for(auto& f : factors[nums[i]]){
                    freq[f]--;
                    if(freq[f] == 0) freq.erase(f);
                }
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
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