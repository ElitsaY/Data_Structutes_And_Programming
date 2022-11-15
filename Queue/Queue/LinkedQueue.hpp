#pragma once
#include<iostream>
#include<exception>
#include"Abstract_Queue.h"

template<typename T>
class LinkedQueue : public AbstractQueue<T>
{
private:
	template<typename T>
	struct QueueElement
	{
		T data;
		QueueElement<T>* next;
		QueueElement(T _data, QueueElement<T>* _next = nullptr) : data(_data), next(_next) {}
	};

	QueueElement<T>* front;
	QueueElement<T>* back;

	void copyFrom(LinkedQueue<T> const& );
	void free();
public:
	LinkedQueue();
	LinkedQueue(T const& );
	LinkedQueue(LinkedQueue<T>const&);
	LinkedQueue<T>& operator = (LinkedQueue<T> const&);
	~LinkedQueue();

	virtual T const& head() const;

	virtual T& head();

	virtual bool empty() const;

	virtual void enqueue(T const&);

	virtual T dequeue();
};

template<typename T>
LinkedQueue<T>::LinkedQueue():front(nullptr), back(nullptr){}

template<typename T>
LinkedQueue<T>::LinkedQueue(T const& _data)
{
	QueueElement<T>* newElement = new QueueElement<T>{_data};
	front = back = newElement;
}

template<typename T>
LinkedQueue<T>::LinkedQueue(LinkedQueue<T> const& other)
{
	copyFrom(other);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(LinkedQueue<T> const& other)
{
	if (this != &other)
	{
		free();
		coptFrom(other);
	}
	return *this;
}

template<typename T>
LinkedQueue<T>::~LinkedQueue()
{
	free();
}

template<typename T>
T const& LinkedQueue<T>::head() const
{
	if (empty())
		throw std::runtime_error("The queue is empty_head()");
	return front->data;
}

template<typename T>
T& LinkedQueue<T>::head()
{
	if (empty())
		throw std::runtime_error("The queue is empty_head()");
	return front->data;
}

template<typename T>
bool LinkedQueue<T>::empty() const
{
	return front == nullptr;
}

template <typename T>
void LinkedQueue<T>::enqueue(T const& newData)
{
	QueueElement<T>* newElement = new QueueElement<T>{ newData };

	if (empty())
		front = back = newElement;
	else
		back = back->next = newElement;
}

template<typename T>
T LinkedQueue<T>::dequeue()
{
	if (empty())
		throw std::runtime_error("The queue is empty!_dequeue()");
	else
	{
		//в опашката има само един елемент
		if (front == back)
			back = nullptr;

		QueueElement<T>* lastElement = front;
		T lastElementData = lastElement->data;

		front = front->next;

		delete lastElement;
		return lastElementData;
	}
}

template<typename T>
void LinkedQueue<T>::copyFrom(LinkedQueue<T> const& other)
{
	if (other.empty())
		front = back = nullptr;
	else
	{
		//в опашката има поне един елемент
		QueueElement<T>* walkOther = other.front->next;

		front = new QueueElement<T>{other.front->data, nullptr};
		back = front;

		while (walkOther != nullptr)
		{
		    back->next =  new QueueElement<T>{ walkOther->data, nullptr};
			back = back->next;
			walkOther = walkOther->next;
		}
	}
}

template<typename T>
void LinkedQueue<T>::free()
{
	while (!empty())
		dequeue();
}