class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // first create 2d prefix sum matrix
        int rows = mat.size();
        int cols = mat[0].size();
        // adding extra 1 row / col for the layer of zeros
        vector<vector<int>>prefixSum(rows + 1, vector<int>(cols + 1, 0));
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                // formula is add element above, to the left, then same pos in original mat,
                // then subtract top left from psum
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] + mat[i-1][j-1] - prefixSum[i-1][j-1];
            }
        }
        // now create the answer matrix by using prefixSum 
        vector<vector<int>>result(rows, vector<int>(cols, 0));
            // first isolate topleft and bottomright corner points to variables
            // k = the number of rows/cols out from the center element
            // k = 1 = 3x3 mat, each ele is one away from center k
            // k = 2 = 5x5 mat, and so on
            // example of k = 1: (where ele is 7)
            // 3 4 5
            // 6 7 8
            // 9 10 11
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                // using max / min because i can't allow bounds to go outside of matrix
                // even if it gets cut off, just use closeset element in the direction
                int r1 = max(0, i - k);
                int c1 = max(0, j - k);
                int r2 = min(rows - 1, i + k);
                int c2 = min(cols - 1, j + k);
                // formula is bottom right (entire mat prefix sum val) - one left
                // ooutside of our k mat - one top outside of our k mat + top left outside of k mat
                // (because it gets subtracted twice and we need to add it back once)
                //              original p sum val.       leftside val           topside val       topleft val to add back
                result[i][j] = prefixSum[r2+1][c2+1] - prefixSum[r2+1][c1] - prefixSum[r1][c2+1] + prefixSum[r1][c1];
            }
        }
        return result;
    }
};