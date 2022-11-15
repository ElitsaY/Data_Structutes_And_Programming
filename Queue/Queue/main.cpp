#include"LinkedQueue.hpp"
#include<vector>

template<typename T>
void printQueue(LinkedQueue<T> queue)
{
	while (!queue.empty())
	{
		std::cout << queue.dequeue() << " ";
	}
	std::cout << std::endl;
}

int min(int first, int second)
{
	return first < second ? first : second;
}

int getMin(int f, int s, int t)
{
	return min(min(f, s), t);
}

std::vector<int> HamminngNumbers(int n)
{
	LinkedQueue<int> queue2(2);
	LinkedQueue<int> queue3(3);
	LinkedQueue<int> queue5(5);
	std::vector<int> hamming;

	for (int i = 1; i <= n; i++)
	{
		int nextHamming = getMin(queue2.head(), queue3.head(), queue5.head());

		if (queue2.head() == nextHamming)
			queue2.dequeue();
		if (queue3.head() == nextHamming)
			queue3.dequeue();
		if (queue5.head() == nextHamming)
			queue5.dequeue();

		hamming.push_back(nextHamming);

		queue2.enqueue(nextHamming * 2);
		//std::cout << " queue2: ";  printQueue(queue2); std::cout << std::endl;
		queue3.enqueue(nextHamming * 3);
		//std::cout << " queue3: ";  printQueue(queue3); std::cout << std::endl;
		queue5.enqueue(nextHamming * 5);
		//std::cout << " queue5: ";  printQueue(queue5); std::cout << std::endl;
	}

	return hamming;
}


void removeMinimum(LinkedQueue<int>& queue)
{
	queue.enqueue('s');
	int minElement = queue.dequeue();
	while (queue.head() != 's')
	{
		if (queue.head() < minElement)
		{
			queue.enqueue(minElement);
			minElement = queue.dequeue();
		}
		else
			queue.enqueue(queue.dequeue());
	}
	queue.dequeue();
}

void test_printQueue()
{
	std::cout << "---------------------Print Queue---------------------------" << std::endl;
	std::cout << "expected: 19 9 9 7 17 10"<<std::endl;
	LinkedQueue<int> intQueue;
	intQueue.enqueue(19);
	intQueue.enqueue(9);
	intQueue.enqueue(9);
	intQueue.enqueue(7);
	intQueue.enqueue(17);
	intQueue.enqueue(10);

	printQueue(intQueue);
}


void test_HammingNumbers()
{
	std::cout << "---------------------Hamming numbers---------------------------" << std::endl;
	std::cout << "expexted: 2 3 4 5 6 8 9 10 12 " << std::endl;

	std::vector<int> hamming = HamminngNumbers(9);
	// 2 3 4 5 6 8 9 10 12 
	for (int i = 0; i < 9; i++)
		std::cout << hamming[i] << " ";
	std::cout<<std::endl;
}

void test_removeMinimum()
{
	std::cout << "---------------------Remove Minimum---------------------------" << std::endl;
	std::cout << "expected: 5 4 10 2 3 11" << std::endl;
	LinkedQueue<int> queue;
	queue.enqueue(5);
	queue.enqueue(2);
	queue.enqueue(4);
	queue.enqueue(10);
	queue.enqueue(1);
	queue.enqueue(3);
	queue.enqueue(11);
	removeMinimum(queue);
	printQueue(queue);
}

int main()
{
	test_printQueue();
	test_HammingNumbers();
	test_removeMinimum();
}