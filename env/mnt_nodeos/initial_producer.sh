ROOTDIR=$1
PRODUCER_NAME=$2

nodeos \
--genesis-json $ROOTDIR"/genesis.json" \
--signature-provider EOS8mUftJXepGzdQ2TaCduNuSPAfXJHf22uex4u41ab1EVv9EAhWt=KEY:5K7EYY3j1YY14TSFVfqgtbWbrw3FA8BUUnSyFGgwHi8Uy61wU1o \
--plugin eosio::producer_plugin \
--plugin eosio::producer_api_plugin \
--plugin eosio::chain_plugin \
--plugin eosio::chain_api_plugin \
--plugin eosio::http_plugin \
--plugin eosio::history_api_plugin \
--plugin eosio::history_plugin \
--data-dir $ROOTDIR"/blockchain/data" \
--blocks-dir $ROOTDIR"/blockchain/blocks" \
--config-dir $ROOTDIR"/blockchain/config" \
--producer-name $PRODUCER_NAME \
--http-server-address 0.0.0.0:8888 \
--p2p-listen-endpoint 0.0.0.0:9011 \
--access-control-allow-origin=* \
--contracts-console \
--http-validate-host=false \
--verbose-http-errors \
--enable-stale-production \
--max-transaction-time=2000 \
--disable-replay-opts \
--filter-on=* \
--filter-out=eosio:onblock: \
>> $ROOTDIR"/blockchain/nodeos.log" 2>&1 & \
echo $! > $ROOTDIR"/blockchain/eosd.pid"

tail -f /eosio/blockchain/nodeos.log