// Problem Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0, high = nums.size()-1, mid, ans = INT_MAX;
        
        while(low < high)
        {
            mid = (low + high)/2;
            
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            else if(nums[mid] >= nums[0])   // If in left part of rotated array.
            {
                ans = nums[mid];
                low = mid + 1;
            }
            else    // If in right part of rotated array.
            {
                ans = nums[mid];
                high = mid;
            }   
        }
        
        return min(nums[0],ans);
    }
};
