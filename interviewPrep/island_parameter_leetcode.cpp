/*
Question :
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
perimeter of the island =  island surroned with 0 or boundary

Explanation: The perimeter is the 16 yellow stripes in the image below:
https://leetcode.com/static/images/problemset/island.png

*/





class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> temp,temp2;
        int rows = grid.size();
        int cols = grid[0].size();
        int sum = 0;
        temp.assign(rows,vector<int>(cols,0));
        for(int i=0; i<rows;i++){
            for(int j=0; j<cols;j++){
               // cout<<"coming here 1 i: "<<i<<" j: "<<j<<endl;
                
                if(grid[i][j] == 0)
                    continue;
                if(i && grid[i-1][j] ==0){
                    temp[i][j] += 1;
                //    cout<<"coming here 1 "<<endl;
                }
                if(j && grid[i][j-1] == 0 ){
                    temp[i][j] += 1;
                //    cout<<"coming here 2 "<<endl;
                }
                if(i+1<rows && grid[i+1][j] == 0 ){
                    temp[i][j] += 1;
                 //   cout<<"coming here 3 "<<endl;
                }
                if(j+1<cols && grid[i][j+1] == 0 ){
                    temp[i][j] += 1;
                   // cout<<"coming here 4 "<<endl;
                }if(grid[i][j]){
                    if(j+1==cols )
                        temp[i][j] += 1;
                    if(j-1 < 0)
                        temp[i][j] += 1;
                    if(i+1 ==rows )
                        temp[i][j] += 1;
                    if(i-1<0)
                        temp[i][j] += 1;
                }
                sum = sum + temp[i][j];    
            }
        }
     
        //printVec(temp);
        //cout<<sum<<endl;
        return sum;
    }
    void printVec(vector<vector<int>> temp){
        int rows = temp.size();
        int cols = temp.size();
        for(int i=0; i<rows;i++){
            for(int j=0; j<cols;j++){
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
            
        }
    }
};