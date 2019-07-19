#pragma once
#include <iostream>

#include "Location2D.h"

using namespace std;

namespace algorithm
{
	class MazeDisplayer
	{
	public:
		template<typename unsigned int HEIGHT, unsigned int WIDTH>
		static void PrintMap(const char maze[][WIDTH], const Location2D currentLoc);
	};

	template<typename unsigned int HEIGHT, unsigned int WIDTH>
	inline void MazeDisplayer::PrintMap(const char maze[][WIDTH], const Location2D currentLoc)
	{
		for (unsigned int i = 0; i < HEIGHT; i++)
		{
			for (unsigned int j = 0; j < WIDTH; j++)
			{
				if (i == currentLoc.row && j == currentLoc.col)
				{
					cout << "¡Ú";
				}
				else
				{
					switch (maze[i][j])
					{
					case '1':
						cout << "¡á";
						break;
					case '0':
						cout << "¡à";
						break;
					case '.':
						cout << "¢Æ";
						break;
					case 'x':
						cout << "¡Ý";
						break;
					case 'e':
						cout << "¡Û";
						break;
					default:
						break;
					}
				}
			}
			cout << endl;
		}
	}
	
}