// Problem link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstOcc(nums,target));
        ans.push_back(lastOcc(nums,target));
        return ans;
    }
    
    int lastOcc(vector<int> &nums,int target)
    {
        int low=0, high = nums.size()-1, mid, ans = -1;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
                ans = mid;
            }
        }
        
        return ans;
    }
    
    int firstOcc(vector<int> &nums,int target)
    {
        int low=0, high = nums.size()-1, mid, ans = -1;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                high = mid - 1;
                ans = mid;
            }
        }
        
        return ans;
    }
};
