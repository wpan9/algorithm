// Design a stack that supports push, pop, top, and retrieving
// the minimum element in constant time.
// 
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
//
class MinStack {
    // a vector of (val, mininal_val) 
    std::vector<std::pair<int, int>> data;
public:
    void push(int x) {
        int min = data.empty() ? x : std::min(getMin(), x);
        data.push_back(std::make_pair(x, min));
    }

    void pop() {
        assert(!data.empty());
        data.pop_back();
    }

    int top() {
        assert(!data.empty());
        return data.back().first;
    }

    int getMin() {
        assert(!data.empty());
        return data.back().second;
    }
};

    // Note that 
    //
    // push(0),push(1),push(0),getMin,pop,getMin
    //
class MinStack {
    std::vector<int> val_data;
    std::vector<int> min_index;

public:
    void push(int x) {
        if (val_data.empty())
            min_index.push_back(0);
        else if (x < getMin())
            min_index.push_back(val_data.size());
        val_data.push_back(x);
    }

    void pop() {
        assert(!val_data.empty());
        if (min_index.back() == val_data.size() - 1)
            min_index.pop_back();
        val_data.pop_back();
    }

    int top() {
        assert(!val_data.empty());
        return val_data.back();
    }

    int getMin() {
        assert(!min_index.empty());
        return val_data[min_index.back()];
    }
};
