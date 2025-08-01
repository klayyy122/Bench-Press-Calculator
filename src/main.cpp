#include"realization.hpp"

int main(){
    char question = 'y';
    double weight;
    int reps;
    
    while(question == 'y' ){
        std::cout << "Enter bench's weigth and count of reps" << std::endl;
        std::cin >> weight >> reps;
        if(reps < 1){
            std::cout << "Enter correct count of reps: ";
           std::cin >> reps;
           std::cout << std::endl;
        }
        CalculateBenchPress cacl(weight, reps);
        cacl.getResult();
        std::cout << "\nAre you want to check another results?[y/n] ";
        std::cin >> question;
        std::cout << "\n";
    }
    std::cout << "Goodbye, bro!";
}