import { ofType, ActionsObservable } from "redux-observable";
import { AnyAction } from "redux";
import { AppRootActionType } from "./AppRootActions";
import { mergeMap, map, catchError, startWith } from "rxjs/operators";
import {
  responseAction,
  startedAction,
  genericErrorAction,
} from "../../../shared/Actions";
import {
  getEnvEntity,
  updateEnvApi,
  updateEnvContractName,
  updateEnvEosAccountName,
  updateEnvEosPrivateKey,
} from "../../../data/domain/env/EnvRepository";
import {
  createAccount,
  rawUnsignedTransaction,
  getAccountIdentifier,
  getCode,
  getState,
} from "../../../data/domain/eos/EosRepository";

const eosioApiEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_EOSIO_API),
    mergeMap((action) =>
      updateEnvApi(action.value).pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const evmContractNameEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_EVM_CONTRACT_NAME),
    mergeMap((action) =>
      updateEnvContractName(action.value).pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const eosAccountNameEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_EOS_ACCOUNT_NAME),
    mergeMap((action) =>
      updateEnvEosAccountName(action.value).pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const eosPrivateKeyEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_EOS_PRIVATE_KEY),
    mergeMap((action) =>
      updateEnvEosPrivateKey(action.value).pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const getEvmEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_ENV),
    mergeMap((action) =>
      getEnvEntity().pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const createEvmAccountEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_CREATE),
    mergeMap((action) =>
      createAccount(action.value).pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const rawEvmUnsignedTransactionEpic = (
  action$: ActionsObservable<AnyAction>
) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_RAW_UNSIGNED),
    mergeMap((action) =>
      rawUnsignedTransaction(action.sender, action.rawTransaction).pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const getEvmAccountEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_ACCOUNT),
    mergeMap((action) =>
      getAccountIdentifier(action.value).pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const getEvmCodeEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_CODE),
    mergeMap((action) =>
      getCode(action.value).pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const getEvmStateEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_STATE),
    mergeMap((action) =>
      getState(action.value).pipe(
        map((response) => responseAction(action.type, response)),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

export {
  eosioApiEpic,
  evmContractNameEpic,
  eosAccountNameEpic,
  eosPrivateKeyEpic,
  getEvmEpic,
  createEvmAccountEpic,
  rawEvmUnsignedTransactionEpic,
  getEvmAccountEpic,
  getEvmCodeEpic,
  getEvmStateEpic,
};
