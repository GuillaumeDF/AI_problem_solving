#ifndef __PUZZLE_HPP__
# define __PUZZLE_HPP__

# include <vector>
# include <iostream>
# include <memory>

class Puzzle
{
  private:
    std::vector<int> _grid;
    unsigned int _size;

  public:
    Puzzle(unsigned int size, const std::vector<int> &);
    ~Puzzle();
    friend bool operator==(const Puzzle &, const Puzzle &);
    int findEmptyCell() const;
    void newPuzzle();
    void swapValue(int, int);
    const std::vector<int> &getPuzzle() const;
    void print() const;

  friend bool operator==(const Puzzle &a, const Puzzle &b)
  {
  return (a._grid == b._grid);
  }
};

#endif /* __PUZZLE_HPP__ */