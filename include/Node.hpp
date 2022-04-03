#ifndef __NODE_HPP__
# define __NODE_HPP__

# include <vector>
# include <iostream>
# include <memory>
# include "Puzzle.hpp"

class Node
{
  private:
    Puzzle _grid;
    std::shared_ptr<Node> _parent;
    int _depth;

  public:
    Node(const Puzzle &Puzzle, std::shared_ptr<Node>, int);
    ~Node();
    const std::shared_ptr<Node> getParent() const;
    const Puzzle &getPuzzle() const;
    int getDepth() const;
};

#endif /* __NODE_HPP__ */