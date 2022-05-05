// Problem link : https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        return modified_binary_search(arr);
    }
    
    int modified_binary_search(vector<int> &arr)
    {
        int low = 0, high = arr.size()-1, mid, indx = -1;
        
        while(low < high)
        {
            mid = (low + high)/2;
            
            if(arr[mid] < arr[mid+1])
            {
                // We are in asscending part of arr, possible ans is to right side.
                low = mid + 1;
            }
            else
            {
                // We are in descending part of arr, possible ans lies in left side including this mid element can be a possible ans.
                indx = mid;
                high = mid;
            }
        }
        
        return indx;
    }
};
