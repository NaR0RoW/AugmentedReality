#include <cstring>
#include "cpp/base_exception.h"


namespace exception {
Exception::Exception(std::string es) : _errstr(std::move(es)) {
    _errstr += "\n";
    _errstr += strerror(errno);
}

const char *Exception::what() const noexcept {
    return _errstr.c_str();
}
}  // namespace process
