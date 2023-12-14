#include <cstdio>
#include <sstream>
#include <string>

#include "CLHEP/Random/MTwistEngine.h"


const std::string concat(const std::string& s, int i)
{
    std::stringstream ss;
    ss << s << i;
    return ss.str();
}


double monteCarlo(CLHEP::MTwistEngine& mt, const std::string& statusFile) {
    
    unsigned int totalInCircle = 0;

    double x, y;
    
    mt.restoreStatus(statusFile.c_str());
    for(unsigned int i = 0; i < 1'000'000'000; ++i) {
        x = mt.flat();
        y = mt.flat();
        if(x*x + y*y <= 1) ++totalInCircle;
    }

    return 4*((double)totalInCircle/1'000'000'000);
}


int main(void) {

    std::string basename = "MTStatus";

    double somme = 0;
    double currentPi;

    CLHEP::MTwistEngine mt;

    // Calculs séquentiels
    for(unsigned int i = 1; i <= 10; ++i) {
        currentPi = monteCarlo(mt, concat(basename, i));
        somme += currentPi;
        printf("Estimation %d : %1.8f\n", i, currentPi);
    }

    printf("Moyenne des calculs : %1.8f\n", somme/10);

    return 0;
}