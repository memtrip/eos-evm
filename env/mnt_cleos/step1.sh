#!/bin/sh

# wait for nodeos
until $(wget http://nodeos:8888/v1/chain/get_info); do
  echo 'cleos is waiting for nodeos...'
  sleep 1
done

# create the default wallet
declare CREATE_WALLET_RESULT=($(cleos wallet create --to-console))
WALLET_PASSWORD=${CREATE_WALLET_RESULT[22]}

# import the `signature-provider` private key into the default wallet
cleos wallet import --private-key 5K7EYY3j1YY14TSFVfqgtbWbrw3FA8BUUnSyFGgwHi8Uy61wU1o

# import the key into the default wallet
cleos wallet import --private-key $PRIVATE_KEY

echo "priv/pub/wallet"
echo $PRIVATE_KEY
echo $PUBLIC_KEY
echo $WALLET_PASSWORD

# create system accounts
cleos --url http://nodeos:8888/ create account eosio eosio.names $PUBLIC_KEY
cleos --url http://nodeos:8888/ create account eosio eosio.ram $PUBLIC_KEY
cleos --url http://nodeos:8888/ create account eosio eosio.ramfee $PUBLIC_KEY
cleos --url http://nodeos:8888/ create account eosio eosio.saving $PUBLIC_KEY
cleos --url http://nodeos:8888/ create account eosio eosio.stake $PUBLIC_KEY
cleos --url http://nodeos:8888/ create account eosio eosio.rex $PUBLIC_KEY
cleos --url http://nodeos:8888/ create account eosio eosio.vpay $PUBLIC_KEY

# install the eosio.token smart contract
cleos --url http://nodeos:8888/ create account eosio eosio.token $PUBLIC_KEY
cleos --url http://nodeos:8888/ set contract eosio.token /contracts/build/contracts/eosio.token

# install the eosio.msig smart contract
cleos --url http://nodeos:8888/ create account eosio eosio.msig $PUBLIC_KEY
cleos --url http://nodeos:8888/ set contract eosio.msig /contracts/build/contracts/eosio.msig

# install the eos.evm smart contract
cleos --url http://nodeos:8888/ create account eosio eos.evm $PUBLIC_KEY
cleos --url http://nodeos:8888/ set contract eos.evm /init/eos_evm/

# PREACTIVE_FEATURE
curl --request POST \
    --url http://nodeos:8888/v1/producer/schedule_protocol_feature_activations \
    -d '{"protocol_features_to_activate": ["0ec7e080177b2c02b278d5088611686b49d739925a92d9bfcacd7fc6b74053bd"]}'

# create system accounts
cleos --url http://nodeos:8888/ create account eosio eosio.bpay $PUBLIC_KEY