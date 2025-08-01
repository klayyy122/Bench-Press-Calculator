#include "realization.hpp"
double Formulas::Epli(double weight, int reps)
{
    return static_cast<double>(weight * reps / 30 + weight);
}
double Formulas::Brzycki(double weight, int reps)
{

    return static_cast<double>(weight * (36.0 / (37 - reps)));
}
double Formulas::Lander(double weight, int reps)
{
    return (100 * weight) / ((double)101.3 - (double)2.67123 * reps);
}
decltype(auto) Formulas::Conner(double weight, int reps)
{
    return weight * (1.0 + 0.025 * reps);
}

void CalculateBenchPress::getResult()
{
    std::map<std::string, double> result = {
        {"Epli's formula:", Epli(weight, reps)},
        {"Brzycki's formula:", Brzycki(weight, reps)},
        {"Lander's formula:", Lander(weight, reps)},
        {"O_Conner's formula:", Conner(weight, reps)},
    };
    std::cout << "Your max result is:" << "\n";
    double avg_res = 0.0;
    for (const auto &[formula, value] : result)
    {
        std::cout << formula << ' ' << value << "\n";
        avg_res += value;
    }
    std::cout << "Your maximum is: " << (uint)(avg_res / 4);
}
