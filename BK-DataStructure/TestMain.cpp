#include <cassert>
#include <iostream>

#include "CircularQueue.h"
#include "Stack.h"
#include "SinglyLinkedList.h"
#include "FixedStack.h"

using namespace bkDS;
using namespace std;

void TestStack()
{
	Stack<int> s1;

	assert(s1.IsEmpty());
	assert(s1.Size() == 0);
	
	for (int i = 0; i < 10; i++)
	{
		s1.Push(i);
	}

	assert(s1.Peek() == 9);
	assert(s1.Size() == 10);

	Stack<int> s2(s1);
	Stack<int> s3;
	s3 = s1;

	assert(s1.Peek() == 9);
	assert(s1.Size() == 10);
	assert(s2.Peek() == 9);
	assert(s2.Size() == 10);
	assert(s3.Peek() == 9);
	assert(s3.Size() == 10);

	for (int i = 9; i >= 0; i--)
	{
		assert(s1.Size() == i + 1);
		assert(s1.Peek() == i);
		s1.Pop();
	}
	assert(s1.IsEmpty());

	assert(s2.Peek() == 9);
	assert(s2.Size() == 10);
	assert(s3.Peek() == 9);
	assert(s3.Size() == 10);

	for (int i = 9; i >= 0; i--)
	{
		assert(s2.Size() == i + 1);
		assert(s2.Peek() == i);
		s2.Pop();
	}

	assert(s2.IsEmpty());
	assert(s3.Peek() == 9);
	assert(s3.Size() == 10);
}

void TestFixedStack()
{
	FixedStack<int, 10> s1;

	assert(s1.IsEmpty());
	assert(s1.Size() == 0);
	assert(s1.MaxSize() == 10);

	for (int i = 0; i < 10; i++)
	{
		s1.Push(i);
	}

	assert(s1.Peek() == 9);
	assert(s1.Size() == 10);
	assert(s1.IsFull());

	for (int i = 9; i >= 0; i--)
	{
		assert(s1.Size() == i + 1);
		assert(s1.Peek() == i);
		s1.Pop();
	}
	assert(s1.IsEmpty());
}

void TestCircularQueue()
{
	CircularQueue<int> cq1(15);

	assert(cq1.IsEmpty());

	for (int i = 0; i < 15; i++)
	{
		assert(cq1.Enqueue(i));
		assert(cq1.Size() == i + 1);
		assert(cq1.Peek() == 0);
	}

	CircularQueue<int> cq2(cq1);
	CircularQueue<int> cq3 = cq2;

	assert(cq1.IsFull());
	assert(cq2.IsFull());
	assert(cq3.IsFull());

	assert(cq2.Peek() == 0);
	assert(cq3.Peek() == 0);

	for (int i = 0; i < 15; i++)
	{
		cout << "Peek: " << cq2.Peek() << endl;
		cout << "i: " << i << endl;
		assert(cq2.Peek() == i);
		assert(cq2.Dequeue());
	}
	assert(cq2.IsEmpty());

	for (int i = 0; i < 15; i++)
	{
		cout << "Peek: " << cq3.Peek() << endl;
		cout << "i: " << i << endl;
		assert(cq3.Peek() == i);
		assert(cq3.Dequeue());
	}
	assert(cq3.IsEmpty());

	for (int i = 0; i < 6; i++)
	{
		cout << "Peek: " << cq1.Peek() << endl;
		cout << "i: " << i << endl;
		assert(cq1.Peek() == i);
		assert(cq1.Dequeue());
	}

	assert(cq1.Size() == 9);

	for (int i = 15; i < 21; i++)
	{
		assert(cq1.Enqueue(i));
		assert(cq1.Peek() == 6);
	}
	assert(cq1.IsFull());

	for (int i = 0; i < 15; i++)
	{
		assert(cq1.Dequeue());
	}
	assert(cq1.IsEmpty());
}

int main()
{
	//TestStack();
	//TestFixedStack();
	TestCircularQueue();
	return 0;
}