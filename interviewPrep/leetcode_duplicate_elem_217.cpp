// sort the data 
// check for consecutive element wether they are same or not
// or we can do with hash 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (!len)
            return false;
        sort(nums.begin(),nums.end());
        for(int i=0; i<len-1; i++){
            //cout<<" num 1 and 2 "<<nums[i]<<" "<<nums[i+1]<<endl;
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};