import { JsonRpc, Api } from "eosjs";
import { JsSignatureProvider } from "eosjs/dist/eosjs-jssig";
import { Observable } from "rxjs";

type ApiObserver = {
  next: (arg0: any) => void;
  complete: () => void;
  error: (arg0: Error) => void;
};

const pushTransaction = (
  chainApiUrl: string,
  actionName: string,
  evmContractName: string,
  accountName: String,
  privateKey: string,
  data: any
): Observable<any> => {
  const rpc = new JsonRpc(chainApiUrl);
  const signatureProvider = new JsSignatureProvider([privateKey]);
  const api = new Api({
    rpc,
    signatureProvider,
    textDecoder: new TextDecoder(),
    textEncoder: new TextEncoder(),
  });
  return send(
    api.transact(
      {
        actions: [
          {
            account: evmContractName,
            name: actionName,
            authorization: [
              {
                actor: accountName,
                permission: "active",
              },
            ],
            data: data,
          },
        ],
      },
      {
        blocksBehind: 3,
        expireSeconds: 30,
      }
    )
  );
};

const send = (fetch: Promise<any>): Observable<any> => {
  return Observable.create((observer: ApiObserver) => {
    fetch
      .then((response) => {
        observer.next(response);
        observer.complete();
      })
      .catch((err) => {
        try {
          observer.error(Error(err.json.error.details[0].message));
        } catch {
          observer.error(err);
        }
      });
  });
};

export { pushTransaction };
