//
// Created by vlado on 6/6/20.
//

#include <execinfo.h>
#include <cstdio>
#include <cstdlib>
#include "exceptions.h"

const char *BaseException::what() const noexcept {
    return "Racer Base Exception";
}
const char *NotImplementedException::what() const noexcept {
    return "This function or method is not implemented.";
}
