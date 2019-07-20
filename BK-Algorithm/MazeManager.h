#pragma once
#include <iostream>

#include "Location2D.h"

using namespace std;

namespace algorithm
{
	class MazeManager
	{
	public:
		template<typename unsigned int HEIGHT, unsigned int WIDTH>
		static void PrintMap(const char maze[][WIDTH], const Location2D currentLoc);

		template<typename unsigned int HEIGHT, unsigned int WIDTH>
		static bool IsValidLoc(const int row, const int col, const char maze[][WIDTH]);

		template<typename unsigned int HEIGHT, unsigned int WIDTH>
		static Location2D FindEntry(const char maze[][WIDTH]);
	};

	template<typename unsigned int HEIGHT, unsigned int WIDTH>
	inline void MazeManager::PrintMap(const char maze[][WIDTH], const Location2D currentLoc)
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
						cout << "?";
						break;
					}
				}
			}
			cout << endl;
		}
	}
	
	template<typename unsigned int HEIGHT, unsigned int WIDTH>
	inline bool MazeManager::IsValidLoc(const int row, const int col, const char maze[][WIDTH])
	{
		if (row < 0 || col < 0 || row >= HEIGHT || col >= WIDTH)
		{
			return false;
		}
		else
		{
			return maze[row][col] == '0' || maze[row][col] == 'x';
		}
	}

	template<typename unsigned int HEIGHT, unsigned int WIDTH>
	inline Location2D MazeManager::FindEntry(const char maze[][WIDTH])
	{
		for (unsigned int i = 0; i < HEIGHT; i++)
		{
			for (unsigned int j = 0; j < WIDTH; j++)
			{
				if (maze[i][j] == 'e')
				{
					return Location2D(i, j);
				}
			}
		}
		return Location2D(-1, -1);
	}
	
}