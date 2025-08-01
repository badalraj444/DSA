// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int count = 0;
//         bool change = true;
//         bool unrotten = false;
//         while(change){
//             change = false;
//             unrotten = false;
//             vector<vector<int>> grid2(grid.begin(),grid.end());
//             for(int i = 0; i<m; i++){
//                 for(int j = 0; j<n; j++){
//                     if(grid2[i][j] ==1 && rottenNeighbour(i,j,grid2,m,n)){
//                         grid[i][j] = 2;
//                         change = true;
//                     }
//                     if(grid[i][j]==1)unrotten = true;
//                 }
//             }
//             if(change)count++;
//         }
//         if(unrotten) return -1;
//         return count;
//     }
//     private:
//     bool rottenNeighbour(int i, int j, vector<vector<int>>&  grid, int m, int n){
//         if(i-1>=0 && grid[i-1][j]==2)return true;
//         if(i+1<m && grid[i+1][j]==2)return true;
//         if(j-1>=0 && grid[i][j-1]==2)return true;
//         if(j+1<n && grid[i][j+1]==2)return true;
//         return false;
//     }
// };

// /*
// KEY-OBSERVATIONS & INSIGHTS:
// . count no of iterations it taks
// . if in end, any orange remains as not 2 or 0, ret -1 
// . in any iteration, go find a 1, check if any neighbour is 2, update it to 2. 
// . stop iteration if no change
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int l = q.size();
            while(l--){
                auto [i,j] = q.front();q.pop();
                if(i-1>=0 && grid[i-1][j]==1){
                    grid[i-1][j] = 2;
                    q.push({i-1,j});
                }
                if(i+1<m && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(j+1<n && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
            if(!q.empty())count++;
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)return -1;
            }
        }

        return count;
    }
    
};

/*
KEY-OBSERVATIONS & INSIGHTS:
. use  bfs, count how many iterations it takes
. push first rotten element
loop: n = size of queue
. pop an element(rotten)
. mark it 0, so it doesnt get reconsidered at all in the picture
. push into queue all its neighbours with value 1 and mark rotten, (change value to 2)
. repeat untill n--
. inc count in each iteration
.  check if any val remains with 1, return -1 
. ret count
ALGO:


PROBLEMS:

*/