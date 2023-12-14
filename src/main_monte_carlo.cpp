#include "CLHEP/Random/MTwistEngine.h"

#include <string>

int main(int, char** argv) {

    CLHEP::MTwistEngine mt;
    std::string statusFileName = argv[1];

    unsigned int totalInCircle = 0;
    double x, y;
    
    mt.restoreStatus(statusFileName.c_str());

    for(unsigned int i = 0; i < 1'000'000'000; ++i) {
        x = mt.flat();
        y = mt.flat();
        if(x*x + y*y <= 1) ++totalInCircle;
    }

    printf("%1.10f\n", 4*((double)totalInCircle/1'000'000'000));
    return 0;
}