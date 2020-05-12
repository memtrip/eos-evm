import { OutputFactory } from "javascript-terminal";
import { Record } from "immutable";

const commandMap = {
  EOS_API: {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be a valid chain api endpoint",
          }),
        };
      }

      return {
        output: OutputFactory.makeTextOutput("EOS_API(" + input + ")"),
      };
    },
    optDef: {},
  },
  EVM_CONTRACT_NAME: {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be a valid eos account name",
          }),
        };
      }

      return {
        output: OutputFactory.makeTextOutput(
          "EVM_CONTRACT_NAME(" + input + ")"
        ),
      };
    },
    optDef: {},
  },
  EOS_ACCOUNT_NAME: {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be a valid eos account name",
          }),
        };
      }

      return {
        output: OutputFactory.makeTextOutput("EOS_ACCOUNT_NAME(" + input + ")"),
      };
    },
    optDef: {},
  },
  EOS_PRIVATE_KEY: {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be a valid private key",
          }),
        };
      }

      return {
        output: OutputFactory.makeTextOutput("EOS_PRIVATE_KEY(" + input + ")"),
      };
    },
    optDef: {},
  },
  create: {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be an Ethereum address or an arbitrary string",
          }),
        };
      }
      return {
        output: OutputFactory.makeTextOutput("create(" + input + ")"),
      };
    },
    optDef: {},
  },
  "raw-signed": {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be an RLP encoded transaction as a hex string",
          }),
        };
      }
      return {
        output: OutputFactory.makeTextOutput(
          wrapOutput("raw-signed(" + input + ")")
        ),
      };
    },
    optDef: {},
  },
  "raw-unsigned": {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be an account identifier",
          }),
        };
      }
      return {
        output: OutputFactory.makeTextOutput(
          wrapOutput("raw-unsigned(" + input + ")")
        ),
      };
    },
    optDef: {},
  },
  account: {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be an eos account name",
          }),
        };
      }
      return {
        output: OutputFactory.makeTextOutput("account(" + input + ")"),
      };
    },
    optDef: {},
  },
  code: {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be an EVM account identifier",
          }),
        };
      }
      return {
        output: OutputFactory.makeTextOutput("code(" + input + ")"),
      };
    },
    optDef: {},
  },
  state: {
    function: (state: any, opts: any) => {
      const input = opts.join("");
      if (input === "") {
        return {
          output: OutputFactory.makeErrorOutput({
            source: "eos-evm",
            type: "arg1 must be an EVM account identifier",
          }),
        };
      }
      return {
        output: OutputFactory.makeTextOutput("state(" + input + ")"),
      };
    },
    optDef: {},
  },
  help: {
    function: (state: any, opts: any) => {
      return {
        output: OutputFactory.makeTextOutput(
          `
[command] [arg]

Environment commands:
  EOS_API             Set the nodeos HTTP Api endpoint
  EVM_CONTRACT_NAME   Set the account name containing the eos-evm contract
  EOS_ACCOUNT_NAME    Set the eos account name that will authorize transactions
  EOS_PRIVATE_KEY     Set the private key of the authorizing eos account
  
Commands
  create              Creates a new EVM account, (optional: link to an existing Ethereum address)
  raw-signed          Push a signed Ethereum transaction, the signature address must be linked to the
                      account identifier associated with the sender.
  raw-unsigned        Push an unsigned Ethereum transaction, 
                        arg1; accountIdentifier
                        arg2; rlp encoded transaction hex string
  account             Gets the EVM account identifier associated with the eos account name
  code                Gets the Ethereum contracts associated with the account identifier
  state               Gets the Ethereum state associated with the acccount identifier
          `
        ),
      };
    },
    optDef: {},
  },
};

const extractSummary = (label: String, value: Record<any>) => {
  const rx = new RegExp(new RegExp(label + "\\((.*)\\)"));
  const arr = rx.exec(value.get("content").replace(/(\r\n|\n|\r)/gm, ""));
  const summary = arr != null ? arr[1] : "";
  return summary.replace("\n", "");
};

const recordStartsWith = (key: String, record: Record<any>): boolean => {
  return record.get("content").startsWith(key);
};

const isOutputCommand = (record: Record<any> | undefined): boolean => {
  return record != null ? record.get("type") === "TEXT_OUTPUT" : false;
};

const wrapOutput = (value: string): string => {
  return value.replace(/(?!$|\n)([^\n]{70}(?!\n))/g, "$1\n");
};

export {
  commandMap,
  extractSummary,
  recordStartsWith,
  isOutputCommand,
  wrapOutput,
};
