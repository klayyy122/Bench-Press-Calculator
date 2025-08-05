#include <iostream>
#include <vector>
#include<map>
#include<cmath>

class Formulas{
protected:
    double Epli(double weight, int reps);
    double  Brzycki(double weight, int reps);
    double Lander(double weight, int reps);
    decltype(auto) Conner(double weight, int reps);
    
};

class CalculateBenchPress final : public Formulas
{
    double weight;
    int reps;

public:
    explicit CalculateBenchPress(double weight_, int reps_) : weight(weight_), reps(reps_) {}
    ~CalculateBenchPress() = default;
    CalculateBenchPress(const CalculateBenchPress &obj) = delete;
    CalculateBenchPress &operator=(const CalculateBenchPress &obj) = delete;
    void getResult();
    
};

struct Helper
{
   bool is_number(const std::string& s);
   void fix(std::string& weight, std::string& reps, double& weight_, int& reps_);
};
