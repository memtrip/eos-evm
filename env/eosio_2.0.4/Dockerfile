FROM ubuntu:bionic

RUN apt-get update -y
RUN apt-get install wget -y
RUN apt-get install curl -y
RUN apt-get install git -y

RUN wget https://github.com/eosio/eos/releases/download/v2.0.4/eosio_2.0.4-1-ubuntu-18.04_amd64.deb
RUN apt-get install ./eosio_2.0.4-1-ubuntu-18.04_amd64.deb -y

RUN wget https://github.com/eosio/eosio.cdt/releases/download/v1.7.0/eosio.cdt_1.7.0-1-ubuntu-18.04_amd64.deb
RUN apt-get install ./eosio.cdt_1.7.0-1-ubuntu-18.04_amd64.deb

RUN apt-get install build-essential -y
RUN apt-get install cmake -y

RUN apt-get install unzip

RUN wget https://github.com/EOSIO/eosio.contracts/archive/master.zip
RUN unzip master.zip
RUN mv eosio.contracts-master contracts

WORKDIR /contracts
RUN rm -fr build
RUN mkdir build
WORKDIR /contracts/build
RUN cmake ..
RUN make -j$( nproc )