#include <stdexcept>

class IndexError : public std::runtime_error {
public:
    explicit IndexError(const std::string& message) : std::runtime_error(message) {}
};
