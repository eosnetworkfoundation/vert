#include <eosio/eosio.hpp>
using namespace eosio;

CONTRACT authtester : public contract {
   public:
      using contract::contract;

      ACTION test( name account ){
         require_auth(account);
      }

      ACTION inlinetest(name account, name contract){
         action(
            permission_level{account, "active"_n},
			contract,
			"test"_n,
			std::make_tuple(account)
		 ).send();
      }
};