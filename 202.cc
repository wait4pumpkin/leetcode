class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> loop;
		while (loop.find(n) == loop.end() && n != 1) {
			loop.insert(n);

			auto num = 0;
			while (n > 0) {
				num += (n % 10) * (n % 10);
				n /= 10;
			}
			n = num;
		}
		return n == 1;
	}
};