class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }

        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                          
        vector<bool> cols_bool_init(cols, false); 

        vector<vector<bool>> visited(rows, cols_bool_init);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;  
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            auto current = pq.top();
            pq.pop();
            int time = current[0], row = current[1], col = current[2];


            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            if (visited[row][col]){
                continue;
            }

            visited[row][col] = true;

            for (auto& d: directions){
                int nextRow = row + d[0];
                int nextCol = col + d[1];
                if (!isValid(visited, nextRow, nextCol)){
                    continue;
                }

                int waitTime = ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0; // using ternary operator
                int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);

                pq.push({nextTime, nextRow, nextCol});
            }

        }
        return -1;
    }
private:

    bool isValid(vector<vector<bool>>& visited, int row, int col){
        if (row >= 0 && col >= 0 && row < visited.size() && col < visited[0].size() && !visited[row][col]){
            return true;
        }
        return false;
    }
};