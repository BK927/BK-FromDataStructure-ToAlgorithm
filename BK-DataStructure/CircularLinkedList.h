#pragma once
#include <cassert>

#include "BaseContainer.h"

namespace bkDS
{
	template<typename T>
	class CircularLinkedList : public BaseContainer
	{
	public:
		CircularLinkedList();
		CircularLinkedList(T& data);
		CircularLinkedList(const CircularLinkedList<T>& rhs);
		~CircularLinkedList();

		CircularLinkedList<T>& operator=(const CircularLinkedList<T>& rhs);
		CircularLinkedList<T> operator+(const CircularLinkedList<T>& rhs);
		void operator+=(const CircularLinkedList<T>& rhs);

		T& GetHead();
		T& GetTail();
		T& GetCurrent();
		bool Next();
		void PushBack(T& data);
		void PushBack(T&& data);
		void AddFirst(T& data);
		void AddFirst(T&& data);
		void RemoveFirst();
		void RemoveLast();
		void Clear();

	private:
		struct Node
		{
			Node(T& data, Node* next);
			T data;
			Node* next;
		};

		Node* mCurrent;
		Node* mHead;
		Node* mTail;
	};

	template<typename T>
	CircularLinkedList<T>::CircularLinkedList() : mHead(nullptr), mTail(nullptr), mCurrent(nullptr)
	{
	}

	template<typename T>
	CircularLinkedList<T>::CircularLinkedList(T& data)
	{
		mHead = new Node(data);
		mTail = mHead;
		mCurrent = mHead;
	}

