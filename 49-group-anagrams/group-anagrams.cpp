class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s: strs){
            string temp=s;
            sort(s.begin(), s.end());
            mp[s].push_back(temp);
        }
        vector<vector<string>> res;
        for(auto &[key,anagrams]: mp){
            res.push_back(anagrams);
        }
        return res;
    }
};