// Problem Link : https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
          
        // Find max and min in array.
        int low,high,mid;
        low = 1;
        high = piles[0];
        
        for(int i=1;i<piles.size();i++)
        {
            if(piles[i] < low)
                low = piles[i];
            
            if(piles[i] > high)
                high = piles[i];
        }
        
        int ans = high;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            int totalHrs = 0;
            
            for(int i=0;i<piles.size();i++)
            {
                if(piles[i]%mid != 0)
                    totalHrs += (piles[i]/mid) + 1;
                else
                    totalHrs += (piles[i]/mid);
                
                if(totalHrs > h)
                    break;
            }
            
            
            if(totalHrs > h)
                low = mid + 1;
            else
            {
                ans = min(ans,mid);
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
