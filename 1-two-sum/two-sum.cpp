class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> result;
       unordered_map<int, int> mp;
       for(int i=0;i<nums.size();i++){
        if(mp.find(target-nums[i])!=mp.end()){
            int firstIndex = target-nums[i];
            result.push_back(mp[firstIndex]);
            result.push_back(i);
            
        } else {
            mp[nums[i]]= i;
        }

       }
       return result;
    }
};