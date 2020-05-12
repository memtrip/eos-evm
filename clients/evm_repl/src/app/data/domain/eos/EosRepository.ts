import { Observable, of } from "rxjs";
import DomainResponse from "../DomainResponse";
import { getEnv } from "../../storage/env/EnvDao";
import { catchError, mergeMap, map } from "rxjs/operators";
import { createEvmAccount, rawEvmTransaction } from "../../api/eos/EosApi";

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

const rawTransaction = (
  ethereumTransactions: string
): Observable<DomainResponse<void>> => {
  return getEnv().pipe(
    mergeMap((envEntity) => {
      if (envEntity != null) {
        return rawEvmTransaction(
          envEntity.api || "",
          envEntity.evmContractName || "",
          envEntity.eosAccountName || "",
          envEntity.eosPrivateKey || "",
          ethereumTransactions,
          envEntity.eosAccountName || ""
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

export { createAccount, rawTransaction };
