class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		if (nums.empty()) return result;
		if (k == 1) return nums;
		if (k >= nums.size()) {
			result.push_back(*max_element(nums.begin(), nums.end()));
			return result;
		}

		deque<int> window;
		window.push_back(nums[k - 1]);
		for (auto n = k - 2; n >= 0; --n) {
			window.push_front(max(nums[n], window.front()));
		}

		result.push_back(window.front());
		for (auto n = k; n < nums.size(); ++n) {
			window.pop_front();

			auto value = nums[n];
			for (auto m = static_cast<int>(window.size()) - 1; m >= 0; --m) {
				if (window[m] >= value) break;
				window[m] = value;
			}
			window.push_back(value);
			result.push_back(window.front());
		}
		return result;
	}
};