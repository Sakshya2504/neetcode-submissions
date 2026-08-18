class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums,int target,int index,vector<int> &temp,int sum){
        if(index == nums.size()){
            return;
        }
        if(sum == target){
            ans.push_back(temp);
            // temp.erase(temp.begin(),temp.end());
            return;
        }
        if(sum > target) return;
        temp.push_back(nums[index]);
        helper(nums,target,index,temp,sum+nums[index]);
        temp.pop_back();
        helper(nums, target, index + 1, temp, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(nums,target,0,temp,0);
        return ans;
    }
};
