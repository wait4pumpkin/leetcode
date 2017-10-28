class MapSum {
public:
	/** Initialize your data structure here. */
	MapSum() : root(new TreeNode()) {	
	}

	~MapSum() {
		stack<TreeNode*> pending;
		pending.push(root);
		while (!pending.empty()) {
			auto node = pending.top();
			pending.pop();

			for (auto pair : node->children) {
				pending.push(pair.second);
			}

			delete node;
		}
	}
	
	void insert(string key, int val) {
		auto node = root;
		for (auto n : key) {
			TreeNode *child;
			auto it = node->children.find(n);
			if (it == node->children.end()) {
				child = new TreeNode();
				node->children[n] = child;
			} else {
				child = it->second;
			}
			node = child;
		}
		node->value = val;
	}
	
	int sum(string prefix) {
		if (prefix.empty()) return 0;

		auto node = root;
		for (auto n : prefix) {
			auto it = node->children.find(n);
			if (it == node->children.end()) return 0;
			node = it->second;
		}
		
		int result = 0;
		stack<TreeNode*> pending;
		pending.push(node);
		while (!pending.empty()) {
			node = pending.top();
			pending.pop();

			for (auto pair : node->children) {
				pending.push(pair.second);
			}
			result += node->value;
		}
		return result;
	}

private:
	struct TreeNode {
		int value;
		unordered_map<char, TreeNode*> children;

		TreeNode() : value(0) {
		}
	};

	TreeNode *root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */