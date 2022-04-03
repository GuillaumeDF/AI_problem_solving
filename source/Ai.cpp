#include "Ai.hpp"

Ai::Ai()
{
}

Ai::~Ai()
{
}

std::vector<std::shared_ptr<Node>> Ai::lauch()
{
    Puzzle start(3, std::vector<int>{5, 6, 2, 8, 0, 1, 4, 3, 7});
    Puzzle goal(3, std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 0});
    Neighbours g;
    int depth;

    depth = 0;
    while (!Solver::isSolvable(start))
        start.newPuzzle();
    std::cout << "Start with this puzzle solvable :\n";
    start.print();
    std::cout << "--------------\n";
    auto startTimer = high_resolution_clock::now(); 
    std::shared_ptr<Node> node;
    Solver solver(start, goal);
    int count = 0;
    while (!solver.isSolved())
    {
        node = solver.getNode();
        solver.solve(node, g);
        count++;
    }
    auto stopTimer = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stopTimer - startTimer); 
    std::vector<std::shared_ptr<Node>> solution;
    std::shared_ptr<Node> s = node;
    while (s != NULL)
    {
        solution.push_back(s);
        s = s->getParent();
        depth++;
    }
    std::cout << "Solution found in " << duration.count() * pow(10, -6) << " seconds\n"; 
    std::cout << solver.getNodetoVisite().size() << " nodes visited for this solution.\n";
    std::cout << "The greatest depth is " << depth << ".\n\n";
    return (solution);
}