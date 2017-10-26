class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		vector<int> a = { p2[0] - p1[0], p2[1] - p1[1] };
		vector<int> b = { p3[0] - p1[0], p3[1] - p1[1] };
		vector<int> c = { p4[0] - p1[0], p4[1] - p1[1] };

		vector<int> *x, *y, *z; 
		if (a[0] * b[0] + a[1] * b[1] == 0) {
			x = &a;
			y = &b;
			z = &c;
		} else if (b[0] * c[0] + b[1] * c[1] == 0) {
			x = &b;
			y = &c;
			z = &a;
		} else if (a[0] * c[0] + a[1] * c[1] == 0) {
			x = &a;
			y = &c;
			z = &b;
		} else {
			return false;
		}

		auto width = (*x)[0] * (*x)[0] + (*x)[1] * (*x)[1];
		return width > 0 && (*z)[0] == (*x)[0] + (*y)[0] && (*z)[1] == (*x)[1] + (*y)[1] && width == (*y)[0] * (*y)[0] + (*y)[1] * (*y)[1];
	}
};