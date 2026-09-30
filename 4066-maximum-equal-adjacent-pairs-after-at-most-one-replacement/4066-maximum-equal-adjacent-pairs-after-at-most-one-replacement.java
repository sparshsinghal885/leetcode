import java.util.*;

class Solution {
    public int maxEqualAdjacentPairs(int[] nums) {
        int n = nums.length;
        int base = 0, newPairs = 0;
        HashMap<Long,Integer> mp = new HashMap<>();
        
        for(int i=0; i<n-1; i++){
            int a = nums[i], b = nums[i+1];

            if(a == b) base++;
            else{
                int u = Math.min(a, b);
                int v = Math.max(a, b);
                long key = ((long)u << 32) | v;
                int cnt = mp.getOrDefault(key, 0) + 1;

                mp.put(key, cnt);
                if(cnt > newPairs) newPairs = cnt;
            }
        }

        return base + newPairs;
    }
}