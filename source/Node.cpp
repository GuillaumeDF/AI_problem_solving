#include "Node.hpp"

Node::Node(const Puzzle &Puzzle, std::shared_ptr<Node> parent, int depth = 0)
        : _grid(Puzzle), _depth(depth), _parent(parent)
{}

Node::~Node()
{}

const std::shared_ptr<Node> Node::getParent() const
{
    return (this->_parent);
}

const Puzzle &Node::getPuzzle() const
{
    return (this->_grid);
}

int Node::getDepth() const
{
    return (this->_depth);
}