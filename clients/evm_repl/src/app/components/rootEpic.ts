import { combineEpics } from "redux-observable";
import {
  eosioApiEpic,
  evmContractNameEpic,
  eosAccountNameEpic,
  eosPrivateKeyEpic,
  createEvmAccountEpic,
  rawEvmTransactionEpic,
} from "./root/model/AppRootEpic";

const rootEpic = combineEpics(
  eosioApiEpic,
  evmContractNameEpic,
  eosAccountNameEpic,
  eosPrivateKeyEpic,
  createEvmAccountEpic,
  rawEvmTransactionEpic
);

export { rootEpic };
