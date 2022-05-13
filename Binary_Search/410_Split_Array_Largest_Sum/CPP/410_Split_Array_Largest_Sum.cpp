// Problem link : https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int low = INT_MIN, high = 0, mid, possibleAns = INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            high += nums[i];
            
            if(low < nums[i])
                low = nums[i];
        }
        
        
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(no_of_split(nums,mid) <= m)
            {
                high = mid - 1;
                if(possibleAns > mid)
                possibleAns = mid;
            }
            else
                low = mid + 1;
        }
        
        return possibleAns;
        
    }
    
    
    int no_of_split(vector<int> &nums, int sum)
    {
        int tempSum = 0, noOfSplit = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(tempSum + nums[i] <= sum)
                tempSum += nums[i];
            else
            {
                noOfSplit++;
                tempSum = nums[i];
            }
        }
        
        noOfSplit++;
        return noOfSplit;
    }
};
