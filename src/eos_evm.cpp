#include <eos_evm.hpp>

namespace evm {
  ACTION evm::eos_evm::writelog(name from, string message) {
    require_auth(get_self());
    
    log_table _log(get_self(), get_self().value);

    _log.emplace(from, [&](auto& log) {
      log.key = _log.available_primary_key();
      log.user = from;
      log.message = message;
    });
  }

  ACTION evm::eos_evm::clearlog() {
    require_auth(get_self());

    log_table _log(get_self(), get_self().value);

    auto log_itr = _log.begin();
    while (log_itr != _log.end()) {
      log_itr = _log.erase(log_itr);
    }
  }
}

EOSIO_DISPATCH(evm::eos_evm, (writelog)(clearlog))
