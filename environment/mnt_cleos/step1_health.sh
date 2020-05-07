#!/bin/sh

# Confirm that create bpay account has been executed, this is the last action of step1
status_code=$(curl --output /dev/null --write-out %{http_code} --silent http://nodeos:8888/v1/chain/get_account -d '{"account_name":"eosio.bpay"} --request POST')

if [ $status_code == 200 ]; then
  exit 0
else
  exit 1
fi