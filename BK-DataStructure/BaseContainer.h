#pragma once

namespace bkDS
{
	class BaseContainer
	{
	public:
		BaseContainer();
		BaseContainer(unsigned int size);
		bool IsEmpty() const;
		unsigned int Size() const;

	protected:
		unsigned int mSize;
	};
}