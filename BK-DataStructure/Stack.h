#pragma once
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
		void Push(T&& data);
		void Pop();
		T& Peek();
		bool IsEmpty() const;
		unsigned int Size() const;
	};

	template<typename T>
	inline Stack<T>::Stack() : SinglyLinkedList<T>()
	{
	}

	template<typename T>
	inline Stack<T>::Stack(const Stack<T>& rhs) : SinglyLinkedList<T>(rhs)
	{
	}

	template<typename T>
	inline Stack<T>& Stack<T>::operator=(const Stack<T>& rhs)
	{
		SinglyLinkedList<T>::operator=(rhs);
		return *this;
	}

	template<typename T>
	inline void Stack<T>::Push(T& data)
	{
		SinglyLinkedList<T>::AddFirst(data);
	}

	template<typename T>
	inline void Stack<T>::Push(T&& data)
	{
		SinglyLinkedList<T>::AddFirst(data);
	}

	template<typename T>
	inline void Stack<T>::Pop()
	{
		SinglyLinkedList<T>::RemoveFirst();
	}

	template<typename T>
	inline T& Stack<T>::Peek()
	{
		return SinglyLinkedList<T>::GetHead();
	}

	template<typename T>
	inline bool Stack<T>::IsEmpty() const
	{
		return BaseContainer::IsEmpty();
	}

	template<typename T>
	inline unsigned int Stack<T>::Size() const
	{
		return BaseContainer::Size();
	}
}