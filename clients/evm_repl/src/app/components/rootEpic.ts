import { combineEpics } from "redux-observable";
import {
  eosioApiEpic,
  evmContractNameEpic,
  eosAccountNameEpic,
  eosPrivateKeyEpic,
  getEvmEpic,
  getEvmAccountEpic,
  createEvmAccountEpic,
  rawEvmUnsignedTransactionEpic,
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
  rawEvmUnsignedTransactionEpic,
  getEvmAccountEpic,
  getEvmCodeEpic,
  getEvmStateEpic
);

export { rootEpic };
