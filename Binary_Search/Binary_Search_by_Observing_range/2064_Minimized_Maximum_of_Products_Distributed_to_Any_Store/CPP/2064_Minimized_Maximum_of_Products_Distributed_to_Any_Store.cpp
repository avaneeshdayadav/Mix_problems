// Problem Link : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quant) {
        
        int low = 1, high = 100000, mid, possibleAns;
        
        
        while(low <= high)
        {
            mid = (low + high) / 2;
            
            if(no_of_split(quant,mid) > n)
                low = mid + 1;
            else
            {
                high = mid - 1;
                possibleAns = mid;
            }
        }
        return possibleAns;
    }
    
    int no_of_split(vector<int> &quant, int mid)
    {
        int noOfSplit = 0;
        for(int i=0;i<quant.size();i++)
            if(quant[i] % mid == 0)
                noOfSplit += (quant[i] / mid);
            else
                noOfSplit += (quant[i] / mid) + 1;
        
        return noOfSplit;
    }
};