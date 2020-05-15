import { combineEpics } from "redux-observable";
import {
  eosioApiEpic,
  evmContractNameEpic,
  eosAccountNameEpic,
  eosPrivateKeyEpic,
  getEvmEpic,
  getEvmAccountEpic,
  createEvmAccountEpic,
  rawEvmSignedTransactionEpic,
  rawEvmUnsignedTransactionEpic,
  seedEvmTransactionEpic,
  withdrawBalanceEpic,
  getBalanceEpic,
  getEvmCodeEpic,
  getEvmStateEpic,
} from "./root/model/AppRootEpic";

const rootEpic = combineEpics(
  eosioApiEpic,
  evmContractNameEpic,
  eosAccountNameEpic,
  eosPrivateKeyEpic,
  getEvmEpic,
  createEvmAccountEpic,
  rawEvmSignedTransactionEpic,
  rawEvmUnsignedTransactionEpic,
  seedEvmTransactionEpic,
  withdrawBalanceEpic,
  getBalanceEpic,
  getEvmAccountEpic,
  getEvmCodeEpic,
  getEvmStateEpic
);

export { rootEpic };
