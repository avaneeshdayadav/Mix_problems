// Problem Link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
    public int[] twoSum(int[] arr, int target) {
        
        int i = 0, j = arr.length-1;
        int[] ans = new int[2];
        // System.out.println(j);

        while(i <= j)
        {
            int sum = arr[i] + arr[j];
            
            if(sum == target)
            {
                ans[0] = i+1;
                ans[1] = j+1;
                break;
            }
            else if(sum < target)
                i++;
            else
                j--;
            
        }
        
        return ans;
    }
}
