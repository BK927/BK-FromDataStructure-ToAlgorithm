#pragma once

#include <iostream>
#include <fstream>

#include "Stack.h"

using namespace std;

namespace algorithm
{
	class StackApplication
	{
	public:
		static void CheckMatching(const char* filename);

	private:
		enum class eCheckMatchingError;

		static void CheckMatchingErrMsg(const unsigned int nLine, const unsigned int nChar, const eCheckMatchingError err);

		enum class eCheckMatchingError
		{
			Missing_Single_Quotation_Mark,
			Missing_Double_Quotation_Mark,
			Missing_Bracket
		};
	};
}