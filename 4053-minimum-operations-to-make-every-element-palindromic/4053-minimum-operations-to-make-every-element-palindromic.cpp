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
const ll limit = 1e9;

vector<ll> odds, evens;

bool precompute() {

    for (int i = 1; i <= 100000; i++) {

        string s = to_string(i);

        string rev = s;
        reverse(b2e(rev));

        string even = s + rev;
        ll val1 = stoll(even);

        if (val1 <= limit) {
            if (val1 & 1)
                odds.pb(val1);
            else
                evens.pb(val1);
        }

        string odd = s.substr(0, s.size() - 1) + rev;
        ll val2 = stoll(odd);

        if (val2 <= limit) {
            if (val2 & 1)
                odds.pb(val2);
            else
                evens.pb(val2);
        }
    }

    sort(b2e(odds));
    sort(b2e(evens));

    return true;
}

bool computed = precompute();

class Solution {
public:

    ll getCost(ll num, vector<ll>& target) {

        auto it = lower_bound(b2e(target), num);

        ll ans = LLONG_MAX;

        if (it != target.end())
            ans = min(ans, abs(num - *it));

        if (it != target.begin()) {
            --it;
            ans = min(ans, abs(num - *it));
        }

        return ans / 2;
    }

    long long minOperations(vector<int>& nums) {

        ll ans = 0;

        for (int num : nums) {

            vector<ll>& target = (num & 1) ? odds : evens;

            ans += getCost(num, target);
        }

        return ans;
    }
};

static const auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();