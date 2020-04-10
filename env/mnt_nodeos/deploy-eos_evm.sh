#!/bin/sh

NAME=$(uuidgen)
cleos wallet create --to-console -n $NAME
cleos wallet import --private-key $PRIVATE_KEY -n $NAME

cleos --url http://nodeos:8888/ set contract eos.evm /eosio/eos_evm/