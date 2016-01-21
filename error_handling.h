#ifndef GUARD_ERROR_HANDLING_H
#define GUARD_ERROR_HANDLING_H

#include <exception>
#include <string>
#include <SDL.h>

class InitError : public std::exception {
private:
    std::string msg;
public:
    InitError();
    InitError(const std::string&);
    virtual ~InitError() throw();
    virtual const char *what() const throw();
};

#endif
