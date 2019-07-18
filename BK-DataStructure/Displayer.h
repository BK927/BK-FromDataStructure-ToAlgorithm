#pragma once
#include <iostream>
#include <iomanip>

#include "SinglyLinkedList.h"
#include "Stack.h"
#include "FixedStack.h"

using namespace std;

namespace bkDS
{
	template<typename T>
	class Displayer
	{
	public:
		void Display(const Stack<T>& stack) const;
	};

	template<typename T>
	void Displayer<T>::Display(const Stack<T>& stack) const
	{

	}

}