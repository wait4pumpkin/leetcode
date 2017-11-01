class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		
	}
	
	/** Push element x to the back of queue. */
	void push(int x) {
		major.push(x);
	}
	
	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		auto value = peek();
		minor.pop();
		return value;
	}
	
	/** Get the front element. */
	int peek() {
		if (minor.empty()) {
			while (!major.empty()) {
				auto value = major.top();
				major.pop();
				minor.push(value);
			}
		}
		return minor.top();
	}
	
	/** Returns whether the queue is empty. */
	bool empty() {
		return major.empty() && minor.empty();
	}

private:
	stack<int> major;
	stack<int> minor;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */