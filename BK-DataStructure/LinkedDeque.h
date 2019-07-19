#pragma once
#include <cassert>

#include "DoublyLinkedList.h"

namespace bkDS
{
	template <typename T>
	class LinkedDeque : protected DoublyLinkedList<T>
	{
	public:
		LinkedDeque();
		LinkedDeque(const LinkedDeque<T>& rhs);
		~LinkedDeque() = default;

		LinkedDeque<T>& operator=(const LinkedDeque<T>& rhs);

		T& Front();
		T& Back();
		void PushFront(T& data);
		void PushFront(T&& data);
		void PushBack(T& data);
		void PushBack(T&& data);
		void PopFront();
		void PopBack();
		void Clear();
	};

	template<typename T>
	inline LinkedDeque<T>::LinkedDeque() : DoublyLinkedList<T>()
	{
	}

	template<typename T>
	inline LinkedDeque<T>::LinkedDeque(const LinkedDeque<T>& rhs) : DoublyLinkedList<T>(rhs)
	{
	}

	template<typename T>
	inline LinkedDeque<T>& LinkedDeque<T>::operator=(const LinkedDeque<T>& rhs)
	{
		DoublyLinkedList<T>::operator=(rhs);
		return *this
	}

	template<typename T>
	inline T& LinkedDeque<T>::Front()
	{
		return DoublyLinkedList<T>::GetHead();
	}

	template<typename T>
	inline T& LinkedDeque<T>::Back()
	{
		return DoublyLinkedList<T>::GetTail();
	}

	template<typename T>
	inline void LinkedDeque<T>::PushFront(T& data)
	{
		DoublyLinkedList<T>::AddFirst(data);
	}

	template<typename T>
	inline void LinkedDeque<T>::PushFront(T&& data)
	{
		DoublyLinkedList<T>::AddFirst(data);
	}

	template<typename T>
	inline void LinkedDeque<T>::PushBack(T& data)
	{
		DoublyLinkedList<T>::PushBack(data);
	}

	template<typename T>
	inline void LinkedDeque<T>::PushBack(T&& data)
	{
		DoublyLinkedList<T>::PushBack(data);
	}

	template<typename T>
	inline void LinkedDeque<T>::PopFront()
	{
		DoublyLinkedList<T>::RemoveFirst();
	}

	template<typename T>
	inline void LinkedDeque<T>::PopBack()
	{
		DoublyLinkedList<T>::RemoveLast();
	}

	template<typename T>
	inline void LinkedDeque<T>::Clear()
	{
		DoublyLinkedList<T>::Clear();
	}
}