class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int even =  0, odd = 0;

        for(auto& a : nums){
            if( a % 2 == 0) even++;
            else odd++;
        }

        if(even == 0) return true;
        else if(odd  == 0) return true;
        else if(even >= 1 && odd >= 1) return true;

        return false;
    }
};