#include <iostream>

int main()
{
    std::string word;
    int wordint;
    int i;
    int j;
    int mode;
    int letter1;
    int letter2;
    char letterfinal;
    
    std::cout << "Human-Alien-Cipher-Inator" << std::endl;
    std::cout << "1. Cipher message" << std::endl << "2. Decipher message" << std::endl << "Choose mode: ";
    std::cin >> mode;

    if(mode == 1 || mode == 2){
    
        std::cout << "Input word in lowercase: ";
        std::cin >> word;

        wordint = word.length();

        for(j = 0; j < wordint; j++){
            if(word.at(j) < 'a' || word.at(j) > 'z'){
                std::cout << "Error"; return 0;
            }
        }

        char previousletter = word.at(0); 

        switch(mode){
            case 1:
                for(i = 0; i < wordint; i++){
                if(i == 0){
                std::cout << word.at(i);
                }
                else{
                letter1 = word.at(i) - 'a' + 1;
                letter2 = word.at(--i) - 'a' + 1;
                letterfinal = 'a' + (letter1 + letter2) % 26 - 1;
                i++; 
                if(letterfinal == '`'){
                    std::cout << 'z';
                }
                else
                std::cout << letterfinal;
                }
            }   break;
            case 2:
                for(i = 0; i < wordint; i++){
                if(i == 0){
                std::cout << word.at(i);
                }
                else{
                letter1 = word.at(i) - 'a' + 1;
                letter2 = previousletter - 'a' + 1;
                previousletter = 'a' + (letter1 - letter2 + 26) % 26 - 1;
                if(previousletter == '`'){
                    previousletter = 'z';
                    std::cout << previousletter;
                }
                else
                std::cout << previousletter;
                }
            }   break;
        }
    }
    else{
        std::cout << "Invalid mode";
    }

    return 0;
}