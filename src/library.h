#ifndef PLAYGROUND_LIBRARY_H
#define PLAYGROUND_LIBRARY_H

#include <string>

enum ConnectFlags {
    CONNECT_PERSIST,
    CONNECT_DEFERRED,
    CONNECT_REFERENCE_COUNTED,
    CONNECT_ONESHOT
};

std::string hello();

#endif //PLAYGROUND_LIBRARY_H