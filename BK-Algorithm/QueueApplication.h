#pragma once
#include <algorithm>
#include <iostream>

#include "LinkedQueue.h"
#include "MazeManager.h"

using namespace std;

namespace algorithm
{
	class QueueApplication
	{
	public:
		template<typename unsigned int HEIGHT, unsigned int WIDTH>
		static void ExploreMaze(const char maze[][WIDTH]);
	};

	template<typename unsigned int HEIGHT, unsigned int WIDTH>
	inline void QueueApplication::ExploreMaze(const char maze[][WIDTH])
	{
		char copiedMaze[HEIGHT][WIDTH];
		memcpy_s(copiedMaze, sizeof(char) * HEIGHT * WIDTH, maze, sizeof(char) * HEIGHT * WIDTH);
		bkDS::LinkedQueue<Location2D> queue;

		Location2D entry = MazeManager::FindEntry<HEIGHT, WIDTH>(copiedMaze);

		if (entry == Location2D(-1, -1))
		{
			cout << "오류 : 입구를 찾는데 실패 했습니다." << endl;
			return;
		}

		queue.Enqueue(entry);

		while (!queue.IsEmpty())
		{
			Location2D currentLoc = queue.Peek();
			queue.Dequeue();

			MazeManager::PrintMap<HEIGHT, WIDTH>(copiedMaze, currentLoc);
			cout << '(' << currentLoc.row << ", " << currentLoc.col << ") " << endl << endl;

			if (copiedMaze[currentLoc.row][currentLoc.col] == 'x')
			{
				cout << endl << "출구 발견!" << endl;
				return;
			}

			copiedMaze[currentLoc.row][currentLoc.col] = '.';

			if (MazeManager::IsValidLoc<HEIGHT, WIDTH>(currentLoc.row + 1, currentLoc.col, copiedMaze))
			{
				queue.Enqueue(Location2D(currentLoc.row + 1, currentLoc.col));
			}

			if (MazeManager::IsValidLoc<HEIGHT, WIDTH>(currentLoc.row - 1, currentLoc.col, copiedMaze))
			{
				queue.Enqueue(Location2D(currentLoc.row - 1, currentLoc.col));
			}

			if (MazeManager::IsValidLoc<HEIGHT, WIDTH>(currentLoc.row, currentLoc.col + 1, copiedMaze))
			{
				queue.Enqueue(Location2D(currentLoc.row, currentLoc.col + 1));
			}

			if (MazeManager::IsValidLoc<HEIGHT, WIDTH>(currentLoc.row, currentLoc.col - 1, copiedMaze))
			{
				queue.Enqueue(Location2D(currentLoc.row, currentLoc.col - 1));
			}
		}

		cout << "오류 : 출구를 발견하는데 실패했습니다." << endl;
	}
}