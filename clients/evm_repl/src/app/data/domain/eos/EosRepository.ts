import { Observable, of } from "rxjs";
import DomainResponse from "../DomainResponse";
import { getEnv } from "../../storage/env/EnvDao";
import { catchError, mergeMap, map } from "rxjs/operators";
import {
  createEvmAccount,
  rawEvmUnsignedTransaction,
  getEvmAccountIdentifier,
  getEvmCode,
  getEvmState,
} from "../../api/eos/EosApi";

const createAccount = (blob: string): Observable<DomainResponse<void>> => {
  return getEnv().pipe(
    mergeMap((envEntity) => {
      if (envEntity != null) {
        return createEvmAccount(
          envEntity.api || "",
          envEntity.evmContractName || "",
          envEntity.eosAccountName || "",
          envEntity.eosPrivateKey || "",
          blob
        ).pipe(map(() => DomainResponse.createSuccessEmpty<void>()));
      } else {
        return of(
          DomainResponse.createError<any>(
            Error(
              'Environment not setup, type "help" to view the prerequisite commands'
            )
          )
        );
      }
    }),
    catchError((error) => of(DomainResponse.createError<void>(error)))
  );
};

const rawUnsignedTransaction = (
  sender: string,
  rawTransaction: string
): Observable<DomainResponse<void>> => {
  return getEnv().pipe(
    mergeMap((envEntity) => {
      if (envEntity != null) {
        return rawEvmUnsignedTransaction(
          envEntity.api || "",
          envEntity.evmContractName || "",
          envEntity.eosAccountName || "",
          envEntity.eosPrivateKey || "",
          rawTransaction,
          sender
        ).pipe(map(() => DomainResponse.createSuccessEmpty<void>()));
      } else {
        return of(
          DomainResponse.createError<any>(
            Error(
              'Environment not setup, type "help" to view the prerequisite commands'
            )
          )
        );
      }
    }),
    catchError((error) => of(DomainResponse.createError<void>(error)))
  );
};

const getAccountIdentifier = (
  accountName: string
): Observable<DomainResponse<any>> => {
  return getEnv().pipe(
    mergeMap((envEntity) => {
      if (envEntity != null) {
        return getEvmAccountIdentifier(
          envEntity.api || "",
          envEntity.evmContractName || "",
          accountName
        ).pipe(map((entity) => DomainResponse.createSuccess<any>(entity)));
      } else {
        return of(
          DomainResponse.createError<any>(
            Error(
              'Environment not setup, type "help" to view the prerequisite commands'
            )
          )
        );
      }
    }),
    catchError((error) => of(DomainResponse.createError<any>(error)))
  );
};

const getCode = (
  accountIdentifier: string
): Observable<DomainResponse<any>> => {
  return getEnv().pipe(
    mergeMap((envEntity) => {
      if (envEntity != null) {
        return getEvmCode(
          envEntity.api || "",
          envEntity.evmContractName || "",
          accountIdentifier
        ).pipe(map((entity) => DomainResponse.createSuccess<any>(entity)));
      } else {
        return of(
          DomainResponse.createError<any>(
            Error(
              'Environment not setup, type "help" to view the prerequisite commands'
            )
          )
        );
      }
    }),
    catchError((error) => of(DomainResponse.createError<any>(error)))
  );
};

const getState = (
  accountIdentifier: string
): Observable<DomainResponse<any>> => {
  return getEnv().pipe(
    mergeMap((envEntity) => {
      if (envEntity != null) {
        return getEvmState(
          envEntity.api || "",
          envEntity.evmContractName || "",
          accountIdentifier
        ).pipe(map((entity) => DomainResponse.createSuccess<any>(entity)));
      } else {
        return of(
          DomainResponse.createError<any>(
            Error(
              'Environment not setup, type "help" to view the prerequisite commands'
            )
          )
        );
      }
    }),
    catchError((error) => of(DomainResponse.createError<any>(error)))
  );
};

export {
  createAccount,
  rawUnsignedTransaction,
  getAccountIdentifier,
  getCode,
  getState,
};
