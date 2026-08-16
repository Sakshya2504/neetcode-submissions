class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                count++;
            }
        }
        vector<int> ans;
        if(count >1){
            vector<int> ans(nums.size(),0);
            return ans;
        }
        else if(count == 1){
            int mul = 1;
            int index = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] == 0){
                    index = i;
                    continue;
                }
                else{
                    mul *= nums[i];
                }
            }
            vector<int> ans(nums.size(),0);
            ans[index] = mul;
            return ans;
        }
        else{
            int mul=1;
            for(int i=0;i<nums.size();i++){
                mul*=nums[i];
            }
            for(int i=0;i<nums.size();i++){
                ans.push_back(mul/nums[i]);
            }
        }
        return ans;
    }
};
