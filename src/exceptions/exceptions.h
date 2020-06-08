//
// Created by vlado on 6/6/20.
//

#ifndef RACER_EXCEPTIONS_H
#define RACER_EXCEPTIONS_H


#include <c++/9/exception>

struct BaseException : public std::exception {
private:
    const char *message;
public:
    explicit inline BaseException(const char *message = "Racer Base Exception") : message{message} {}
    inline const char *what() const noexcept override { return message; }
};

#define DECLARE_EXCEPTION(kind, default_message) \
    struct kind : public BaseException { explicit inline kind(const char *message = default_message) : BaseException{message} {} };

DECLARE_EXCEPTION(NotImplementedException, "This function or method is not implemented.")

DECLARE_EXCEPTION(InvalidArgumentException, "Received an invalid argument.")

#endif //RACER_EXCEPTIONS_H
