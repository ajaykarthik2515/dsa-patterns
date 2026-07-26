class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c=0;
        int ans=0;
        int element;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                element = nums[i];
                c++;
                ans= max(ans, c);
            }else{
                if(nums[i]==element){
                    continue;
                }else if(nums[i]== element + 1){
                    c++;
                    element = nums[i];
                    ans= max(ans, c);
                }else {
                    c=1;
                    element = nums[i];
                }
            }
        }
        return ans;
    }
};