// Problem Link : https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int>sumnums;
        
        for(int i=0;i<nums.size();i++)
        {
            int temp = target-nums[i];
            if(sumnums.find(temp)!=sumnums.end()){
                return {i,sumnums[temp]};
            }
            sumnums[nums[i]] = i;
        }
        return {0,1};
    }
};