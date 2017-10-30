class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		auto result = 0;
		auto end = 0;
		for (auto n : timeSeries) {
			result += duration - max(0, (end - n));
			end = n + duration;
		}
		return result;
	}
};