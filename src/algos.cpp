#include <iostream> //std
#include <vector> //vector
#include <list> //list
#include <algorithm> //lambda
#include <cmath> //pow, hypot
#include <utility> // pair
#include <tuple>
#include <optional>
#include "algos.hpp"

namespace advcpp {   
void sortPointsByDistance(std::vector<std::pair<double, double>>& a_pointsVec) {
    if(a_pointsVec.empty()) {
        throw std::runtime_error("Vector is empty.");
    }
    auto comparePointsByDistance = [](std::pair<double, double> a_point1, std::pair<double, double> a_point2) {
        return hypot(a_point1.first, a_point1.second) < hypot(a_point2.first, a_point2.second);
    };
    std::sort(a_pointsVec.begin(), a_pointsVec.end(), comparePointsByDistance);
}


void sortPointsByRange (std::vector<std::pair<double, double>>& a_pointsVec, double a_innerRadius, double a_outerRadius) {
    if(a_pointsVec.empty()) {
        throw std::runtime_error("Vector is empty.");
    }
    if(a_innerRadius > a_outerRadius) {
        std::swap(a_innerRadius, a_outerRadius);
    }
    auto comparePointsByRange = [a_innerRadius, a_outerRadius](const std::pair<double, double>& a_point1, const std::pair<double, double>& a_point2) {
    double distance1 = hypot(a_point1.first, a_point1.second);
    double distance2 = hypot(a_point2.first, a_point2.second);
    if (distance1 >= a_innerRadius && distance1 < a_outerRadius && distance2 < a_innerRadius) {
        return true;
    }
    if (distance2 >= a_innerRadius && distance2 < a_outerRadius && distance1 < a_innerRadius) {
        return false;
    }
    return distance1 < distance2;
};
    std::sort(a_pointsVec.begin(), a_pointsVec.end(), comparePointsByRange);
}


std::vector<double> thirdPowerOfEvenNumbersFromList(std::list<int> const& a_numbersList) {
    std::vector<double> results;
    results.reserve(a_numbersList.size());
    std::copy_if(a_numbersList.begin(), a_numbersList.end(),
        std::back_inserter(results),
        [](int a_element)  {
            return a_element % 2 == 0;
        });
    std::transform(results.begin(), results.end(), results.begin(), 
        [](double a_num) -> double {
            return std::pow(a_num, 3);
        });
    return results;
}
namespace {
using QuadraticRoots = std::optional<std::pair<double, double>>;
QuadraticRoots findRoots(std::tuple<double, double, double> const& a_quadratics) {
    double a = std::get<0>(a_quadratics);
    double b = std::get<1>(a_quadratics);
    double c = std::get<2>(a_quadratics);
    QuadraticRoots roots;
    double discriminant = std::pow(b,2) - 4 * a * c;
    if (discriminant == 0) {
        double root1 = -b / (2 * a);
        return std::make_pair(root1, root1);
    }
    else if (discriminant > 0) {
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        return std::make_pair(root1, root2);
    }
    return QuadraticRoots{};
}
} //namespace

std::list<QuadraticRoots> solveQuadraticEquations(std::vector<std::tuple <double, double, double>> const& a_vector) {
    std::list<QuadraticRoots> results;
    std::transform(a_vector.begin(), a_vector.end(), std::back_inserter(results),
        [](std::tuple <double, double, double> a_coefs) {
            return findRoots(a_coefs);
        });
    return results;
}


void printVector(std::vector<double> const& a_vec) {
    if(a_vec.empty()) {
        throw std::runtime_error("Vector is empty.");
    }
    for (size_t i = 0 ; i < a_vec.size(); ++i) {
        std::cout << a_vec[i] << "  " ;
    }
    std::cout << std::endl;
}


void printPointsVector(std::vector<std::pair<double, double>> const& a_pointsVec) {
    if(a_pointsVec.empty()) {
        throw std::runtime_error("Vector is empty.");
    }
    for (size_t i = 0 ; i < a_pointsVec.size(); ++i) {
        std::cout << "(" << a_pointsVec[i].first << ", " << a_pointsVec[i].second << ") ";
    }
    std::cout << std::endl;
}

void printList(std::list<double> const& a_list) {
    for (std::list<double>::const_iterator it = a_list.begin(); it != a_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

}//advcpp
