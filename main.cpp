#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
//removed two single use funcitons
 
//made the input checker into a simple if else instead of a 60+ line swich/case
int charToInt(char character){
        int enteredChar = (int)character;
        if(enteredChar <= 122 && enteredChar >= 97){ //97 = (int)'a' 122 = (int)'z'
            return (enteredChar - 87);            
        }else if(enteredChar <= 90 && enteredChar >= 65){ //65 = (int)'A' 90 = (int)'Z'
            return((int)character - 55);
        }else{ // (int)'1' - 48 = 1
            return((int)character - 48);
        }
}

//completely redone
std::string from10(int num_from10, int base_from10) { 
    
    int inNum = num_from10;
    int base = base_from10;
    
    std::string final_from10{};
    while(inNum >= 1){
        int check = inNum%base;
        if(!check){
            final_from10 += std::to_string(0);
            inNum = (int)inNum/base;
        }else if(check >= 10) {
            final_from10 += (char)check + 55;
            inNum = (int)inNum/base;
        }else{
            final_from10 += std::to_string(check);
            inNum = (int)inNum/base;
        }
    }
    std::reverse(final_from10.begin(), final_from10.end());

    return final_from10;
}

int to10(std::string num_to10, int base_to10) {

    const int sizeOfNum = num_to10.length();
    int modExponent{sizeOfNum - 1};
    double final_to10{ 0 };
    
    for(int i{ 0 }; i < sizeOfNum; ++i){
        int value{ charToInt(num_to10[i]) };
        double exponentEquation{ pow(base_to10,modExponent) };  //FIXED NARROWING WARNING 
        int valueAdj{ value * (int)exponentEquation };
        --modExponent;
        final_to10 += valueAdj;
    };
    return final_to10;
}


int main()
{
    
    std::string firstInput{};
    std::cout << "Enter your first number: "; std::cin >> firstInput;
    int firstBase{};
    std::cout << "\n" << "Enter the base of your first input: "; std::cin >> firstBase;
    int convBase{0};
    std::cout << "\n" << "Enter the base you would like to convert " << firstInput << " to: "; std::cin >> convBase;
    
    int toAnswer = to10(firstInput, firstBase);
    std::string fromAnswer = from10(toAnswer, convBase);
    
    std::cout << "\n\n\n" << "Your answer is " << fromAnswer;

    return 0;
}
