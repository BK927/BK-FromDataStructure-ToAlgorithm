#include <cassert>

#include "Stack.h"
#include "SinglyLinkedList.h"
#include "FixedStack.h"

using namespace bkDS;

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

int main()
{
	TestStack();
	TestFixedStack();
	return 0;
}