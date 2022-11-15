#pragma once

// First In First Out
template<typename T>
class AbstractQueue
{
public:
	//зачиства данните на наследниците ( :) ООП )
	virtual ~AbstractQueue() {}

	//връща върха на опашката без възможност за промяна
	virtual T& head() = 0;

	//връща върха на опашката с възможност за промяна
	virtual T const& head() const = 0;

	//проверява дали опашката е празна
	virtual bool empty() const = 0;
	
	//добавя елемент в края на опашката ( нарежда го)
	virtual void enqueue(const T&) = 0;

	//връща копие на върха на опашката и го премахва
	virtual T dequeue() = 0;

};