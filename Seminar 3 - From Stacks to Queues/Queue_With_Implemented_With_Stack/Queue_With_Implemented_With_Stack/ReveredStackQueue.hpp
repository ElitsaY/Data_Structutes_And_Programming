#pragma once
#include"Abstract_Queue.hpp"
#include"lstack.hpp"

template<typename T>
class ReversedStackQueue : public AbstractQueue<T>
{
private:
	//store elements in the stack
	LinkedStack<T> container;
	// queue = reverse order stack
	LinkedStack<T> queue;

public:
	//създава празен контейнер
	ReversedStackQueue();

	//проверява дали контейнерът е празен
	bool empty() const;

	// намиране на последния включен елемент
	T const& peek() const;

	// безопасно намиране на последния включен елемент с индикация за успех
	bool peek(T&) const;

	// изключване на последния включен елемент
	T pop();

	// изключване на последния включен елемент с код за грешка
	T pop(bool& success);
};

template<typename T>
ReversedStackQueue<T>::ReversedStackQueue()
{
	container = new LinkedStack();
	queue = new LinkedStack();
}