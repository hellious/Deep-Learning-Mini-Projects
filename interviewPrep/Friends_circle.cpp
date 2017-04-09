/* algo used:
here are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.

*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int num_connected = 0;
        vector<vector<int>> vect;
        vector<int> visited(M.size(),0);
        vector<queue<int>> no_of_comp;
        queue<int> setv;
        for(int i=0; i<M.size(); ){
            visited[i] = 1;
            for(int j=0; j<M[0].size(); j++){
                if (i==j || M[i][j] ==0)
                    continue;
                else if(visited[j]==0){
                    setv.push(j);
                }
            }
            if(!setv.empty()){
                i = setv.front();
                setv.pop();
            }else{
               num_connected++;
               int val = checkVect(visited);
                   if( val == -1){
                    return num_connected;
                }else{
                    i = val;
                }
            }
        }
        return num_connected;
    }
    int checkVect(vector<int> vect){
        for(int i=0 ; i<vect.size(); i++){
            if(vect[i] == 0)
                return i;
        }
        return -1;
    }
    
    
};