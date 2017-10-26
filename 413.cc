#include <vector>


using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3) return 0;

		auto result = 0;
		auto current = 0;
		for (auto n = 1; n < A.size() - 1; ++n) {
			if (A[n] - A[n - 1] == A[n + 1] - A[n]) {
				current += 1;
				result += current;
			} else {
				current = 0;
			}
		}
		return result;
	}
};