	template<typename T>
	CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& rhs) : mHead(nullptr), mTail(nullptr)
	{
		Node* cursor = rhs.mHead;
		for (unsigned int i = 0; i < rhs.mSize; i++)
		{
			PushBack(cursor->data);
			cursor = cursor->next;
		}
		mCurrent = mHead;

		assert(mSize == rhs.mSize);
	}

	template<typename T>
	CircularLinkedList<T>::~CircularLinkedList()
	{
		Clear();
	}

	template<typename T>
	CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList<T>& rhs)
	{
		if (mSize > rhs.mSize)
		{
			for (unsigned int i = 0; i < mSize - rhs.mSize; i++)
			{
				RemoveFirst();
			}
			assert(mSize == rhs.mSize);
		}

		Node* thisCursor = mHead;
		Node* rhsCursor = rhs.mHead;

		for (unsigned int i = 0; i < mSize; i++)
		{
			thisCursor->data = rhsCursor->data;
			thisCursor = rhsCursor->next;
			rhsCursor = rhsCursor->next;
		}

		for (unsigned int i = mSize; i < rhs.mSize; i++)
		{
			PushBack(rhsCursor->data);
			rhsCursor = rhsCursor->next;
		}

		assert(mSize == rhs.mSize);
		mCurrent = mHead;

		return *this;
	}

	template<typename T>
	CircularLinkedList<T> CircularLinkedList<T>::operator+(const CircularLinkedList<T>& rhs)
	{
		CircularLinkedList<T> sum = CircularLinkedList<T>();

		Node* cursor = mHead;
		for (unsigned int i = 0; i < mSize; i++)
		{
			sum.PushBack(cursor->data);
			cursor = cursor->next;
		}

		assert(sum.mSize == mSize);

		Node* cursor = rhs.mHead;
		for (unsigned int i = 0; i < rhs.mSize; i++)
		{
			sum.PushBack(cursor->data);
			cursor = cursor->next;
		}

		assert(sum.mSize == mSize + rhs.mSize);

		return sum;
	}

	template<typename T>
	void CircularLinkedList<T>::operator+=(const CircularLinkedList<T>& rhs)
	{
		Node* cursor = rhs.mHead;
		for (unsigned int i = 0; i < rhs.mSize; i++)
		{
			PushBack(cursor->data);
			cursor = cursor->next;
		}
	}

	template<typename T>
	inline T& CircularLinkedList<T>::GetHead()
	{
		return mHead->data;
	}

	template<typename T>
	inline T& CircularLinkedList<T>::GetTail()
	{
		return mTail->data;
	}

	template<typename T>
	inline T& CircularLinkedList<T>::GetCurrent()
	{
		return mCurrent->data;
	}

	template<typename T>
	bool CircularLinkedList<T>::Next()
	{
		if (mCurrent == nullptr)
		{
			assert(mHead == nullptr);
			assert(mTail == nullptr);
			return false;
		}

		mCurrent = mCurrent->next;
		return true;
	}

	template<typename T>
	void CircularLinkedList<T>::PushBack(T& data)
	{
		if (mTail == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			assert(mHead == nullptr);
			mTail = new Node(data, mHead);
			mHead = mTail;
			mCurrent = mHead;
		}
		else
		{
			mTail->next = new Node(data, mHead);
			mTail = mTail->next;
		}
		mSize++;
	}

	template<typename T>
	inline void CircularLinkedList<T>::PushBack(T&& data)
	{
		if (mTail == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			assert(mHead == nullptr);
			mTail = new Node(data, mHead);
			mHead = mTail;
			mCurrent = mHead;
		}
		else
		{
			mTail->next = new Node(data, mHead);
			mTail = mTail->next;
		}
		mSize++;
	}

	template<typename T>
	void CircularLinkedList<T>::AddFirst(T& data)
	{
		mHead = new Node(data, mHead);

		if (mTail == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			mTail = mHead;
			mCurrent = mHead;
		}
		else
		{
			mTail->next = mHead;
		}

		mSize++;
	}

	template<typename T>
	inline void CircularLinkedList<T>::AddFirst(T&& data)
	{
		mHead = new Node(data, mHead);

		if (mTail == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			mTail = mHead;
			mCurrent = mHead;
		}
		else
		{
			mTail->next = mHead;
		}

		mSize++;
	}

	template<typename T>
	void CircularLinkedList<T>::RemoveFirst()
	{
		if (mHead == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			assert(mTail == nullptr);
			return;
		}

		if (mHead == mTail)
		{
			assert(mSize == 1);
			assert(mHead->next == nullptr);
			assert(mTail->next == nullptr);
			delete mHead;
			mHead = nullptr;
			mTail = nullptr;
			mCurrent = nullptr;
			mSize--;
			return;
		}

		Node* temp = mHead;
		mHead = mHead->next;
		mTail->next = mHead;
		if (mCurrent == temp)
		{
			mCurrent = mHead;
		}
		delete temp;
		mSize--;
	}

	template<typename T>
	void CircularLinkedList<T>::RemoveLast()
	{
		if (mTail == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			assert(mHead == nullptr);
			return;
		}

		if (mHead == mTail)
		{
			assert(mSize == 1);
			assert(mHead->next == nullptr);
			assert(mTail->next == nullptr);
			delete mHead;
			mHead = nullptr;
			mTail = nullptr;
			mCurrent = nullptr;
			mSize--;
			return;
		}

		Node* cursor = mHead;
		while (!(cursor->next == mTail))
		{
			cursor = cursor->next;
		}

		if (mCurrent == mTail)
		{
			mCurrent = cursor;
		}

		delete mTail;
		cursor->next == mHead;
		mTail = cursor;
		mSize--;
	}

	template<typename T>
	void CircularLinkedList<T>::Clear()
	{
		Node* cursor = mHead;

		for (unsigned int i = 0; i < mSize; i++)
		{
			Node* temp = cursor;
			cursor = cursor->next;
			delete temp;
		}

		mSize = 0;
		mHead = nullptr;
		mTail = nullptr;
		mCurrent = nullptr;
	}

	template<typename T>
	inline CircularLinkedList<T>::Node::Node(T& data, Node* next) : data(data), next(next)
	{
	}

}