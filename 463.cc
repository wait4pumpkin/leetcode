class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;

		int result = 0;
		auto nRow = grid.size();
		auto nCol = grid[0].size();
		for (auto r = 0; r < nRow; ++r) {
			for (auto c = 0; c < nCol; ++c) {
				if (grid[r][c]) {
					result += 4
						- ((r + 1 < nRow && grid[r + 1][c]) ? 2 : 0)
						- ((c + 1 < nCol && grid[r][c + 1]) ? 2 : 0);
				}
			}
		}
		return result;
	}
};