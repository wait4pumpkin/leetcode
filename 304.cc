class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		sum.resize(matrix.size() + 1);
		sum[0].resize(matrix.size() > 0 ? matrix[0].size() + 1 : 1);
		for (auto r = 0; r < matrix.size(); ++r) {
			sum[r + 1].resize(matrix[0].size() + 1);

			for (auto c = 0; c < matrix[0].size(); ++c) {
				sum[r + 1][c + 1] = sum[r + 1][c] + matrix[r][c];
			}
		}

		for (auto r = 0; r < matrix.size(); ++r) {
			for (auto c = 0; c < matrix[0].size(); ++c) {
				sum[r + 1][c + 1] += sum[r][c + 1];
			}
		}
	}
	
	int sumRegion(int row1, int col1, int row2, int col2) {
		return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
	}

private:
	vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */