class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        
        vector<long long> dp(n, 0);
        vector<long long> suf_max(n + 1, 0); 
        
        long long ans = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            int low = i + 1, high = n - 1;
            int next_i = n; 
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (meetings[mid][0] >= meetings[i][1]) {
                    next_i = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            dp[i] = meetings[i][2]; 
            
            if (next_i < n) {
                dp[i] += (suf_max[next_i] - meetings[i][1]);
            }
            
            suf_max[i] = max(suf_max[i + 1], dp[i] + meetings[i][0]);
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};