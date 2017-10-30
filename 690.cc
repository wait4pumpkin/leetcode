/*
// Employee info
class Employee {
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};
*/
class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		unordered_map<int, Employee*> lookup;
		for (auto employee : employees) {
			lookup[employee->id] = employee;
		}

		int result = 0;
		stack<Employee*> pending;
		pending.push(lookup[id]);
		while (!pending.empty()) {
			auto node = pending.top();
			pending.pop();

			result += node->importance;
			for (auto child : node->subordinates) {
				pending.push(lookup[child]);
			}
		}
		return result;
	}
};