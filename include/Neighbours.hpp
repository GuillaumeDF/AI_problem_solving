#ifndef __NEIGHBOURS_HPP__
# define __NEIGHBOURS_HPP__

# include <vector>
# include <iostream>
# include <memory>
# include <vector>
# include <map>

class Neighbours
{
  public:
    std::map<int, std::vector<int>> _neightbours;
    Neighbours();
    ~Neighbours();
    const std::vector<int> &getNeighbours(int) const;
};

#endif /* __NEIGHBOURS_HPP__ */