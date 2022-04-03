#include "Neighbours.hpp"

Neighbours::Neighbours()
{
    _neightbours.insert(std::make_pair(0, std::vector<int>{1, 3}));
    _neightbours.insert(std::make_pair(1, std::vector<int>{0, 2, 4}));
    _neightbours.insert(std::make_pair(2, std::vector<int>{1, 5}));
    _neightbours.insert(std::make_pair(3, std::vector<int>{4, 0, 6}));
    _neightbours.insert(std::make_pair(4, std::vector<int>{3, 5, 1, 7}));
    _neightbours.insert(std::make_pair(5, std::vector<int>{4, 2, 8}));
    _neightbours.insert(std::make_pair(6, std::vector<int>{7, 3}));
    _neightbours.insert(std::make_pair(7, std::vector<int>{6, 8, 4}));
    _neightbours.insert(std::make_pair(8, std::vector<int>{7, 5}));
}

Neighbours::~Neighbours()
{
}

const std::vector<int> &Neighbours::getNeighbours(int id) const
{
    std::map<int, std::vector<int>>::const_iterator neighbour(_neightbours.find(id));

    return neighbour->second;
}