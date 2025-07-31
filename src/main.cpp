#include <iostream>
#include <vector>
#include<map>
#include<cmath>
class Formulas
{
protected:
    double Epli(double weight, int reps)
    {
        return static_cast<double>(weight * reps / 30 + weight);
    }
    double  Brzycki(double weight, int reps){
        return static_cast<double>(weight * (36.0 / (37 - reps)));
    }
    double Lander(double weight, int reps){
     return   (100 * weight) / ((double)101.3 - (double)2.67123 * reps);
    }
    decltype(auto) Conner(double weight, int reps){
        return weight * (1.0 + 0.025 * reps);
    }
    
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

    void getResult(){
        std::map<std::string, double> result = {
            {"Epli's formula:", Epli(weight, reps)},
            {"Brzycki's formula:", Brzycki(weight, reps)},
            {"Lander's formula:", Lander(weight, reps)},
            {"O_Conner's formula:", Conner(weight, reps)},
        };
        std::cout << "Your max result is:" << "\n";
        double avg_res = 0.0;
        for(const auto& [formula, value] : result){
            std::cout << formula << ' ' << value << "\n";
            avg_res += value;
        }
        std::cout << "Your maximum is: " << (uint)(avg_res / 4);
    
    }
    
};


int main(){
    char question = 'y';
    double weight;
    int reps;
    
    while(question == 'y'){
        std::cout << "Enter bench's weigth and count of reps" << std::endl;
        std::cin >> weight >> reps;
        CalculateBenchPress cacl(weight, reps);
        cacl.getResult();
        std::cout << "\nAre you want to check another results?[y/n] ";
        std::cin >> question;
        std::cout << "\n";
    }
    std::cout << "Goodbye, bro!";
}