class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		pair<int, int> x = decode(a);
		pair<int, int> y = decode(b);

		string result;
		result.append(to_string(x.first * y.first - x.second * y.second));
		result.push_back('+');
		result.append(to_string(x.first * y.second + x.second * y.first));
		result.push_back('i');
		return result;
	}

private:
	pair<int, int> decode(const string &a) {
		int x, y;

		string content;
		auto it = a.begin();
		while (*it != '+') content.push_back(*it++);
		x = stoi(content);

		++it;
		content.clear();
		while (*it != 'i') content.push_back(*it++);
		y = stoi(content);

		return make_pair(x, y);
	}
};