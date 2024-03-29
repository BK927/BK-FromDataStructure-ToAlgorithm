#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>

#include "Stack.h"
#include "Location2D.h"
#include "MazeManager.h"

using namespace std;

namespace algorithm
{
	class StackApplication
	{
	public:
		static void CheckMatching(const char* filename);

		template<typename unsigned int HEIGHT, unsigned int WIDTH>
		static void ExploreMaze(const char maze[][WIDTH]);

	private:
		enum class eCheckMatchingError
		{
			Missing_Single_Quotation_Mark,
			Missing_Double_Quotation_Mark,
			Missing_Bracket
		};

		static void checkMatchingErrMsg(const unsigned int nLine, const unsigned int nChar, const eCheckMatchingError err);
	};

	template<typename unsigned int HEIGHT, unsigned int WIDTH>
	inline static void StackApplication::ExploreMaze(const char maze[][WIDTH])
	{
		char copiedMaze[HEIGHT][WIDTH];
		memcpy_s(copiedMaze, sizeof(char) * HEIGHT * WIDTH, maze, sizeof(char) * HEIGHT * WIDTH);

		bkDS::Stack<Location2D> stack;
		Location2D entry = MazeManager::FindEntry<HEIGHT, WIDTH>(copiedMaze);

		if (entry == Location2D(-1, -1))
		{
			cout << "오류 : 입구를 찾는데 실패 했습니다." << endl;
			return;
		}

		stack.Push(entry);

		while (!stack.IsEmpty())
		{
			Location2D currentLoc = stack.Peek();
			stack.Pop();

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
				stack.Push(Location2D(currentLoc.row + 1, currentLoc.col));
			}

			if (MazeManager::IsValidLoc<HEIGHT, WIDTH>(currentLoc.row - 1, currentLoc.col, copiedMaze))
			{
				stack.Push(Location2D(currentLoc.row - 1, currentLoc.col));
			}

			if (MazeManager::IsValidLoc<HEIGHT, WIDTH>(currentLoc.row, currentLoc.col + 1, copiedMaze))
			{
				stack.Push(Location2D(currentLoc.row, currentLoc.col + 1));
			}

			if (MazeManager::IsValidLoc<HEIGHT, WIDTH>(currentLoc.row, currentLoc.col - 1, copiedMaze))
			{
				stack.Push(Location2D(currentLoc.row, currentLoc.col - 1));
			}
		}

		cout << "오류 : 출구를 발견하는데 실패했습니다." << endl;
	}
}

