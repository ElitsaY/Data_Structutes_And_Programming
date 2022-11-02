﻿#include<iostream>
#include "abstract_queue.hpp"
#include "squeue.hpp"
#include "abstract_stack.hpp"
#include "lstack.hpp"
#include<vector>

// -------------------------------------- task from seminar 4 ----------------------------------
template<typename T>
void printQueue(StaticQueue<T> queue)
{
	//приема се по копие, за да не се променя оригиналната опашка
	//че да си я ползвам пак :D
	while (!queue.empty())
	{
		std::cout << queue.dequeue() << " ";
	}
	std::cout << std::endl;
}


template<typename T>
StaticQueue<T> reverseQueue(StaticQueue<T> queue)
{
	//отново приемаме по копие опашката, за да я обходим
	LinkedStack<T> container;
	while (!queue.empty())
	{
		container.push(queue.dequeue());
	}
	while (!container.empty())
	{
		queue.enqueue(container.pop());
	}
	return queue;
}

std::vector<int> findSlidinfWindowMaxValues_fast(std::vector<int> const& numbers, int windowSize)
{
	StaticQueue<int> queue;
	std::vector<int> answer;

	for (int el : numbers)
	{
		queue.enqueue(el);
	}

	int currentMaxElement = numbers[0];

	return answer;
}

std::vector<int> findSlidinfWindowMaxValues_slow(std::vector<int> const& numbers, int windowSize)
{
	std::vector<int> answer;
	return answer;
}

//----------------------- test for my functions -----------------------------------------------

void test_Print_And_Reverse_QueueOperations()
{
	//използвано е camel case, за да се отличат имената на функциите, за които е направен този
	//неформален ръчен тест
	std::cout << "Print_And_Reverse_QueueOperations" << std::endl;
	std::cout << "Expected: 17 5 12 10" << std::endl;

	StaticQueue<int> myQueue;
	myQueue.enqueue(10);
	myQueue.enqueue(12);
	myQueue.enqueue(5);
	myQueue.enqueue(17);

	printQueue(reverseQueue(myQueue));
	//expected 17 5 12 10
	std::cout << std::endl;
}

//vector of  -1 5 10 4 123 -9 0 -1 
//window size = 3
// 10   --- [-1 5 10]
// 10   --- [5 10 4]
// 123  --- [10 4 123]
// 123  --- [4 123 -9]
// 123  --- [123 -9 0]
// 0    --- [-9  0 -1]

void test_findSlidinfWindowMaxValues()
{
	std::cout << "findSlidinfWindowMaxValues" << std::endl;
	std::cout << "Expected: 10 10 123 123 123 0" << std::endl;
	std::cout << std::endl;

	std::vector<int> myVector(8);
	myVector.push_back(-1);
	myVector.push_back(5);
	myVector.push_back(10);
	myVector.push_back(4);
	myVector.push_back(123);
	myVector.push_back(-9);
	myVector.push_back(0);
	myVector.push_back(-1);

	const int SLIDING_WINDOW = 3;

	std::cout << "----Fast solution---" << std::endl;
	std::vector<int> ans(findSlidinfWindowMaxValues_fast(myVector, SLIDING_WINDOW));
	for (int i = 0; i < ans.size(); i++)
		std::cout << ans[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "---Slow solution----" << std::endl;
	ans = findSlidinfWindowMaxValues_slow(myVector, SLIDING_WINDOW);
	for (int i = 0; i < ans.size(); i++)
		std::cout << ans[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	test_Print_And_Reverse_QueueOperations();
	test_findSlidinfWindowMaxValues();
}