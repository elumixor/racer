//
// Created by vlado on 5/6/20.
//

#ifndef RACER_PRINTING_H
#define RACER_PRINTING_H

#include <string>

//template<typename T>
//string to_string(const T &value);

inline void print(const char *value) {
    printf("%s\n\r", value);
}

template<typename T>
void print(const T &value) {
    printf("%s\n\r", std::to_string(value).c_str());
}

#endif //RACER_PRINTING_H
