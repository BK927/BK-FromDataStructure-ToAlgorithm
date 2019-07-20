#pragma once
#include <cassert>

#include "BaseContainer.h"
#include "SinglyLinkedList.h"

namespace bkDS
{
	template<typename T>
	class LinkedQueue : protected SinglyLinkedList<T>
	{
	public:
		LinkedQueue();
		LinkedQueue(const LinkedQueue<T>& rhs);
		~LinkedQueue() = default;

		LinkedQueue<T>& operator=(const LinkedQueue<T>& rhs);
		LinkedQueue<T> operator+(const LinkedQueue<T>& rhs);
		void operator+=(const LinkedQueue<T>& rhs);

		void Enqueue(T& data);
		void Enqueue(T&& data);
		bool Dequeue();
		T& Peek();
		bool IsEmpty() const;
		unsigned int Size() const;
	};

	template<typename T>
	inline LinkedQueue<T>::LinkedQueue() : SinglyLinkedList<T>()
	{
	}

	template<typename T>
	inline LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& rhs) : SinglyLinkedList<T>(rhs)
	{
	}

	template<typename T>
	inline LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rhs)
	{
		return SinglyLinkedList<T>::operator=(rhs);
	}

	template<typename T>
	inline LinkedQueue<T> LinkedQueue<T>::operator+(const LinkedQueue<T>& rhs)
	{
		return SinglyLinkedList<T>::operator+(rhs);
	}

	template<typename T>
	inline void LinkedQueue<T>::operator+=(const LinkedQueue<T>& rhs)
	{
		SinglyLinkedList<T>::operator+=(rhs);
	}

	template<typename T>
	inline void LinkedQueue<T>::Enqueue(T& data)
	{
		SinglyLinkedList<T>::PushBack(data);
	}

	template<typename T>
	inline void LinkedQueue<T>::Enqueue(T&& data)
	{
		SinglyLinkedList<T>::PushBack(data);
	}

	template<typename T>
	inline bool LinkedQueue<T>::Dequeue()
	{
		if (BaseContainer::IsEmpty())
		{
			return false;
		}

		SinglyLinkedList<T>::RemoveFirst();

		return true;
	}

	template<typename T>
	inline T& LinkedQueue<T>::Peek()
	{
		return SinglyLinkedList<T>::GetHead();
	}
	template<typename T>
	inline bool LinkedQueue<T>::IsEmpty() const
	{
		return BaseContainer::IsEmpty();
	}
	template<typename T>
	inline unsigned int LinkedQueue<T>::Size() const
	{
		return BaseContainer::Size();
	}
}