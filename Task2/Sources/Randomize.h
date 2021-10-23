#ifndef ABC2_RANDOMIZE_H
#define ABC2_RANDOMIZE_H

#include <cstdlib>

inline auto Random() {
    return rand() % 20 + 1;
}

#endif //ABC2_RANDOMIZE_H
