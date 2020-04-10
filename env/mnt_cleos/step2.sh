#!/bin/sh

# wait for step1
until $(bash /init/step1_health.sh); do
  echo 'step2 is waiting for step1...'
  sleep 5
done

# create the default wallet
declare CREATE_WALLET_RESULT=($(cleos wallet create --to-console))
WALLET_PASSWORD=${CREATE_WALLET_RESULT[22]}

# import the `signature-provider` private key into the default wallet
cleos wallet import --private-key 5K7EYY3j1YY14TSFVfqgtbWbrw3FA8BUUnSyFGgwHi8Uy61wU1o

# import the key into the default wallet
cleos wallet import --private-key $PRIVATE_KEY

# install the old eosio.system contract
n=0
until [ $n -ge 5 ]
do
   cleos --url http://nodeos:8888/ set contract eosio /old-contracts/build/contracts/eosio.system
   n=$[$n+1]
   sleep 1
done

cleos --url http://nodeos:8888/ push action eosio activate '["f0af56d2c5a48d60a4a5b5c903edfb7db3a736a94ed589d0b797df33ff9d3e1d"]' -p eosio # GET_SENDER
cleos --url http://nodeos:8888/ push action eosio activate '["2652f5f96006294109b3dd0bbde63693f55324af452b799ee137a81a905eed25"]' -p eosio # FORWARD_SETCODE
cleos --url http://nodeos:8888/ push action eosio activate '["8ba52fe7a3956c5cd3a656a3174b931d3bb2abb45578befc59f283ecd816a405"]' -p eosio # ONLY_BILL_FIRST_AUTHORIZER
cleos --url http://nodeos:8888/ push action eosio activate '["ad9e3d8f650687709fd68f4b90b41f7d825a365b02c23a636cef88ac2ac00c43"]' -p eosio # RESTRICT_ACTION_TO_SELF
cleos --url http://nodeos:8888/ push action eosio activate '["68dcaa34c0517d19666e6b33add67351d8c5f69e999ca1e37931bc410a297428"]' -p eosio # DISALLOW_EMPTY_PRODUCER_SCHEDULE
cleos --url http://nodeos:8888/ push action eosio activate '["e0fb64b1085cc5538970158d05a009c24e276fb94e1a0bf6a528b48fbc4ff526"]' -p eosio # FIX_LINKAUTH_RESTRICTION
cleos --url http://nodeos:8888/ push action eosio activate '["ef43112c6543b88db2283a2e077278c315ae2c84719a8b25f25cc88565fbea99"]' -p eosio # REPLACE_DEFERRED
cleos --url http://nodeos:8888/ push action eosio activate '["4a90c00d55454dc5b059055ca213579c6ea856967712a56017487886a4d4cc0f"]' -p eosio # NO_DUPLICATE_DEFERRED_ID
cleos --url http://nodeos:8888/ push action eosio activate '["1a99a59d87e06e09ec5b028a9cbb7749b4a5ad8819004365d02dc4379a8b7241"]' -p eosio # ONLY_LINK_TO_EXISTING_PERMISSION
cleos --url http://nodeos:8888/ push action eosio activate '["4e7bf348da00a945489b2a681749eb56f5de00b900014e137ddae39f48f69d67"]' -p eosio # RAM_RESTRICTIONS
cleos --url http://nodeos:8888/ push action eosio activate '["4fca8bd82bbd181e714e283f83e1b45d95ca5af40fb89ad3977b653c448f78c2"]' -p eosio # WEBAUTHN_KEY
cleos --url http://nodeos:8888/ push action eosio activate '["299dcb6af692324b899b39f16d5a530a33062804e41f09dc97e9f156b4476707"]' -p eosio # WTMSIG_BLOCK_SIGNATURES

# issue tokens
cleos --url http://nodeos:8888/ push action eosio.token create '[ "eosio", "10000000000.0000 EVM" ]' -p eosio.token@active
cleos --url http://nodeos:8888/ push action eosio.token issue '[ "eosio", "1000000000.0000 EVM", "memo" ]' -p eosio@active

cleos --url http://nodeos:8888/ transfer eosio eos.evm "1000000000.0000 EVM" "memo" -p eosio@active
