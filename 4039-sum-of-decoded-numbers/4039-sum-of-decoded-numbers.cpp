#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;

        while(exp > 0) {
            if(exp & 1) {
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

        for(int i = 0; i < n; i++) {
            ll num = nums[i];

            int w = num % 10;
            ll d = num / 10;

            string s = to_string(d);

            int x = 0, y = 0;

            for(int j = 0; j < s.size(); j++) {
                int t = s[j] - '0';

                if(j < w) {
                    x = x * 10 + t;
                }
                else {
                    y = y * 10 + t;
                }
            }

            ans = (ans + power(x, y)) % MOD;
        }

        return ans;
    }
};