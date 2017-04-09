/* algo used:
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1

*/

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> vect;
        string str  = to_string(n);
        int a = -1;
        do{
            int val =  atoi(str.c_str());
            //cout<<"val "<<val<<endl;
            if(val > n)
                return val;
        }while(next_permutation(str.begin(),str.end()));
        return a;
    }
};