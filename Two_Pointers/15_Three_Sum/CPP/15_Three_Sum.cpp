// Problem Link : https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        if(nums.size() < 3)
            return ans;
        
        for(int i=0;i<nums.size()-2;i++)
        {
            // Handling duplicates in this loop.
            while(i-1>=0 && nums[i] == nums[i-1] && i<nums.size()-2)
                i++; 
            
            int j = i+1, k = nums.size()-1;
            
            while(j < k)
            {
                // All while loops inside here are for handling duplicates.
                int sum = nums[k] + nums[j];
                if(sum + nums[i]  == 0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    
                    j++;
                    while(j-1 > i && nums[j] == nums[j-1] && j<k)
                        j++;
                    
                    k--;
                    while(k+1 < nums.size() && nums[k] == nums[k+1] && k>j)
                        k--;
                        
                }
                else if(sum + nums[i] < 0 )
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        } 
        return ans;
    }
};
