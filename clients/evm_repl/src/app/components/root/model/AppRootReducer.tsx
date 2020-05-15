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

    case asStarted(AppRootActionType.COMMAND_ENV):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_ENV):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_ENV):
      return envSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_CREATE):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_CREATE):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_CREATE):
      return transactionSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_RAW_UNSIGNED):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_RAW_UNSIGNED):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_RAW_UNSIGNED):
      return transactionSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_RAW_SIGNED):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_RAW_SIGNED):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_RAW_SIGNED):
      return transactionSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_SEED):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_SEED):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_SEED):
      return transactionSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_WITHDRAW):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_WITHDRAW):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_WITHDRAW):
      return transactionSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_BALANCE):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_BALANCE):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_BALANCE):
      return arraySuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_ACCOUNT):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_ACCOUNT):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_ACCOUNT):
      return jsonSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_CODE):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_CODE):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_CODE):
      return jsonSuccess(stopLoading(state), action);

    case asStarted(AppRootActionType.COMMAND_STATE):
      return startLoading(state);
    case asError(AppRootActionType.COMMAND_STATE):
      return logError(stopLoading(state), action);
    case asSuccess(AppRootActionType.COMMAND_STATE):
      return jsonSuccess(stopLoading(state), action);

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

const envSuccess = (state: AppRootState, action: AnyAction) => {
  const defaultState = EmulatorState.create({
    commandMapping: CommandMapping.create({
      ...defaultCommandMapping,
      ...commandMap,
    }),
  });
  const defaultOutputs = state.emulatorState.getOutputs();
  const newOutputs = Outputs.addRecord(
    defaultOutputs,
    OutputFactory.makeTextOutput(
      `EOS_API=` +
        action.result.entity.api +
        `
EOS_ACCOUNT_NAME=` +
        action.result.entity.eosAccountName +
        `
EOS_PRIVATE_KEY=` +
        action.result.entity.eosPrivateKey +
        `
EVM_CONTRACT_NAME=` +
        action.result.entity.evmContractName +
        ``
    )
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
    OutputFactory.makeTextOutput("(Transaction committed)")
  );
  const emulatorState = defaultState.setOutputs(newOutputs);
  return { ...state, emulatorState: emulatorState };
};

const jsonSuccess = (state: AppRootState, action: AnyAction) => {
  const rows = action.result.entity.rows.map((row: any) => {
    if ("code" in row) {
      console.dir(row.code);
      row.code = toHexString(Uint8Array.from(row.code));
    }
    return row;
  });

  return outputString(state, JSON.stringify(rows, undefined, 2));
};

const arraySuccess = (state: AppRootState, action: AnyAction) => {
  return outputString(
    state,
    JSON.stringify(action.result.entity, undefined, 2)
  );
};

const outputString = (state: AppRootState, json: string) => {
  const defaultState = EmulatorState.create({
    commandMapping: CommandMapping.create({
      ...defaultCommandMapping,
      ...commandMap,
    }),
  });
  const defaultOutputs = state.emulatorState.getOutputs();
  const newOutputs = Outputs.addRecord(
    defaultOutputs,
    OutputFactory.makeTextOutput(json)
  );
  const emulatorState = defaultState.setOutputs(newOutputs);
  return { ...state, emulatorState: emulatorState };
};

const toHexString = (bytes: any) =>
  bytes.reduce(
    (str: string, byte: any) => str + byte.toString(16).padStart(2, "0"),
    ""
  );

const inputChanged = (state: AppRootState, action: AnyAction) => {
  return { ...state, input: action.input };
};

const emulateStateChanged = (state: AppRootState, action: AnyAction) => {
  return { ...state, emulatorState: action.emulatorState, input: "" };
};

export { appRootReducer };
