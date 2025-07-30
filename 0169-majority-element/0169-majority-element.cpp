class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int freq = 0, ans = 0;
        for(int i=0; i<n; i++){
            if(freq == 0){
                ans = nums[i];
            }
                if(nums[i] == ans){
                    freq++;
                }
                else{
                    freq--;
                }
            }
            int count = 0;
            for(int i=0; i<n; i++){
                if(nums[i] == ans){
                    count++;
                }
            }
            if(count > n/2){
                return ans;
            }

        return -1;
    }
};