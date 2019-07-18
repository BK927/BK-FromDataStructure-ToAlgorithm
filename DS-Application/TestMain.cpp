#include "StackApplication.h"

using namespace algorithm;

void TestCheckMatching()
{
	StackApplication::CheckMatching("StackApplication.cpp");
	StackApplication::CheckMatching("StackApplication.h");
	getchar();
}

int main()
{
	TestCheckMatching();
}
