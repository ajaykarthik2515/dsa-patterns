class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixSum=0;
        int ans=0;

        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int rem=prefixSum%k;
            if (rem < 0)
                rem += k; // very very imp we have to store all the remainder in non-neagrive only detailed explaination in the comment 
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
        
    }
};