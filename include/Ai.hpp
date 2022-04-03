#ifndef __AI_HPP__
# define __AI_HPP__

# include <chrono> 
# include "Puzzle.hpp"
# include "Node.hpp"
# include "Neighbours.hpp"
# include "Solver.hpp"
# include <math.h>

using namespace std::chrono; 

class Ai
{
  public:
    Ai();
    ~Ai();
    std::vector<std::shared_ptr<Node>> lauch();
};

#endif /* __AI_HPP__ */