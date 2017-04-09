/* algo used:
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

*/

class Solution {
public:
    string reverseWords(string s) {
        int start,end;
         for(int i=0; i<s.size();){
             int start = i;
             int end = s.find(" ",i);
             i = end+1;
             if(end == -1){
                end = s.size();
                end = end-1;
                swap(start,end,s);
                break;
             }else{
                end = end-1;
                swap(start,end,s);
             }
            
             cout<<"start : "<<start<<" end: "<<end<<endl;
         }
        return s;
    }
    void swap(int start, int end,string &s){
        for(int i=start ; i<=end;i++){
            int temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};