import { connect } from "react-redux";
import { AppRootComponent } from "./AppRootComponent";
import { AppRootActionType } from "./model/AppRootActions";
import { RootState } from "../rootReducer";
import { Dispatch } from "react";
import { AnyAction } from "redux";
import { EmulatorState } from "javascript-terminal";

const mapStateToProps = (state: RootState) => {
  return {
    ...state.appRoot,
  };
};

const mapDispatchToProps = (dispatch: Dispatch<AnyAction>) => {
  return {
    loadHome: () => {
      dispatch({ type: AppRootActionType.FETCH_HOME });
    },
    inputChanged: (input: string) => {
      dispatch({ type: AppRootActionType.INPUT_CHANGED, input: input });
    },
    emulatorStateChanged: (emulatorState: EmulatorState) => {
      dispatch({
        type: AppRootActionType.EMULATOR_STATE_CHANGED,
        emulatorState: emulatorState,
      });
    },
    commandEosioApi: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_EOSIO_API,
        value: value,
      });
    },
    commandEvmContractName: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_EVM_CONTRACT_NAME,
        value: value,
      });
    },
    commandEosAccountName: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_EOS_ACCOUNT_NAME,
        value: value,
      });
    },
    commandEosPrivateKey: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_EOS_PRIVATE_KEY,
        value: value,
      });
    },
    commandEnv: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_ENV,
        value: value,
      });
    },
    commandCreate: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_CREATE,
        value: value,
      });
    },
    commandRawUnsigned: (sender: string, rawTransaction: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_RAW_UNSIGNED,
        sender: sender,
        rawTransaction: rawTransaction,
      });
    },
    commandRawSigned: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_RAW_SIGNED,
        value: value,
      });
    },
    commandAccount: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_ACCOUNT,
        value: value,
      });
    },
    commandCode: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_CODE,
        value: value,
      });
    },
    commandState: (value: string) => {
      dispatch({
        type: AppRootActionType.COMMAND_STATE,
        value: value,
      });
    },
    retryClicked: () => {},
  };
};

export default connect(mapStateToProps, mapDispatchToProps)(AppRootComponent);
