class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto e:mp)
        {
            q.push(make_pair(e.second,e.first));
            
        }
        vector<int>v;
        while(k--)
        {
         v.push_back(q.top().second); 
            q.pop();
        }
        return v;
        
    }
};