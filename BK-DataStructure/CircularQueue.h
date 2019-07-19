#pragma once
#include <algorithm>
#include <cassert>
#include <memory>

#include "BaseContainer.h"

using namespace std;

namespace bkDS
{
	template<typename T>
	class CircularQueue : public BaseContainer
	{
	public:
		CircularQueue(unsigned int reservingSize);
		CircularQueue(CircularQueue<T>& rhs);
		~CircularQueue() = default;

		CircularQueue<T>& operator=(CircularQueue<T>& rhs);

		bool Enqueue(T& data);
		bool Enqueue(T&& data);
		bool Dequeue();
		T& Peek();
		bool IsFull() const;

	private:
		unsigned int mCapacity;
		unsigned int mFront;
		unsigned int mRear;
		unique_ptr<T[]> mContainer;
	};

	template<typename T>
	inline CircularQueue<T>::CircularQueue(unsigned int reservingSize) : mCapacity(reservingSize), mFront(0), mRear(0)
	{
		mContainer = make_unique<T[]>(reservingSize);
	}

	template<typename T>
	inline CircularQueue<T>::CircularQueue(CircularQueue<T>& rhs) : mCapacity(rhs.mCapacity), mFront(rhs.mFront), mRear(rhs.mRear), BaseContainer(rhs)
	{
		mContainer = make_unique<T[]>(mCapacity);

		std::copy(rhs.mContainer.get(), rhs.mContainer.get() + mCapacity, mContainer.get());
	}

	template<typename T>
	inline CircularQueue<T>& CircularQueue<T>::operator=(CircularQueue<T>& rhs)
	{
		BaseContainer::operator=(rhs);
		mCapacity = rhs.mCapacity;
		mFront = rhs.mFront;
		mRear = rhs.mRear;
		mContainer = make_unique<T[]>(mCapacity);

		std::copy(rhs.mContainer.get(), rhs.mContainer.get() + mCapacity, mContainer.get());
	}

	template<typename T>
	inline bool CircularQueue<T>::Enqueue(T& data)
	{
		if (IsFull())
		{
			return false;
		}

		mContainer[(++mRear) % mCapacity] = data;

		mSize++;
		return true;
	}

	template<typename T>
	inline bool CircularQueue<T>::Enqueue(T&& data)
	{
		if (IsFull())
		{
			return false;
		}

		mContainer[(++mRear) % mCapacity] = data;

		mSize++;
		return true;
	}

	template<typename T>
	inline bool CircularQueue<T>::Dequeue()
	{
		if (IsEmpty())
		{
			return false;
		}

		++mFront;

		mSize--;
		return true;
	}

	template<typename T>
	inline T& CircularQueue<T>::Peek()
	{
		return mContainer[(mFront + 1) % mCapacity];
	}

	template<typename T>
	inline bool CircularQueue<T>::IsFull() const
	{
		if (mCapacity <= mSize)
		{
			assert(mCapacity == mSize);
			return true;
		}
		else
		{
			return false;
		}
	}
}