#pragma once
#include <iostream>

class bad_range : public std::exception {
public:
    virtual const char* what() const noexcept override;
};

class bad_length : public  std::exception {
    virtual const char* what() const noexcept override;
};

class bad_index : public std::exception {
    virtual const char* what() const noexcept override;
};

