#include "Solver.hpp"

Solver::Solver(const Puzzle &start, const Puzzle &goal)
        : _goal(goal), _solved(false)
{
    std::shared_ptr<Node> root(new Node(start, 0, 0));
    this->_toVisite.push_back(root);
}

Solver::~Solver()
{}

bool Solver::isSolved() const
{
    return (this->_solved);
}

const std::vector<std::shared_ptr<Node>> Solver::getNodetoVisite() const
{
    return (this->_toVisite);
}

unsigned int Solver::getInversions(const std::vector<int> &puzzle)
{
    unsigned int inversions;
    unsigned int i;
    unsigned int j;

    inversions = 0;
    i = 0;
    while (i != puzzle.size())
    {
        j = i;
        while (j != puzzle.size())
        {
            if (puzzle[j] && puzzle[i] && puzzle[i] > puzzle[j])
                inversions++;
            j++;
        }
        i++;
    }
    return (inversions);
}

bool Solver::isSolvable(const Puzzle &puzzle)
{
    unsigned int inversions;

    inversions = getInversions(puzzle.getPuzzle());
    return ((inversions % 2) == 0);
}

bool Solver::alreadyExist(const Puzzle &puzzle, const std::vector<std::shared_ptr<Node>> &values)
{
    unsigned int i = 0;
    for (; i < values.size(); ++i)
    {
        if (puzzle == values[i]->getPuzzle())
            return true;
    }
    return false;
}

int Solver::getMissPlacedCell(const Puzzle &puzzle)
{
    int missPlaced;
    int i;
    const std::vector<int> &tmpPuzzle = puzzle.getPuzzle();

    missPlaced = 0;
    i = 0;
    while (i != tmpPuzzle.size())
    {
        if (tmpPuzzle[i] != i + 1)
            missPlaced += 1;
        i++;
    }
    return missPlaced;
}

bool Solver::compareNode(const std::shared_ptr<Node> &node1, const std::shared_ptr<Node> &node2)
{
    return (getMissPlacedCell(node1->getPuzzle())) < (getMissPlacedCell(node2->getPuzzle()));
}


std::vector<std::shared_ptr<Node>>::iterator Solver::getBestNode()
{
    std::vector<std::shared_ptr<Node>>::iterator first;
    std::vector<std::shared_ptr<Node>>::iterator last;
    std::vector<std::shared_ptr<Node>>::iterator bestNode;

    first = this->_toVisite.begin();
    last = this->_toVisite.end();
    if (first == last)
        return last;
    bestNode = first;
    first++;
    while (first != last)
    {
        if (compareNode(*first, *bestNode))
            bestNode = first;
        first++;
    }
    return bestNode;
}

std::shared_ptr<Node> Solver::getNode()
{
    std::shared_ptr<Node> tmpNode;
    std::vector<std::shared_ptr<Node>>::iterator bestNode = getBestNode();

    if (this->_toVisite.empty())
        return 0;
    bestNode = getBestNode();
    if (bestNode == this->_toVisite.end())
        return 0;
    tmpNode = *bestNode;
    this->_toVisite.erase(bestNode);
    this->_alreadyVisited.push_back(tmpNode);
    return tmpNode;
}

void Solver::solve(std::shared_ptr<Node> current, const Neighbours &graph)
{
    if (current->getPuzzle() == _goal)
    {
        _solved = true;
        return;
    }
    int zero = current->getPuzzle().findEmptyCell();
    const std::vector<int> &neighbours = graph.getNeighbours(zero);

    for (int next : neighbours)
    {
        Puzzle puzzle = current->getPuzzle();
        puzzle.swapValue(zero, next);

        if (!alreadyExist(puzzle, this->_alreadyVisited))
        {
            std::shared_ptr<Node> newNode(new Node(puzzle, current, current->getDepth() + 1));
            this->_toVisite.push_back(newNode);
        }
    }
}