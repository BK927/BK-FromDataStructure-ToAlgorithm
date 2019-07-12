#pragma once

namespace bkDS
{
	class BaseContainer
	{
	public:
		BaseContainer();
		bool IsEmpty() const;
		unsigned int Size() const;

	protected:
		unsigned int mSize;
	};
}