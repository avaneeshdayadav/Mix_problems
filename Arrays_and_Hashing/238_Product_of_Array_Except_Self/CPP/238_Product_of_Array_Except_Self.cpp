// Problem Link : https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,1);
        
        
        
        // O(n) Space Complexity and O(n) time complexity soln.
        
//         int prefixProd[n], suffixProd[n];
        
        
//         prefixProd[0] = nums[0];
//         suffixProd[n-1] = nums[n-1];
        
//         for(int i=1,j=n-2;i<n;i++,j--)
//         {
//             prefixProd[i] = prefixProd[i-1] * nums[i];
//             suffixProd[j] = suffixProd[j+1] * nums[j];
//         }
        
//         for(int i=0;i<n;i++)
//         {
//             if(i == 0)
//                 ans[i] = suffixProd[i+1];
//             else if(i == n-1)
//                 ans[i] = prefixProd[i-1];
//             else
//                 ans[i] = prefixProd[i-1] * suffixProd[i+1];
            
//         }
        
        
        // O(1) Space Complexity and O(n) time complexity.
        
        int pref = 1;
        for(int i=0;i<n;i++)
        {
            ans[i] = pref;
            pref *= nums[i];
        }
        
        int suff = 1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i] = suff * ans[i];
            suff *= nums[i];
        }
        
        return ans;
    }
};