#include "CLHEP/Random/MTwistEngine.h"

#include <sstream>
#include <string>

const std::string concat(const std::string& s, int i)
{
    std::stringstream ss;
    ss << s << i;
    return ss.str();
}

int main() {

    std::string basename = "MTStatus";

    CLHEP::MTwistEngine mt;

    // savestatus
    mt.saveStatus("MTStatus1");

    // 9 fois
    for(unsigned int i = 2; i <= 10; ++i) {
        // 2 milliards de tirages
        for(unsigned int t = 0; t < 2'000'000'000; ++t) {
            mt.flat();
        }
        // savestatus
        mt.saveStatus(concat(basename, i).c_str());
    }

    return 0;
}