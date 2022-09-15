#include "NewExceptions.h"

const char* bad_range::what() const noexcept {
    return "ERROR: Out of Range!";
}
const char* bad_length::what() const noexcept {
    return "ERROR: Bad Lenght!";
}
const char* bad_index::what() const noexcept {
    return "ERROR: Bad Index!";
}