#pragma once

namespace algorithm
{
	struct Location2D
	{
		Location2D(int row = 0, int col = 0);
		bool operator==(const Location2D& p) const;
		bool IsNeighbor(const Location2D& p) const;

		int row;
		int col;
	};
}