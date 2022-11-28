#pragma once

template <class T>
class myStack {
private:
	T* s;
	int len;
	int size;
	int top;
public:
	int getSize() { return size; };
	myStack(int cap);
	~myStack() { delete[] s; }
	bool IsEmpty();
	bool IsFull();
	void Push(T);
	void Pop();
	int Length() { return len; }
	T TopElement();
	void Display();
	int Search(T);
	bool Find(int, T&);
};

