


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        int len = nums.size();
        if(len==0)
            return false;
        for(int i=0; i<len; i++){
            //cout<<"i  nums [i]  and previos loction "<<i<<" "<<nums[i]<<" "<<mp.find(nums[i])->second<<endl;
            if(mp.find(nums[i]) != mp.end() && (i- mp.find(nums[i])->second )<=k){
                return true;
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};


/* or could be this 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       unordered_set<int> s;
       
       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;
       
       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }
       
       return false;
    }
};
The basic idea is to maintain a set s which contain unique values from nums[i - k] to nums[i - 1],
if nums[i] is in set s then return true else update the set.

*/