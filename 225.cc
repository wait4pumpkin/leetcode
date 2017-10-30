class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		
	}
	
	/** Push element x onto stack. */
	void push(int x) {
		major.push(x);
	}
	
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		auto value = top();
		major.pop();
		swap(major, minor);
		return value;
	}
	
	/** Get the top element. */
	int top() {
		while (major.size() > 1) {
			auto value = major.front();
			major.pop();
			minor.push(value);
		}
		return major.front();
	}
	
	/** Returns whether the stack is empty. */
	bool empty() {
		return major.empty() && minor.empty();
	}

private:
	queue<int> major;
	queue<int> minor;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */