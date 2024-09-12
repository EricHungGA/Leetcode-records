class NumMatrix {
private:
    vector<vector<int>>pSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        // in this constructor we will check for edge case (empty matrix)
        // then initialize our pSum private member
        if(matrix.empty() || matrix[0].empty()) return;
        int rows = matrix.size();
        int cols = matrix[0].size();
        // adding 1 extra row / col for zeros
        pSum = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                // add left, and above, subtract diagonal left, add center pos (from mat)
                pSum[i][j] = pSum[i][j - 1] + pSum[i - 1][j] - pSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        // formula is take the pSum total val from r2c2,
        // subtact one left out of requested bounds from psum
        // subtact one above out of requested bounds from psum
        // add top left diagonal out of bounds (because it was subtracted twice)
        sum = pSum[row2+1][col2+1] - pSum[row2+1][col1] - pSum[row1][col2+1] + pSum[row1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */