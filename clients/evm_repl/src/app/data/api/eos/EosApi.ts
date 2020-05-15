import { Observable } from "rxjs";
import { pushTransaction, getTableRows, getBalances } from "../RxEos";
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

const rawEvmSignedTransaction = (
  chainApiUrl: string,
  evmContractName: string,
  accountName: string,
  privateKey: string,
  ethereumTransaction: string
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
      sender: "",
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

const seedEvmAccountTransaction = (
  chainApiUrl: string,
  evmContractName: string,
  accountName: string,
  privateKey: string,
  amount: string
): Observable<any> => {
  console.log(amount);
  return pushTransaction(
    chainApiUrl,
    "transfer",
    "eosio.token",
    accountName,
    privateKey,
    {
      from: accountName,
      to: evmContractName,
      quantity: amount,
      memo: "seed EVM account",
    }
  );
};

const withdrawEvmBalanceTransaction = (
  chainApiUrl: string,
  evmContractName: string,
  accountName: string,
  privateKey: string,
  amount: string
): Observable<any> => {
  return pushTransaction(
    chainApiUrl,
    "withdraw",
    evmContractName,
    accountName,
    privateKey,
    {
      to: accountName,
      quantity: amount,
    }
  );
};

const getEosBalance = (
  chainApiUrl: string,
  accountName: string,
  symbol: string
): Observable<any> => {
  return getBalances(chainApiUrl, accountName, symbol);
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
  rawEvmSignedTransaction,
  rawEvmUnsignedTransaction,
  seedEvmAccountTransaction,
  withdrawEvmBalanceTransaction,
  getEosBalance,
  getEvmAccountIdentifier,
  getEvmCode,
  getEvmState,
};
