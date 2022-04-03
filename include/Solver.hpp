#ifndef __SOLVER_HPP__
# define __SOLVER_HPP__

# include <vector>
# include <iostream>
# include <memory>
# include "Node.hpp"
# include "Neighbours.hpp"
# include "Ai.hpp"

class Solver
{
  private:
    std::vector<std::shared_ptr<Node>> _toVisite;
    std::vector<std::shared_ptr<Node>> _alreadyVisited;
    const Puzzle &_goal;
    bool _solved;
    bool compareNode(const std::shared_ptr<Node> &, const std::shared_ptr<Node> &);
    int getMissPlacedCell(const Puzzle &);
    bool alreadyExist(const Puzzle &, const std::vector<std::shared_ptr<Node>> &);

  public:
    Solver(const Puzzle &start, const Puzzle &);
    ~Solver();
    bool isSolved() const;
    static unsigned int getInversions(const std::vector<int> &);
    static bool isSolvable(const Puzzle &);
    std::vector<std::shared_ptr<Node>>::iterator getBestNode();
    std::shared_ptr<Node> getNode();
    void solve(std::shared_ptr<Node>, const Neighbours &);
    const std::vector<std::shared_ptr<Node>> getNodetoVisite() const;
};

#endif /* __SOLVER_HPP__ */