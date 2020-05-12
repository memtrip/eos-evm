import { ofType, ActionsObservable } from "redux-observable";
import { AnyAction } from "redux";
import { AppRootActionType } from "./AppRootActions";
import { mergeMap, map, catchError, startWith } from "rxjs/operators";
import DomainResponse from "../../../data/domain/DomainResponse";
import {
  responseAction,
  startedAction,
  genericErrorAction,
} from "../../../shared/Actions";
import {
  updateEnvApi,
  updateEnvContractName,
  updateEnvEosAccountName,
  updateEnvEosPrivateKey,
} from "../../../data/domain/env/EnvRepository";
import {
  createAccount,
  rawTransaction,
} from "../../../data/domain/eos/EosRepository";

const eosioApiEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_EOSIO_API),
    mergeMap((action) =>
      updateEnvApi(action.value).pipe(
        map<DomainResponse<void>, any>((response) =>
          responseAction(action.type, response)
        ),
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
        map<DomainResponse<void>, any>((response) =>
          responseAction(action.type, response)
        ),
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
        map<DomainResponse<void>, any>((response) =>
          responseAction(action.type, response)
        ),
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
        map<DomainResponse<void>, any>((response) =>
          responseAction(action.type, response)
        ),
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
        map<DomainResponse<void>, any>((response) =>
          responseAction(action.type, response)
        ),
        catchError(() => genericErrorAction(action.type)),
        startWith(startedAction(action.type))
      )
    )
  );
};

const rawEvmTransactionEpic = (action$: ActionsObservable<AnyAction>) => {
  return action$.pipe(
    ofType(AppRootActionType.COMMAND_RAW),
    mergeMap((action) =>
      rawTransaction(action.value).pipe(
        map<DomainResponse<void>, any>((response) =>
          responseAction(action.type, response)
        ),
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
  createEvmAccountEpic,
  rawEvmTransactionEpic,
};
