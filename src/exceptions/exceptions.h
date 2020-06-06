//
// Created by vlado on 6/6/20.
//

#ifndef RACER_EXCEPTIONS_H
#define RACER_EXCEPTIONS_H

#include <exception>
#include <string>

struct BaseException : public std::exception {
    const char *what() const noexcept override;
};

struct NotImplementedException : public BaseException {
    const char * what() const noexcept override;
};

#define NotImplemented throw NotImplementedException();

#endif //RACER_EXCEPTIONS_H
