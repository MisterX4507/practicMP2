#ifndef DEQUEUEuser
#define DEQUEUEuser
#include <iostream>
using namespace std;

template <typename T>
class Dequeue {
private:
	struct Node
	{
		T* element;
		Node* leftElement;
		Node* rightElement;
	};
	Node* _leftElement;
	Node* _rightElement;
	int c;
public:
	Dequeue();
	~Dequeue();
	inline void DobavlenieLeft(T* element);
	inline void DobavlenieRight(T* element);
	inline T* IzvlechLeft();
	inline T* IzvlechRight();
	int Count();
};

template<typename T>
Dequeue<T>::Dequeue()
{
	c = 0;
	_leftElement = NULL;
	_rightElement = NULL;
}

template<typename T>
Dequeue<T>::~Dequeue()
{
	for (int i = 0; i < Count(); i++)
	{
		delete IzvlechRight();
	}
}

template<typename T>
inline void Dequeue<T>::DobavlenieLeft(T * element)
{
	Node* newNode = new Node;
	newNode->element = element;
	newNode->leftElement = NULL;
	newNode->rightElement = _leftElement;
	if (c > 0) {
		_leftElement->leftElement = newNode;
	}
	else {
		_leftElement = newNode;
		_rightElement = newNode;
	}
	_leftElement = newNode;
	c++;
}

template<typename T>
inline void Dequeue<T>::DobavlenieRight(T * element)
{
	Node* newNode = new Node;
	newNode->element = element;
	newNode->rightElement = NULL;
	newNode->leftElement = _rightElement;
	if (c > 0) {
		_rightElement->rightElement = newNode;
	}
	else {
		_leftElement = newNode;
		_rightElement = newNode;
	}
	_rightElement = newNode;
	c++;
}

template<typename T>
inline T * Dequeue<T>::IzvlechLeft()
{
	if (c != 0) {
		T* element = _leftElement->element;
		Node* q = _leftElement;
		_leftElement = _leftElement->rightElement;
		delete q;
		c--;
		return element;
	}
	else {
		cout << "Пустой дек\n"; return NULL;
	}
}

template<typename T>
inline T * Dequeue<T>::IzvlechRight()
{
	if (c != 0) {
		T* element = _rightElement->element;
		Node* q = _rightElement;
		_rightElement = _rightElement->leftElement;
		delete q;
		c--;
		return element;
	}
	else {
		cout << "Пустой дек\n"; return NULL;
	}
}

template<typename T>
inline int Dequeue<T>::Count()
{
	return c;
}
#endif