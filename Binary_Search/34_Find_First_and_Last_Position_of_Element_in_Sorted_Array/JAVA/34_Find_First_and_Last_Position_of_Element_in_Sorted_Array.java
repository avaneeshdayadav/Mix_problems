// Problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int [] ans = new int[2];
        
        ans[0] = find_first_last_occ(nums, target, 1);
        ans[1] = find_first_last_occ(nums, target, 0);
        
        return ans;
    }
    
    int find_first_last_occ(int[] nums, int target, int flag)
    {
        int low = 0, high = nums.length-1, mid, ans = -1;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(target > nums[mid])
                low = mid + 1;
            else if(target < nums[mid])
                high = mid - 1;
            else
            {
                if(flag == 0)
                    low = mid + 1;
                else
                    high = mid - 1;
                
                ans = mid;
            }
        }
        
        return ans;
    }
}
