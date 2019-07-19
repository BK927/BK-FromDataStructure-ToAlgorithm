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

		template<typename unsigned int HEIGHT, unsigned int WIDTH>
		static void ExploreMaze(char maze[][WIDTH]);

	private:
		enum class eCheckMatchingError
		{
			Missing_Single_Quotation_Mark,
			Missing_Double_Quotation_Mark,
			Missing_Bracket
		};

		class Location2D
		{
		public:
			Location2D(int row = 0, int col = 0);
			bool operator==(const Location2D& p) const;
			bool IsNeighbor(const Location2D& p) const;

			int row;
			int col;
		};

		static void checkMatchingErrMsg(const unsigned int nLine, const unsigned int nChar, const eCheckMatchingError err);

		template<typename unsigned int HEIGHT, unsigned int WIDTH>
		static bool isValidLoc(const int row, const int col, const char maze[][WIDTH]);

		template<typename unsigned int HEIGHT, unsigned int WIDTH>
		static void printMap(const char maze[][WIDTH], const Location2D currentLoc);
	};

	template<typename unsigned int HEIGHT, unsigned int WIDTH>
	inline static void StackApplication::ExploreMaze(char maze[][WIDTH])
	{
		bkDS::Stack<Location2D> stack;

		for (unsigned int i = 0; i < HEIGHT; i++)
		{
			for (unsigned int j = 0; j < WIDTH; j++)
			{
				if (maze[i][j] == 'e')
				{
					Location2D entry(i, j);
					stack.Push(entry);
					goto OUT_OF_LOOP;
				}
			}
		}
	OUT_OF_LOOP:

		if (stack.IsEmpty())
		{
			cout << "오류 : 입구를 찾는데 실패 했습니다." << endl;
			return;
		}

		while (!stack.IsEmpty())
		{
			Location2D currentLoc = stack.Peek();
			stack.Pop();

			cout << '(' << currentLoc.row << ", " << currentLoc.col << ") ";

			if (maze[currentLoc.row][currentLoc.col] == 'x')
			{
				cout << endl << "출구 발견!" << endl;
				return;
			}

			maze[currentLoc.row][currentLoc.col] = '.';

			if (isValidLoc<HEIGHT ,WIDTH>(currentLoc.row + 1, currentLoc.col, maze))
			{
				Location2D temp(currentLoc.row + 1, currentLoc.col);
				stack.Push(temp);
			}

			if (isValidLoc<HEIGHT, WIDTH>(currentLoc.row - 1, currentLoc.col, maze))
			{
				Location2D temp(currentLoc.row - 1, currentLoc.col);
				stack.Push(temp);
			}

			if (isValidLoc<HEIGHT, WIDTH>(currentLoc.row, currentLoc.col + 1, maze))
			{
				Location2D temp(currentLoc.row, currentLoc.col + 1);
				stack.Push(temp);
			}

			if (isValidLoc<HEIGHT, WIDTH>(currentLoc.row, currentLoc.col - 1, maze))
			{
				Location2D temp(currentLoc.row, currentLoc.col - 1);
				stack.Push(temp);
			}
		}

		cout << "오류 : 출구를 발견하는데 실패했습니다." << endl;
	}

	template<typename unsigned int HEIGHT, unsigned int WIDTH>
	inline bool StackApplication::isValidLoc(const int row, const int col, const char maze[][WIDTH])
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
	inline void StackApplication::printMap(const char maze[][WIDTH], const StackApplication::Location2D currentLoc)
	{
		for (unsigned int i = 0; i < HEIGHT; i++)
		{
			for (unsigned int j = 0; j < WIDTH; j++)
			{
				if (i == currentLoc.row && j == currentLoc.col)
				{
					cout << 'C' << ' ';
				}
				else
				{
					cout << maze[i][j] << ' ';
				}
			}
			cout << endl;
		}
	}
}

