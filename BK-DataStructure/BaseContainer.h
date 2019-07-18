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

	inline BaseContainer::BaseContainer() : mSize(0)
	{
	}

	inline bool BaseContainer::IsEmpty() const
	{
		return mSize == 0 ? true : false;
	}

	inline unsigned int BaseContainer::Size() const
	{
		return mSize;
	}
}