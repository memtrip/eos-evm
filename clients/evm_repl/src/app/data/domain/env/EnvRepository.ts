import { Observable, of } from "rxjs";
import DomainResponse from "../DomainResponse";
import { updateEnv } from "../../storage/env/EnvDao";
import { catchError, map } from "rxjs/operators";

const updateEnvApi = (envApi: string): Observable<DomainResponse<void>> => {
  return updateEnv(envApi, undefined, undefined, undefined).pipe(
    map(() => DomainResponse.createSuccess(void 0)),
    catchError((error) => of(DomainResponse.createError<void>(error)))
  );
};

const updateEnvContractName = (
  envContractName: string
): Observable<DomainResponse<void>> => {
  return updateEnv(undefined, envContractName, undefined, undefined).pipe(
    map(() => DomainResponse.createSuccess(void 0)),
    catchError((error) => of(DomainResponse.createError<void>(error)))
  );
};

const updateEnvEosAccountName = (
  eosAccountName: string
): Observable<DomainResponse<void>> => {
  return updateEnv(undefined, undefined, eosAccountName, undefined).pipe(
    map(() => DomainResponse.createSuccess(void 0)),
    catchError((error) => of(DomainResponse.createError<void>(error)))
  );
};

const updateEnvEosPrivateKey = (
  eosPrivateKey: string
): Observable<DomainResponse<void>> => {
  return updateEnv(undefined, undefined, undefined, eosPrivateKey).pipe(
    map(() => DomainResponse.createSuccess(void 0)),
    catchError((error) => of(DomainResponse.createError<void>(error)))
  );
};

export {
  updateEnvApi,
  updateEnvContractName,
  updateEnvEosAccountName,
  updateEnvEosPrivateKey,
};
