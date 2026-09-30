import java.util.*;

class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int n = nums.length;
        
        Deque<Integer> min_dq = new LinkedList<>();
        Deque<Integer> max_dq = new LinkedList<>();
        long count = 0;
        int left = 0;

        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                min_dq.clear();
                max_dq.clear();
                left = i+1;
                continue;
            }

            while((min_dq.isEmpty() == false) && nums[min_dq.getLast()] >= nums[i]) 
                min_dq.removeLast();

            min_dq.addLast(i);;
            
            while((max_dq.isEmpty() == false) && nums[max_dq.getLast()] <= nums[i]) 
                max_dq.removeLast();

            max_dq.addLast(i);

            if(nums[min_dq.getFirst()] == minK && nums[max_dq.getFirst()] == maxK){
                int start = Math.min(min_dq.getFirst(), max_dq.getFirst());
                count += (start - left + 1);
            }
        }
        return count;
    }
}