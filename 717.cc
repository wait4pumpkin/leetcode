class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		auto n = 0;
		auto last = false;
		while (n < bits.size()) {
			if (bits[n] == 0) {
				last = true;
				++n;
			} else {
				last = false;
				n += 2;
			}
		}
		return last;
	}
};