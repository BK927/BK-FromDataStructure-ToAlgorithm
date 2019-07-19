#include "StackApplication.h"

using namespace algorithm;

void TestCheckMatching()
{
	StackApplication::CheckMatching("StackApplication.cpp");
	StackApplication::CheckMatching("StackApplication.h");
}

void TestExploreMaze()
{
	char map[][6] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'}
	};
	StackApplication::ExploreMaze<6, 6>(map);
}

int main()
{
	//TestCheckMatching();
	TestExploreMaze();
	getchar();
}
