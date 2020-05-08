# copy wasm 
# TODO: when the repository is public, this will be replaced with pulling the local code in the Docker image
rm -rf mnt_cleos/eos_evm/
mkdir mnt_cleos/eos_evm/
cp ../contract/eos_evm.wasm ./mnt_cleos/eos_evm/
cp ../contract/eos_evm.abi ./mnt_cleos/eos_evm/

# clean the blockchain state of the attached volume
rm -rf mnt_nodeos/blockchain/
mkdir mnt_nodeos/blockchain/

# start
docker-compose up --force-recreate --remove-orphans