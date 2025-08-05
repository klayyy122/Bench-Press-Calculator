#include"realization.hpp"


int main(){
    try{
    char question = 'y';
    std::string weight;
    std::string reps;
    Helper h;
    while(question == 'y' ){
        int tries = 0;
        
        
        std::cout << "Enter bench's weigth and count of reps(1-13)" << std::endl;
        std::cin >> weight >> reps;
        double weight_;
        int reps_;
        h.fix(weight, reps, weight_, reps_);
        while (weight_ <= 0 || reps_ < 1 || reps_ > 13) {
            
            if(reps_ > 13){
                if (tries >= 2) {
                    throw std::runtime_error("Idi nahui eblan.");
                }
                std::cout << "Eblan napisano zhe <13 typoi baran: ";
                std::cin  >> reps;
                h.fix(weight, reps, weight_, reps_);
                ++tries;
            }
            else{
                std::cout << "Invalid input. Enter weight (positive number) and reps (1-13): ";
                std::cin >> weight >> reps;
                h.fix(weight, reps, weight_, reps_);

            }
        }
        CalculateBenchPress cacl(weight_, reps_);
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
