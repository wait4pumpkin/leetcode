class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		auto radius = 0;
		auto idx = 0;
		for (auto house : houses) {
			auto current = abs(house - heaters[idx]);
			if (current <= radius) continue;

			for (auto n = idx + 1; n < heaters.size(); ++n) {
				if (abs(house - heaters[n]) <= current) {
					current = abs(house - heaters[n]);
					idx = n;
				} else {
					break;
				}
			}
			radius = max(radius, current);
		}
		return radius;
	}
};