#pragma once

namespace bkDS
{
	template<typename T>
	class Stack
	{
	public:
		void Push(const T& value);
		T Pop();
		T& Peek() const;
		bool IsFull() const;
	};
}