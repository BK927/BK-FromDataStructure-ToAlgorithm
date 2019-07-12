#include "BaseContainer.h"

namespace bkDS
{
	BaseContainer::BaseContainer() : mSize(0)
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