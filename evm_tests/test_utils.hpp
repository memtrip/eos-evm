#include <sstream>
#include <iomanip>
class TestUtils {
  public:
    static std::string bytesToHex(std::shared_ptr<bytes_t> in) {
      bytes_t::const_iterator from = in->cbegin();
      bytes_t::const_iterator to = in->cend();
      std::ostringstream oss;
      for (; from != to; ++from)
          oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(*from);
      return oss.str();
    }

    static std::string bytesToHex(const bytes_t& in) {
      bytes_t::const_iterator from = in.cbegin();
      bytes_t::const_iterator to = in.cend();
      std::ostringstream oss;
      for (; from != to; ++from)
          oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(*from);
      return oss.str();
    }
};