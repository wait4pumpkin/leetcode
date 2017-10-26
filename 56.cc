/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.empty()) return vector<Interval>();

		sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return (a.start < b.start) || (a.start == b.start && a.end < b.end); });

		vector<Interval> result;
		result.push_back(intervals[0]);

		for (auto n = 1; n < intervals.size(); ++n) {
			auto& last = result.back();
			const auto& current = intervals[n];
			if (current.start <= last.end) {
				last.end = max(last.end, current.end);
			} else {
				result.push_back(current);
			}
		}
		return result;
	}
};
