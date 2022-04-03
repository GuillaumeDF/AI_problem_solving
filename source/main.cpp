#include "Ai.hpp"

int main(int argc, char *argv[])
{
    Ai ai;
    std::vector<std::shared_ptr<Node>> solution;
    std::vector<std::shared_ptr<Node>>::iterator itrSolution;
    int stape;
    
    stape = 1;
    solution = ai.lauch();
    itrSolution = solution.end() - 1;
    while (itrSolution != solution.begin())
    {
        std::cout << "Stape " << stape << '\n';
        (*itrSolution)->getPuzzle().print();
        itrSolution--;
        stape++;
    }
    std::cout << "Stape " << stape << '\n';
    (*itrSolution)->getPuzzle().print();
    std::cout << '\n';
    return (0);
}
