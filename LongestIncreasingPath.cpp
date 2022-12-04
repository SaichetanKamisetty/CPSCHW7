class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {return 0;}                      // Catch empty matrix.

        int ROWS = matrix.size();                                   // Get the Rows and Column length of the matrix. 
        int COL = matrix[0].size();

        vector<vector<int>> cache(ROWS, vector<int>(COL));          // Allows us to keep track of DFS to not check paths 
                                                                    // already checked. 

        int val = 0;

        for (int r = 0; r < ROWS; ++r) {                                   
            for (int c = 0; c < COL; ++c) {
                val = max(val, DFS(matrix, cache, ROWS, COL, r, c, -1));     // Loop through matrix to get each element to calculate the
                                                                            // DFS, and then find the max path of each element in the
                                                                            // matrix
            }
        }
        return val;
    }

    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& cache, int ROWS, int COL, int r, int c, int previousVal) {
        if (r < 0 || r == ROWS || c < 0 || c == COL || matrix[r][c] <= previousVal) { return 0; }  // First case, catches all the out of
                                                                                                // bounds, and checks if val is greater
                                                                                                // so it can continue the path.

        if (cache[r][c] != 0) { return cache[r][c]; }            // 2nd case: Checks cache to see if the current point already has its path
                                                                 // calculated, if it does, return it to be added on to the DFS, 
                                                                 // and ultimately be calculated in the longestIncreasingPath function. 

        int maxPath = 1;                                          // Path length can be at minimum 1. 
        maxPath = max(maxPath, 1 + DFS(matrix, cache, ROWS, COL, r+1, c, matrix[r][c]));  // Find max of Up direction (row + 1)
        maxPath = max(maxPath, 1 + DFS(matrix, cache, ROWS, COL, r-1, c, matrix[r][c]));  // Find max of Down direction (row - 1)
        maxPath = max(maxPath, 1 + DFS(matrix, cache, ROWS, COL, r, c+1, matrix[r][c]));  // Find max of Right direction (col + 1)
        maxPath = max(maxPath, 1 + DFS(matrix, cache, ROWS, COL, r, c-1, matrix[r][c]));  // Find max of Right direction (col - 1)

        cache[r][c] = maxPath;                                                           // Map the length of the element in the 
                                                                                    // cache, so it doesn't need to be calculated again

        return maxPath;                                                             // Return the maxPath value to find the max in the 
                                                                                    // longestIncreasingPath function. 
    }
};
