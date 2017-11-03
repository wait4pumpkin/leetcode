class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		auto result = 0;
		set<pair<int, int>> visited;
		for (auto x = 0; x < grid.size(); ++x) {
			for (auto y = 0; y < grid[0].size(); ++y) {
				result = max(result, maxAreaOfIsland(grid, x, y, visited));
			}
		}
		return result;
	}

private:
	int maxAreaOfIsland(vector<vector<int>> &grid, int x, int y, set<pair<int, int>> &visited) {
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() ||
			!grid[x][y] || visited.find(make_pair(x, y)) != visited.end()) return 0;

		visited.insert(make_pair(x, y));

		return maxAreaOfIsland(grid, x - 1, y, visited)
			+ maxAreaOfIsland(grid, x, y - 1, visited)
			+ maxAreaOfIsland(grid, x + 1, y, visited)
			+ maxAreaOfIsland(grid, x, y + 1, visited) + 1;
	}
};