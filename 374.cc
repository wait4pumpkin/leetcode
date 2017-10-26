// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		auto lo = 1, hi = n;
		while (lo <= hi) {
			auto mid = lo + (hi - lo) / 2;
			auto result = guess(mid);
			if (result == 0) return mid;

			if (result > 0) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		return lo;
	}
};
