import { AppRootActionType } from "./AppRootActions";
import {
  asStarted,
  startLoading,
  asError,
  stopLoading,
  asSuccess,
} from "../../../shared/Actions";
import {
  EmulatorState,
  OutputFactory,
  CommandMapping,
  Outputs,
  defaultCommandMapping,
} from "javascript-terminal";
import { AnyAction } from "redux";
import { commandMap, wrapOutput } from "../../../commands/CommandMap";

export interface AppRootState {
  emulatorState: any;
  input: string;
  isLoading: boolean;
}

const initialState = (): AppRootState => {
  const defaultState = EmulatorState.create({
    commandMapping: CommandMapping.create({
      ...defaultCommandMapping,
      ...commandMap,
    }),
  });
  const defaultOutputs = defaultState.getOutputs();
  const newOutputs = Outputs.addRecord(
    defaultOutputs,
    OutputFactory.makeTextOutput(
      `
Welcome to the eos-evm REPL, type "help" for a list of supported commands.

`
    )
  );
  const emulatorState = defaultState.setOutputs(newOutputs);
  return {
    emulatorState: emulatorState,
    input: "",
    isLoading: false,
  };
};

const appRootReducer = (
  state: AppRootState = initialState(),
  action: AnyAction
): AppRootState => {
  switch (action.type) {
    case AppRootActionType.INPUT_CHANGED:
      return inputChanged(state, action);
    case AppRootActionType.EMULATOR_STATE_CHANGED:
      return emulateStateChanged(state, action);

    case asStarted(AppRootActionType.COMMAND_EOSIO_API):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_EOSIO_API):
      return stopLoading(state);
    case asSuccess(AppRootActionType.COMMAND_EOSIO_API):
      return stopLoading(state);

    case asStarted(AppRootActionType.COMMAND_EVM_CONTRACT_NAME):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_EVM_CONTRACT_NAME):
      return stopLoading(state);
    case asSuccess(AppRootActionType.COMMAND_EVM_CONTRACT_NAME):
      return stopLoading(state);

    case asStarted(AppRootActionType.COMMAND_EOS_ACCOUNT_NAME):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_EOS_ACCOUNT_NAME):
      return stopLoading(state);
    case asSuccess(AppRootActionType.COMMAND_EOS_ACCOUNT_NAME):
      return stopLoading(state);

    case asStarted(AppRootActionType.COMMAND_EOS_PRIVATE_KEY):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_EOS_PRIVATE_KEY):
      return stopLoading(state);
    case asSuccess(AppRootActionType.COMMAND_EOS_PRIVATE_KEY):
      return stopLoading(state);

    case asStarted(AppRootActionType.COMMAND_CREATE):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_CREATE):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_CREATE):
      return transactionSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_RAW):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_RAW):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_RAW):
      return transactionSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_ACCOUNT):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_ACCOUNT):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_ACCOUNT):
      return transactionSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_CODE):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_CODE):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_CODE):
      return transactionSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_STATE):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_STATE):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_STATE):
      return transactionSuccess(stopLoading(state), action);

    default:
      return state;
  }
};

const logError = (state: AppRootState, action: AnyAction) => {
  const defaultState = EmulatorState.create({
    commandMapping: CommandMapping.create({
      ...defaultCommandMapping,
      ...commandMap,
    }),
  });
  const defaultOutputs = state.emulatorState.getOutputs();
  const newOutputs = Outputs.addRecord(
    defaultOutputs,
    OutputFactory.makeErrorOutput({
      source: "eos-evm",
      type: wrapOutput(action.result.error.body),
    })
  );
  const emulatorState = defaultState.setOutputs(newOutputs);
  return { ...state, emulatorState: emulatorState };
};

const transactionSuccess = (state: AppRootState, action: AnyAction) => {
  const defaultState = EmulatorState.create({
    commandMapping: CommandMapping.create({
      ...defaultCommandMapping,
      ...commandMap,
    }),
  });
  const defaultOutputs = state.emulatorState.getOutputs();
  const newOutputs = Outputs.addRecord(
    defaultOutputs,
    OutputFactory.makeTextOutput("Transaction committed")
  );
  const emulatorState = defaultState.setOutputs(newOutputs);
  return { ...state, emulatorState: emulatorState };
};

const inputChanged = (state: AppRootState, action: AnyAction) => {
  return { ...state, input: action.input };
};

const emulateStateChanged = (state: AppRootState, action: AnyAction) => {
  return { ...state, emulatorState: action.emulatorState, input: "" };
};

export { appRootReducer };
