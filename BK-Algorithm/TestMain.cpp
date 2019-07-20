#include "DequeApplication.h"
#include "StackApplication.h"
#include "QueueApplication.h"

using namespace std;
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

	cout << "-----------StackApplication::ExploreMaze-----------" << endl;
	StackApplication::ExploreMaze<6, 6>(map);


	cout << endl << "-----------QueueApplication::ExploreMaze-----------" << endl;
	QueueApplication::ExploreMaze<6, 6>(map);

	cout << endl << "-----------DequeApplication::DFS_ExploreMaze-----------" << endl;
	DequeApplication::DFS_ExploreMaze<6, 6>(map);

	cout << endl << "-----------QueueApplication::BFS_ExploreMaze-----------" << endl;
	DequeApplication::BFS_ExploreMaze<6, 6>(map);
}

int main()
{
	//TestCheckMatching();
	TestExploreMaze();
	getchar();
}
