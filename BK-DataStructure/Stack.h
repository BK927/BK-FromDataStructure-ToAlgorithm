#pragma once
#include "Displayer.h"
#include "SinglyLinkedList.h"

namespace bkDS
{
	template<typename T>
	class Stack : protected SinglyLinkedList<T>
	{
	public:
		Stack();
		Stack(const Stack<T>& rhs);
		~Stack() = default;

		Stack<T>& operator=(const Stack<T>& rhs);

		void Push(T& data);
		void Pop();
		T& Peek() const;
		bool IsEmpty() const;
		unsigned int Size() const;
	};

	template<typename T>
	inline Stack<T>::Stack() : SinglyLinkedList()
	{
	}

	template<typename T>
	inline Stack<T>::Stack(const Stack<T>& rhs) : SinglyLinkedList(rhs)
	{
	}

	template<typename T>
	inline Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
	{
		SinglyLinkedList<T>::operator=(rhs);
	}

	template<typename T>
	inline void Stack<T>::Push(T& value)
	{
		AddFirst(value);
	}

	template<typename T>
	inline void Stack<T>::Pop()
	{
		RemoveFirst();
	}

	template<typename T>
	inline T& Stack<T>::Peek() const
	{
		return GetHead();
	}
	template<typename T>
	inline bool Stack<T>::IsEmpty() const
	{
		return IsEmpty();
	}

	template<typename T>
	inline unsigned int Stack<T>::Size() const
	{
		return Size();
	}
}