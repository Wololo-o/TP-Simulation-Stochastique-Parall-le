#include <cstdio>
#include <functional>
#include <mutex>
#include <string>
#include <thread>

#include "CLHEP/Random/MTwistEngine.h"

const std::string concat(const std::string& s, int i)
{
    std::stringstream ss;
    ss << s << i;
    return ss.str();
}


void monteCarlo(CLHEP::MTwistEngine mt, const std::string statusFile, double& somme, std::mutex& mutex) {
    
    unsigned int totalInCircle = 0;

    double x, y;
    
    mt.restoreStatus(statusFile.c_str());
    for(unsigned int i = 0; i < 1'000'000'000; ++i) {
        x = mt.flat();
        y = mt.flat();
        if(x*x + y*y <= 1) ++totalInCircle;
    }

    {
        std::lock_guard guard(mutex);
        somme += 4*((double)totalInCircle/1'000'000'000);
    }
}


int main(void) {

    std::string baseName = "MTStatus";
    std::string currentName;

    double somme = 0;

    CLHEP::MTwistEngine mt;

    std::thread threads[10];
    std::mutex mutex;

    for(unsigned int i = 1; i <= 10; ++i) {
        currentName = concat(baseName, i);
        threads[i-1] = std::thread(monteCarlo, mt, currentName, std::ref(somme), std::ref(mutex));
    }

    for(unsigned int i = 1; i <= 10; ++i) {
        threads[i-1].join();
    }

    printf("Moyenne des calculs : %1.8f\n", somme/10);

    return 0;
}