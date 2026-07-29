class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mp;
        mp[0]=-1;
        int prefixSum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]= -1;
            }
        }
        for(int i=0;i<n;i++)
        {
            prefixSum+=nums[i];
            if(mp.find(prefixSum)==mp.end()){
                mp[prefixSum]=i;
            }else{
                ans=max(ans, i-mp[prefixSum]);
            }
        }
        return ans;
    }
};

/*
One small improvement: you don't need the first loop or need to modify the input array. Do the conversion while calculating the prefix sum:

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;
    mp[0] = -1;

    int prefixSum = 0;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        prefixSum += (nums[i] == 0) ? -1 : 1;

        if (mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i;
        } else {
            ans = max(ans, i - mp[prefixSum]);
        }
    }

    return ans;
}
*/

