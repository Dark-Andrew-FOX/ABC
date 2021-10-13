#ifndef __Randomize__
#define __Randomize__

#include <cstdlib>

inline auto Random() {
    return rand() % 20 + 1;
}

#endif
