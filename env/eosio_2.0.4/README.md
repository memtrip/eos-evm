## eosio 2.0.4
### Build
docker build --tag eos_evm_2_0_4:1.0 . 

### Start nodeos
docker run -dt --name eos_evm_2_0_4 --publish 8000:8080 --volume /Users/samkirton/.eosio/eos-evm:/eosio -w /eosio eos_evm_2_0_4:1.0 /bin/bash