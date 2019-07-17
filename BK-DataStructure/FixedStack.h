#pragma once

namespace bkDS
{
	template<typename T, size_t size>
	class FixedStack : public BaseContainer
	{
	public:
		void Push(const T& value);
		T Pop();
		T& Peek() const;
		bool IsFull() const;
		size_t MaxSize() const;

	private:
		T m[size]
	};
}