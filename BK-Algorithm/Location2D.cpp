#include "Location2D.h"

namespace algorithm
{
	Location2D::Location2D(int row, int col) : row(row), col(col)
	{
	}

	bool Location2D::operator==(const Location2D& p) const
	{
		return row == p.row && col == p.col;
	}

	bool Location2D::IsNeighbor(const Location2D& p) const
	{
		return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) || (col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
}