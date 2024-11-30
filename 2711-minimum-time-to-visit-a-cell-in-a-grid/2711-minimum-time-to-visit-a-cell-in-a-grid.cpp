class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // If inital moves requires more than 1 second, path not feasible 
        if (grid[0][1] > 1 && grid[1][0] > 1){
            return -1;
        }

        int rows = grid.size(), cols = grid[0].size();
        // possible movements :- down, up, left, right

        // Initialize the variables
        // A. directions 
        vector<vector<int>> directions = {{0, 1},
                                        {0, -1},
                                        {1, 0},
                                        {-1, 0}};

        // B. Now the visited vector
        // Initializing the 2d vector visited
        // 1. We need to initialize the columns with false                            
        vector<bool> cols_bool_init(cols, false); 
        // 2. Now coming to the initialization of the 2d vector of size columns
        vector<vector<bool>> visited(rows, cols_bool_init);

        // C. Priority Queue for the path
        // Priority queue storing the time taken to visit each nodes. 
        // each element will store {time, row, col}
        // this queue will be an array of these elements
        // args for the priority_queue(type of each element, type of teh array, max/min heap)
        // here greater<> means it will be min-heap
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;  
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            auto current = pq.top();
            pq.pop();
            int time = current[0], row = current[1], col = current[2];

            // Check if reached target (end condition)
            if (row == rows - 1 && col == cols - 1) {
                return time;
            }

            // Skip the cell, if its already visited
            if (visited[row][col]){
                continue;
            }
            // Cell not visited
            visited[row][col] = true;

            // Now find the next possible element for creatign the optimized path 
            // Try all the four possible directions, from the present element
            for (auto& d: directions){
                int nextRow = row + d[0];
                int nextCol = col + d[1];
                if (!isValid(visited, nextRow, nextCol)){
                    continue;
                }

                // Calculating the wait time for the next node
                // For understanding you will have to look into the leetcode explanation
                int waitTime = ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0; // using ternary operator
                int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);
                // This part is important
                pq.push({nextTime, nextRow, nextCol});
            }

        }
        return -1;
    }
private:
    // Checks if the cell is unvisited and valid
    bool isValid(vector<vector<bool>>& visited, int row, int col){
        if (row >= 0 && col >= 0 && row < visited.size() && col < visited[0].size() && !visited[row][col]){
            return true;
        }
        return false;
    }
};