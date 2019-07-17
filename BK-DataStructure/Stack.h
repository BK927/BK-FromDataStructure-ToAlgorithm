#pragma once

namespace bkDS
{
	template<typename T>
	class Stack : public BaseContainer
	{
	public:
		void Push(const T& value);
		T Pop();
		T& Peek() const;

	private:
		T* m
	};
}