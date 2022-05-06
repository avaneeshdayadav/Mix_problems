// Problem Link : https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});   
    }
    
    string get(string key, int timestamp) {
        return binarySearch(key,timestamp);
    }
    
    
    string binarySearch(string key, int timestamp)
    {
        int low = 0, high = mp[key].size()-1, mid;
        string ans = "";
        
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(mp[key][mid].second == timestamp)
                return mp[key][mid].first;
            else if(mp[key][mid].second < timestamp)
            {
                ans = mp[key][mid].first;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
