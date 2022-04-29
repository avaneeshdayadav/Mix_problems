// Problem Link : https://leetcode.com/problems/search-a-2d-matrix/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int low = 0, high = matrix.size()-1,mid;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            // Range found condition
            if(target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size()-1])
                return bs(matrix[mid],target);
            
            if(target < matrix[mid][0])
                high = mid - 1;
            else
                low = mid + 1;
            
        }
        
        return false;
    }
    
    bool bs(vector<int> arr, int target)
    {
        int low = 0, high = arr.size()-1,mid;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(arr[mid] == target)
                return true;
            else if(arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return false;
    }
};
