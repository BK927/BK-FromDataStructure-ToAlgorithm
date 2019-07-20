#pragma once

namespace bkDS
{
	class BaseContainer
	{
	public:
		BaseContainer();

		void operator=(const BaseContainer& rhs);

		bool IsEmpty() const;
		unsigned int Size() const;

	protected:
		unsigned int mSize;
	};

	inline BaseContainer::BaseContainer() : mSize(0)
	{
	}

	inline void BaseContainer::operator=(const BaseContainer& rhs)
	{
		mSize = rhs.mSize;
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