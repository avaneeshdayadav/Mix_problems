// Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return modBinarySearch(nums,target);
    }
    
    int modBinarySearch(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size()-1, mid;
        
        while(l <= h)
        {
            mid = (l + h)/2;
            
            if(nums[mid] == target)
                return mid;
            // Check which part of array are u in
            
            // If in greater no's section left part else in smaller no's section right part
            if(nums[0] <= nums[mid])
            {
                if(target > nums[mid] || target < nums[l])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            else
            {
                if(target > nums[h] || target < nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            
        }
        
        return -1;
    }
};
