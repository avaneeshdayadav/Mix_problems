// Problem Link : https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
    public int peakIndexInMountainArray(int[] arr){
        
        return binarySearch(arr,0,arr.length-1);
        
    }
    
    
    public int binarySearch(int[] arr, int s, int e){
        
        int max = -1;
        while(s < e)
        {
            int mid = (s + e)/2;
            
            if(arr[mid] > arr[mid + 1])
            {
                max = mid;
                e = mid;
            }
            else if(arr[mid] < arr[mid + 1])
            {
                s = mid + 1;
            }
        }
        
        return max;
    }
}
