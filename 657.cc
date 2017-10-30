class Solution {
public:
	bool judgeCircle(string moves) {
		auto horizonal = 0, vertical = 0;
		for (auto c : moves) {
			switch (c) {
				case 'U':
					vertical += 1;
					break;

				case 'D':
					vertical -= 1;
					break;

				case 'L':
					horizonal += 1;
					break;

				case 'R':
					horizonal -= 1;
					break;

				default:
					break;
			}
		}
		return horizonal == 0 && vertical == 0;
	}
};