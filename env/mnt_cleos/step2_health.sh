#!/bin/sh

# Confirm that the EVM tokens have been issued, this is the last action of step2
response=$(curl http://nodeos:8888/v1/chain/get_currency_balance -d '{"code":"eosio.token","account":"eosio","symbol":"EVM"}' --request POST)
if [[ $response == *"EVM"* ]]; then
  exit 0
else
  exit 1
fi