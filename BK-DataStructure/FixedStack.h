#pragma once

#include "BaseContainer.h"

namespace bkDS
{
	template<typename T, size_t capacity>
	class FixedStack : public BaseContainer
	{
	public:
		FixedStack() = default;
		FixedStack(const FixedStack<T, capacity>& rhs);
		~FixedStack() = default;

		T& operator[](unsigned int index);
		FixedStack<T, capacity>& operator=(const FixedStack<T, capacity>& rhs);

		bool Push(const T& value);
		T Pop();
		T& Peek() const;
		bool IsFull() const;
		size_t MaxSize() const;

	private:
		T mArray[capacity]
	};

	template<typename T, size_t capacity>
	FixedStack<T, capacity>::FixedStack(const FixedStack<T, capacity>& rhs) : mSize(mSize)
	{
		for (unsigned int i = 0; i < rhs.mSize; i++)
		{
			mArray[i] = rhs.mArray[i];
		}
	}

	template<typename T, size_t capacity>
	inline T& FixedStack<T, capacity>::operator[](unsigned int index)
	{
		return mSize[index];
	}

	template<typename T, size_t capacity>
	inline FixedStack<T, capacity>& FixedStack<T, capacity>::operator=(const FixedStack<T, capacity>& rhs)
	{
		for (unsigned int i = 0; i < rhs.mSize; i++)
		{
			mArray[i] = rhs.mArray[i];
		}
		mSize = rhs.mSize;
	}

	template<typename T, size_t capacity>
	bool FixedStack<T, capacity>::Push(const T& value)
	{
		if (IsFull())
		{
			return false;
		}

		mArray[mSize++] = value;
		return true;
	}

	template<typename T, size_t capacity>
	inline T FixedStack<T, capacity>::Pop()
	{
		return mArray[--mSize];
	}

	template<typename T, size_t capacity>
	inline T& FixedStack<T, capacity>::Peek() const
	{
		return mArray[mSize - 1];
	}

	template<typename T, size_t capacity>
	bool FixedStack<T, capacity>::IsFull() const
	{
		if (mSize < capacity)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	template<typename T, size_t capacity>
	inline size_t FixedStack<T, capacity>::MaxSize() const
	{
		return capacity;
	}
}