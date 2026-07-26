class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int remainingSum = target-nums[i];
            if(mp.find(remainingSum)!=mp.end()){
                res.push_back(mp[remainingSum]);
                res.push_back(i);
                return res;
            }
            mp[nums[i]]=i;
        }
        return res;
       
    }

/*
Cleaner version
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}
Improvements over yours
Uses a more descriptive variable name (complement instead of remainingSum).
Returns {mp[complement], i} directly instead of creating a result vector and pushing elements.
Returns {} instead of an empty vector variable.
*/
};