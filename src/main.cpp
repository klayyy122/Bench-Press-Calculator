#include"realization.hpp"

int main(){
    try{
    char question = 'y';
    double weight;
    int reps;
    int tries = 0;
    while(question == 'y' ){
        
        
        
        std::cout << "Enter bench's weigth and count of reps(1-13)" << std::endl;
        std::cin >> weight >> reps;
        while (weight <= 0 || reps < 1 || reps > 13) {
            if(reps > 13){
                if (tries >= 2) {
                    throw std::runtime_error("Idi nahui eblan.");
                }
                std::cout << "Eblan napisano zhe <13 typoi baran: ";
                std::cin  >> reps;
                ++tries;
            }
            else{
                std::cout << "Invalid input. Enter weight (positive number) and reps (1-13): ";
                std::cin >> weight >> reps;

            }
        }
        CalculateBenchPress cacl(weight, reps);
        cacl.getResult();
        std::cout << "\nAre you want to check another results?[y/n] ";
        std::cin >> question;
        std::cout << "\n";
    }
    std::cout << "Goodbye, bro!\n";

}catch(const std::exception& e){
    std::cerr << e.what() << '\n';
    return -1000;
}
}
