import { EnvEntity } from "./EnvEntity";
import { RxStorage } from "../RxStorage";
import { Observable } from "rxjs";
import { mergeMap } from "rxjs/operators";
import { Optional } from "../../../shared/Optional";

const storage = new RxStorage<EnvEntity>("EnvEntity");

const getEnv = (): Observable<Optional<EnvEntity>> => {
  return storage.getItem();
};

const insertEnv = (entity: EnvEntity): Observable<void> => {
  return storage.insertItem(entity);
};

const updateEnv = (
  api: Optional<string>,
  evmContractName: Optional<string>,
  eosAccountName: Optional<string>,
  eosPrivateKey: Optional<string>
): Observable<void> => {
  return storage.getItem().pipe(
    mergeMap((envEntity) => {
      if (envEntity != null) {
        return storage.removeItem().pipe(
          mergeMap(() => {
            return storage.insertItem({
              api: api != null ? api : envEntity.api,
              evmContractName:
                evmContractName != null
                  ? evmContractName
                  : envEntity.evmContractName,
              eosAccountName:
                eosAccountName != null
                  ? eosAccountName
                  : envEntity.eosAccountName,
              eosPrivateKey:
                eosPrivateKey != null ? eosPrivateKey : envEntity.eosPrivateKey,
            });
          })
        );
      } else {
        return storage.insertItem({
          api: api != null ? api : "",
          evmContractName: evmContractName != null ? evmContractName : "",
          eosAccountName: eosAccountName != null ? eosAccountName : "",
          eosPrivateKey: eosPrivateKey != null ? eosPrivateKey : "",
        });
      }
    })
  );
};

export { getEnv, insertEnv, updateEnv };
