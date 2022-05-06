// Problem Link : https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() <= nums2.size())
            return func(nums1,nums2);
        else
            return func(nums2,nums1);
    }
    
    double func(vector<int>& chotaArr, vector<int>& badaArr)
    {
        
        if(chotaArr.size() == 0)
        {
            if(badaArr.size()%2==0)
                return (badaArr[badaArr.size()/2 - 1] + badaArr[badaArr.size()/2])/2.0;
            else
                return badaArr[badaArr.size()/2];
        }
        
        
        int chotaArrSize = chotaArr.size();
        int badaArrSize = badaArr.size();
        int mergedArrSize = (chotaArrSize + badaArrSize);
        int low = 0, high = chotaArrSize, mid;
        
        
        while(low <= high)
        {
            mid = (high + low)/2;
            
            int chotaLeft, chotaRight, badaLeft, badaRight;
             
            if(mid-1 < 0)
                chotaLeft = INT_MIN;
            else
                chotaLeft = chotaArr[mid-1];
            
            if(mid == chotaArrSize)
                chotaRight = INT_MAX;
            else
                chotaRight = chotaArr[mid];
            
            int noOfElmFromBadaArr = mergedArrSize/2 - mid;
            
            if(noOfElmFromBadaArr == 0)
                badaLeft = INT_MIN;
            else
                badaLeft = badaArr[noOfElmFromBadaArr-1];
            
            if(noOfElmFromBadaArr == badaArrSize)
                badaRight = INT_MAX;
            else
                badaRight = badaArr[noOfElmFromBadaArr];
            
            if(chotaLeft <= badaRight && badaLeft <= chotaRight)
            {
                if(mergedArrSize % 2 == 0)
                    return (min(badaRight,chotaRight) + max(badaLeft,chotaLeft)) / 2.0;
                else
                    return min(badaRight,chotaRight);
            }
            else if(chotaLeft > badaRight)
            {
                high = mid - 1;
            }
            else if(badaLeft > chotaRight)
            {
                low = mid + 1;
            }
        }
        
        return 0;
    }
};
