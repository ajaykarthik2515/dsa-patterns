class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int prefixSum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            if(mp.find(prefixSum-k)!=mp.end()){
                ans+=mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }
        return ans;

    }
};
/*
above one is optimised and here is the brute fore approach
Brute force -
int n=nums.size();
        int ans=0;
        int sum;
        for(int i=0;i<n;i++){
             sum =0;
            for(int j=i;j<n;j++){
               sum+=nums[j];
               if(sum==k) ans++;
            }
        }
        return ans;
*/