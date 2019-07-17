#pragma once
#include <iostream>

#include "Stack.h"

using namespace std;

namespace bkDS
{
	template<typename T>
	class Displayer
	{
	public:
		static void Display(const Stack<T>& stack) const;
	};
}