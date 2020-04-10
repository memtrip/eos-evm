#!/bin/sh

# wait for step2
until $(bash /init/step2_health.sh); do
  echo 'step3 is waiting for step2...'
  sleep 5
done

# create the default wallet
declare CREATE_WALLET_RESULT=($(cleos wallet create --to-console))
WALLET_PASSWORD=${CREATE_WALLET_RESULT[22]}

# import the `signature-provider` private key into the default wallet
cleos wallet import --private-key 5K7EYY3j1YY14TSFVfqgtbWbrw3FA8BUUnSyFGgwHi8Uy61wU1o

# import the key into the default wallet
cleos wallet import --private-key $PRIVATE_KEY

# install the eosio system contract
n=0
until [ $n -ge 5 ]
do
   cleos --url http://nodeos:8888/ set contract eosio /contracts/build/contracts/eosio.system
   n=$[$n+1]
   sleep 1
done

cleos --url http://nodeos:8888/ push action eosio setpriv '["eosio.msig", 1]' -p eosio@active
cleos --url http://nodeos:8888/ push action eosio init '["0", "4,EVM"]' -p eosio@active