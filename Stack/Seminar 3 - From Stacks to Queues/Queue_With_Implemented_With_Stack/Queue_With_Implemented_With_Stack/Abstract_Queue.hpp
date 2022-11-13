#pragma once 
template <typename T>
class AbstractQueue {
public:
	// проверка за празнота
	virtual bool empty() const = 0;

	// включване на елемент
	virtual void push(T const& x) = 0;

	// намиране на последния включен елемент
	virtual T const& peek() const = 0;

	// изключване на последния включен елемент
	virtual T pop() = 0;

	// виртуален деструктор
	virtual ~AbstractQueue() {}
};