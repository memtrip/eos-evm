import { Observable } from "rxjs";
import { pushTransaction, getTableRows } from "../RxEos";
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

const rawEvmUnsignedTransaction = (
  chainApiUrl: string,
  evmContractName: string,
  accountName: string,
  privateKey: string,
  ethereumTransaction: string,
  sender: string
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
      sender: sender,
    }
  );
};

const getEvmAccountIdentifier = (
  chainApiUrl: string,
  evmContractName: string,
  accountName: string
): Observable<any> => {
  return getTableRows(
    chainApiUrl,
    evmContractName,
    evmContractName,
    "account",
    accountName,
    accountName
  );
};

const getEvmCode = (
  chainApiUrl: string,
  evmContractName: string,
  accountIdentifier: string
): Observable<any> => {
  return getTableRows(
    chainApiUrl,
    evmContractName,
    evmContractName,
    "accountcode",
    accountIdentifier,
    accountIdentifier,
    "owneraddress",
    "sha256",
    "2"
  );
};

const getEvmState = (
  chainApiUrl: string,
  evmContractName: string,
  accountIdentifier: string
): Observable<any> => {
  return getTableRows(
    chainApiUrl,
    evmContractName,
    evmContractName,
    "accountstate",
    accountIdentifier,
    accountIdentifier,
    "stateid",
    "sha256",
    "3"
  );
};

export {
  createEvmAccount,
  rawEvmUnsignedTransaction,
  getEvmAccountIdentifier,
  getEvmCode,
  getEvmState,
};
