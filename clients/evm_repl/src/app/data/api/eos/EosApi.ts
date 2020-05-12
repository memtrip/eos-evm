import { Observable } from "rxjs";
import { pushTransaction } from "../RxEos";
import { fromHexString } from "../Utils";

const createEvmAccount = (
  chainApiUrl: string,
  evmContractName: string,
  accountName: string,
  privateKey: string,
  blob: string
): Observable<any> => {
  return pushTransaction(
    chainApiUrl,
    "create",
    evmContractName,
    accountName,
    privateKey,
    {
      from: accountName,
      message: blob,
    }
  );
};

const rawEvmTransaction = (
  chainApiUrl: string,
  evmContractName: string,
  accountName: string,
  privateKey: string,
  ethereumTransaction: string,
  sender?: string
): Observable<any> => {
  return pushTransaction(
    chainApiUrl,
    "raw",
    evmContractName,
    accountName,
    privateKey,
    {
      from: accountName,
      code: fromHexString(ethereumTransaction),
      sender: sender || "",
    }
  );
};

export { createEvmAccount, rawEvmTransaction };
