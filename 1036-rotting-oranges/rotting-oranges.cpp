class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) { 
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};
        int count=0;
        int a = 0;
        int b = 0;
        queue<vector<int>> q;
        int minutes = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
                if(grid[i][j]==2){
                    a = i;
                    b = j;
                    q.push({a,b,minutes+1});
                }
            }
        }
        if(count==0){
            return 0;
        }
        while(!q.empty()){
            vector<int> dir = q.front();
            int x = dir[0];
            int y = dir[1];
            minutes = dir[2];
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    minutes+1;
                
                    
                    if(grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        count--;
                        q.push({nx,ny,minutes+1});
                    }

                }
            }
        }
        if(count==0){
            return minutes-1;
        }
        return -1;
    }
};