
using ll = long long;

class Solution {
public:
    ll sz(ll n){
        return to_string(n).size();
    }

    long long countCommas(long long n) {
        ll ans = 0;
        ll prev = 999;
        ll i = 9999;

        while(i <= n) {
            ll nums = i - prev;
            ll size = sz(i);
            ll commas = (size - 1) / 3;

            ans += commas * nums;
            prev = i;
            i = (i * 10) + 9;
        }
        
        if (n > prev) {
            ll nums = n - prev;
            ll size = sz(n);
            ll commas = (size - 1) / 3;
            ans += commas * nums;
        }

        return ans;
    }
};