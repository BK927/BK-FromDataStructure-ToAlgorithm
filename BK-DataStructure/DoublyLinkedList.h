#pragma once
#include <cassert>

#include "BaseContainer.h"

namespace bkDS
{
	template<typename T>
	class DoublyLinkedList : public BaseContainer
	{
	public:
		DoublyLinkedList();
		DoublyLinkedList(T& data);
		DoublyLinkedList(const DoublyLinkedList<T>& rhs);
		~DoublyLinkedList();

		DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhs);
		DoublyLinkedList<T> operator+(const DoublyLinkedList<T>& rhs);
		void operator+=(const DoublyLinkedList<T>& rhs);

		T& GetHead();
		T& GetTail();
		T& GetCurrent();
		bool Next();
		bool Previous();
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
			Node(T& data, Node* prev, Node* next = nullptr);
			T data;
			Node* prev;
			Node* next;
		};

		Node* mCurrent;
		Node* mHead;
		Node* mTail;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList() : mHead(nullptr), mTail(nullptr), mCurrent(nullptr)
	{
	}

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList(T& data)
	{
		mHead = new Node(data, nullptr);
		mTail = mHead;
		mCurrent = mHead;
	}

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& rhs) : mHead(nullptr), mTail(nullptr)
	{
		Node* cursor = rhs.mHead;
		while (!(cursor == nullptr))
		{
			PushBack(cursor->data);
			cursor = cursor->next;
		}
		mCurrent = mHead;

		assert(mSize == rhs.mSize);
	}

	template<typename T>
	DoublyLinkedList<T>::~DoublyLinkedList()
	{
		Clear();
	}

	template<typename T>
	DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& rhs)
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
		assert(thisCursor == nullptr);

		while (!(rhsCursor == nullptr))
		{
			PushBack(rhsCursor->data);
			rhsCursor = rhsCursor->next;
		}

		assert(mSize == rhs.mSize);
		mCurrent = mHead;

		return *this;
	}

	template<typename T>
	DoublyLinkedList<T> DoublyLinkedList<T>::operator+(const DoublyLinkedList<T>& rhs)
	{
		DoublyLinkedList<T> sum = DoublyLinkedList<T>();

		Node* cursor = mHead;
		while (!(cursor == nullptr))
		{
			sum.PushBack(cursor->data);
			cursor = cursor->next;
		}

		assert(sum.mSize == mSize);

		Node* cursor = rhs.mHead;
		while (!(cursor == nullptr))
		{
			sum.PushBack(cursor->data);
			cursor = cursor->next;
		}

		assert(sum.mSize == mSize + rhs.mSize);

		return sum;
	}

	template<typename T>
	void DoublyLinkedList<T>::operator+=(const DoublyLinkedList<T>& rhs)
	{
		Node* cursor = rhs.mHead;
		while (!(cursor == nullptr))
		{
			PushBack(cursor->data);
			cursor = cursor->next;
		}
	}

	template<typename T>
	inline T& DoublyLinkedList<T>::GetHead()
	{
		return mHead->data;
	}

	template<typename T>
	inline T& DoublyLinkedList<T>::GetTail()
	{
		return mTail->data;
	}

	template<typename T>
	inline T& DoublyLinkedList<T>::GetCurrent()
	{
		return mCurrent->data;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Next()
	{
		if (mCurrent == nullptr || mCurrent->next == nullptr)
		{
			return false;
		}

		mCurrent = mCurrent->next;
		return true;
	}

	template<typename T>
	inline bool DoublyLinkedList<T>::Previous()
	{
		if (mCurrent == nullptr || mCurrent->prev == nullptr)
		{
			return false;
		}

		mCurrent = mCurrent->prev;
		return true;
	}

	template<typename T>
	void DoublyLinkedList<T>::PushBack(T& data)
	{
		if (mTail == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			assert(mHead == nullptr);
			mTail = new Node(data, nullptr);
			mHead = mTail;
			mCurrent = mHead;
		}
		else
		{
			mTail->next = new Node(data, mTail);
			mTail = mTail->next;
		}
		mSize++;
	}

	template<typename T>
	inline void DoublyLinkedList<T>::PushBack(T&& data)
	{
		if (mTail == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			assert(mHead == nullptr);
			mTail = new Node(data, nullptr);
			mHead = mTail;
			mCurrent = mHead;
		}
		else
		{
			mTail->next = new Node(data, mTail);
			mTail = mTail->next;
		}
		mSize++;
	}

	template<typename T>
	void DoublyLinkedList<T>::AddFirst(T& data)
	{
		mHead = new Node(data, nullptr, mHead);

		if (mTail == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			mTail = mHead;
			mCurrent = mHead;
		}

		mSize++;
	}

	template<typename T>
	inline void DoublyLinkedList<T>::AddFirst(T&& data)
	{
		mHead = new Node(data, nullptr, mHead);

		if (mTail == nullptr)
		{
			assert(BaseContainer::IsEmpty());
			mTail = mHead;
			mCurrent = mHead;
		}

		mSize++;
	}

	template<typename T>
	void DoublyLinkedList<T>::RemoveFirst()
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
		mHead->prev = nullptr;
		if (mCurrent == temp)
		{
			mCurrent = mHead;
		}
		delete temp;
		mSize--;
	}

	template<typename T>
	void DoublyLinkedList<T>::RemoveLast()
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

		Node* temp = mTail;
		mTail = mTail->prev;
		mTail->next = nullptr;
		delete temp;
		mSize--;
	}

	template<typename T>
	void DoublyLinkedList<T>::Clear()
	{
		Node* cursor = mHead;
		while (!(cursor == nullptr))
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
	inline DoublyLinkedList<T>::Node::Node(T& data, Node* prev, Node* next) : data(data), next(next), prev(prev)
	{
	}

}