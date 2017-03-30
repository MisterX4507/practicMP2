#ifndef QUEUEuser
#define QUEUEuser
#include <iostream>
using namespace std;

template <typename T>
class Queue1 {
private:
	const int size;
	int n;
	struct Node {
		T d; Node *p;
	};
	Node *Get = new Node;
	Node *Put = NULL;
public:
	Queue1(int);
	~Queue1();
	inline void push(const T &);
	inline T pop();
	inline void printQueue();
};

template <typename T>
Queue1<T>::Queue1(int max) :
size(max), n(0)
{
	Get = new Node[size];
}
template <typename T>
Queue1<T>::~Queue1()
{
	delete[] Get;
}
template <typename T>
inline void Queue1<T>::push(const T &d2)
{
	if (n == size) { cout << "Переполнение очереди\n"; }
	else {
		Node *q = new Node;
		q->d = d2;
		q->p = NULL;
		if (n != 0) {
			Put->p = q;
			Put = q;
		}
		else Get = Put = q;
		n++;
	}
}
template <typename T>
inline T Queue1<T>::pop()
{
	T data = NULL; if (n == 0) cout << "Пустая очередь\n";
	else
	{
		Node *q = new Node; q = Get; data = Get->d; Get = Get->p;
		delete q; n--;
	}
	return data;
}
template <typename T>
inline void Queue1<T>::printQueue()
{
	if (n != 0) {
		Node *q = Get;
		while (q != NULL) {
			cout << q->d << " ";
			q = q->p;
		}
	}
	cout << "\n";
}
#endif