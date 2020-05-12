import React from "react";
import { AppRootState } from "./model/AppRootReducer";
import { EmulatorState } from "javascript-terminal";
import { ReactTerminalStateless } from "react-terminal-component";
import {
  extractSummary,
  recordStartsWith,
  isOutputCommand,
} from "../../commands/CommandMap";
import { FadeDiv } from "../../uikit/FadeDiv";

export interface AppRootComponentProps extends AppRootState {
  loadHome: () => void;
  inputChanged: (input: string) => void;
  emulatorStateChanged: (state: EmulatorState) => void;
  commandEosioApi: (value: string) => void;
  commandEvmContractName: (value: string) => void;
  commandEosAccountName: (value: string) => void;
  commandEosPrivateKey: (value: string) => void;
  commandCreate: (value: String) => void;
  commandRaw: (value: String) => void;
  commandAccount: (value: String) => void;
  commandCode: (value: String) => void;
  commandState: (value: String) => void;
}

const AppRootComponent = (props: AppRootComponentProps) => {
  return (
    <fieldset disabled={props.isLoading}>
      <FadeDiv isLoading={props.isLoading}>
        <ReactTerminalStateless
          className="terminal"
          clickToFocus={true}
          emulatorState={props.emulatorState}
          inputStr={props.input}
          onInputChange={(input) => props.inputChanged(input)}
          onStateChange={(emulatorState) => {
            const [typeRecord] = emulatorState.getOutputs().slice(-1);
            const [stateRecord] = emulatorState.getOutputs().slice(-1);
            if (isOutputCommand(typeRecord)) {
              if (recordStartsWith("EOS_API", stateRecord)) {
                console.dir(stateRecord);
                props.commandEosioApi(extractSummary("EOS_API", stateRecord));
              } else if (recordStartsWith("EVM_CONTRACT_NAME", stateRecord)) {
                props.commandEvmContractName(
                  extractSummary("EVM_CONTRACT_NAME", stateRecord)
                );
              } else if (recordStartsWith("EOS_ACCOUNT_NAME", stateRecord)) {
                props.commandEosAccountName(
                  extractSummary("EOS_ACCOUNT_NAME", stateRecord)
                );
              } else if (recordStartsWith("EOS_PRIVATE_KEY", stateRecord)) {
                props.commandEosPrivateKey(
                  extractSummary("EOS_PRIVATE_KEY", stateRecord)
                );
              } else if (recordStartsWith("create", stateRecord)) {
                props.commandCreate(extractSummary("create", stateRecord));
              } else if (recordStartsWith("raw-signed", stateRecord)) {
                props.commandRaw(extractSummary("raw-signed", stateRecord));
              } else if (recordStartsWith("account", stateRecord)) {
                props.commandAccount(extractSummary("account", stateRecord));
              } else if (recordStartsWith("code", stateRecord)) {
                props.commandCode(extractSummary("code", stateRecord));
              } else if (recordStartsWith("state", stateRecord)) {
                props.commandState(extractSummary("state", stateRecord));
              }
            }
            props.emulatorStateChanged(emulatorState);
          }}
          promptSymbol={"$"}
          disabled={true}
          theme={{
            background: "#1b1b1b",
            promptSymbolColor: "#ec8664",
            commandColor: "#fcfcfc",
            outputColor: "#3DDED9",
            errorOutputColor: "#FB4B4E",
            fontSize: "1.1rem",
            spacing: "1%",
            fontFamily: "monospace",
            height: "80vh",
            width: "850px",
          }}
        />
      </FadeDiv>
    </fieldset>
  );
};

export { AppRootComponent };
