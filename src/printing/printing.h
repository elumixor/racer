//
// Created by vlado on 5/6/20.
//

#ifndef RACER_PRINTING_H
#define RACER_PRINTING_H

#include <string>

inline void print(const char *value) {
    printf("%s\n\r", value);
}

template<typename T>
void print(const T &value, const char *end = "\n\r") {
    printf("%s%s", std::to_string(value).c_str(), end);
}

#endif //RACER_PRINTING_H
