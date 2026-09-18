#include<iostream>

int main()
{
    int n;
    int k;
    int currentk = 2;
    int i;
    int lastpos = 0;
    std::cout << "Input n: "; 
    std::cin >> n;
    std::cout << "Input k: ";
    std::cin >> k;
    int astroarray[n]{0};
    
    for(i = 0; i < n; ++i){
        if(k < 2 || currentk < 2){
        k = 2;
        }

        int remaining = n - i;

        if(i == 0){
            if(k % remaining == 0){
            currentk = remaining;
            }
            else{
                currentk = k % remaining;
            }
        }
        else{
            if(currentk % remaining == 0){
                currentk = remaining;
            }
            else{
                currentk = currentk % remaining;
            }
        }

        int step = 0;
        int deadpos = 0;

        while(step < currentk){
            if(i == 0){
                step++;
            }
            if(astroarray[lastpos] == 0){
            step++; deadpos = lastpos;
            }
            lastpos = (lastpos + 1) % n;
        }
        astroarray[deadpos] = 1;
        if(deadpos % 2 == 0){
            currentk = currentk + 2;
        }
        else{
            currentk = currentk - 1;
        }
        if(remaining > 1){
            std::cout << "Astronaut " << deadpos + 1 << " eliminiated" << std::endl;
        }
        else{
            std::cout << "Astronaut " << deadpos + 1 << " wins!";
        }
    }
    return 0;
}