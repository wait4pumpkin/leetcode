class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string>> lookup;
		for (auto path : paths) {
			istringstream ss(path);

			string base;
			ss >> base;

			string file;
			string content;
			while (ss >> file) {
				size_t last = 0;  
				size_t index = file.find_first_of('(', 0);
	
				content = file.substr(index + 1, file.size() - index - 2);
				lookup[content].emplace_back(base + "/" + file.substr(0, index));
			}
		}

		vector<vector<string>> result;
		for (auto item : lookup) {
			if (item.second.size() > 1) {
				result.push_back(item.second);
			}
		}
		return result;
	}
};