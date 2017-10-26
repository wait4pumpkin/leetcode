#include <cmath>
#include <vector>
#include <iostream>


using namespace std;


class Solution {
public:
	int numberOfCombination(int size) {
		return (size - 1) * (size - 2) / 2;
	}

	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3) return 0;

		auto result = 0;

		auto size = 2;
		auto diff = A[1] - A[0];
		for (auto n = 1; n < A.size() - 1; ++n) {
			if (A[n + 1] - A[n] == diff) {
				size += 1;
			} else {
				if (size >= 3) result += numberOfCombination(size);

				size = 2;
				diff = A[n + 1] - A[n];
			}
		}

		if (size >= 3) result += numberOfCombination(size);

		return result;
	}
};
