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
    return (weight * static_cast<double>(reps) * 0.0333) + weight;
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


 bool Helper::is_number(const std::string& s){
    auto it = s.begin();
    for(; it != s.end() && isdigit(*it); ++it);
    return !s.empty() && it ==s.end();
 }
    void Helper::fix(std::string& weight, std::string& reps, double& weight_, int& reps_){
        Helper h;
        while (!h.is_number(weight)) {
                std::cout << "Enter correct weight (number): ";
                std::cin >> weight;
            }
        while (!h.is_number(reps)) {
                std::cout << "Enter correct reps (number): ";
                std::cin >> reps;
            }
            
            
        weight_ = std::stof(weight);
        reps_ = std::stod(reps);
    }
 