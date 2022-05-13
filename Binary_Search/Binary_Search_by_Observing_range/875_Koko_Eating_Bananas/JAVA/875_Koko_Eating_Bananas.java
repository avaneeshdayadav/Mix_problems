// Problem Link : https://leetcode.com/problems/koko-eating-bananas/

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        
        int low = 1, high = piles[0], mid;
        
        for(int i=0;i<piles.length;i++)
        {
            if(piles[i] > high)
                high = piles[i];
            if(piles[i] < low)
                low = piles[i];
        }
        
        // Ans can never be greater than max element in array.
        int ans = high;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            int totalHrs = 0;
            
            for(int i=0;i<piles.length;i++)
            {
                totalHrs += Math.ceil((double)piles[i]/mid);
                
                if(totalHrs > h)
                    break;
            }
            
            
            if(totalHrs > h)
                low = mid + 1;
            else
            {
                ans = Math.min(ans,mid);
                high = mid - 1;
            }
        }
        
        return ans;
        
    }
}
