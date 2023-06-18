#ifndef ALGOS_HPP_206
#define ALGOS_HPP_206
#include <optional>
namespace advcpp {
template<typename T>
struct Triple {
    T m_a;
    T m_b;
    T m_c;
};

void sortPointsByDistance(std::vector<std::pair<double, double>>& a_pointsVec);
void sortPointsByRange (std::vector<std::pair<double, double>>& a_pointsVec, double a_innerRadius, double a_outerRadius);
std::vector<double> thirdPowerOfEvenNumbersFromList(std::list<int> const& a_numbersList);

using QuadraticRoots = std::optional<std::pair<double, double>>;
std::list<QuadraticRoots> solveQuadraticEquations(std::vector<std::tuple <double, double, double>> const& a_vector);


void printVector(std::vector<double> const& a_vec);
void printPointsVector(std::vector<std::pair<double, double>> const& a_pointsVec);
void printList(std::list<double> const& a_list);



}//advcpp
#endif //ALGOS_HPP_206