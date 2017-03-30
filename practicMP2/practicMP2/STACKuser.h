#ifndef STACKuser
#define STACKuser
#include <iostream>

using namespace std;

template <typename T>
class Stack1 {
private:
	const int size;
	int top;
	struct Node {
		T d; Node *p;
	};
	Node *pn = new Node;
public:
	Stack1(int);
	~Stack1();
	inline void push(const T &);
	inline T pop();
	inline void printStack();
};
template <typename T>
Stack1<T>::Stack1(int maxSize) :
size(maxSize)
{
	pn = new Node[size];
	top = 0;
}
template <typename T>
Stack1<T>::~Stack1()
{
	delete[] pn;
}
template <typename T>
inline void Stack1<T>::push(const T &d1)
{
	if (top == 0) { pn->d = d1; pn->p = NULL; top++; }
	else
		if (top < size) {
			Node *q = new Node; q->d = d1;
			q->p = pn; pn = q; top++;
		}
		else cout << "Переполнение стека\n";
}
template <typename T>
inline T Stack1<T>::pop()
{
	T data = NULL; if (top == 0) cout << "Пустой стек\n";
	else
	{
		Node *q = new Node; q = pn; data = pn->d; pn = pn->p;
		delete q; top--;
	}
	return data;
}
template <typename T>
inline void Stack1<T>::printStack()
{
	while (pn) {
		cout << pn->d << "\n";
		pn = pn->p;
	}
}
#endif