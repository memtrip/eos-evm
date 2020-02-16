#include <string>

class Address {
  public:
    static std::string createAccountIdentifier(std::string accountName, std::string salt);
};