#include "Puzzle.hpp"

Puzzle::Puzzle(unsigned int size, const std::vector<int> &grid)
        : _size(size), _grid(grid)
{}

Puzzle::~Puzzle()
{}

int Puzzle::findEmptyCell() const
{
    unsigned int i;

    i = 0;
    while (i != this->_grid.size())
    {
        if (this->_grid[i] == 0)
            return (i);
        i++;
    }
    return (-1);
}

void Puzzle::newPuzzle()
{
    std::random_shuffle(_grid.begin(), _grid.end());
}

void Puzzle::swapValue(int firstValue, int secondValue)
{
    int tmp;

    tmp = this->_grid[secondValue];
    this->_grid[secondValue] = this->_grid[firstValue];
    this->_grid[firstValue] = tmp;
}

const std::vector<int> &Puzzle::getPuzzle() const
{
    return (this->_grid);
}

void Puzzle::print() const
{
    int y;
    int x;

    y = 0;
    while (y != 3)
    {
        x = 0;
        while (x != 3)
        {
            std::cout << _grid[(y * this->_size) + x] << " ";
            x++;
        }
        std::cout << "\n";
        y++;
    }
    std::cout << "\n";
}