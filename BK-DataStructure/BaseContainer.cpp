#include "BaseContainer.h"

namespace bkDS
{
	BaseContainer::BaseContainer() : mSize(0)
	{
	}

	BaseContainer::BaseContainer(unsigned int capacity) : mSize(capacity)
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