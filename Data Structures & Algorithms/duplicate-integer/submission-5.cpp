// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
//         map<int,int> mp;
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
//         for(int i=0;i<nums.size();i++){
//             if(mp[nums[i]] >= 2){
//                 return true;
//             }
//         }
//         return false;
//     }
// };
class Solution{
    public:
bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> st;

    for (int x : nums) {
        if (st.find(x) != st.end())
            return true;

        st.insert(x);
    }

    return false;
}
};
