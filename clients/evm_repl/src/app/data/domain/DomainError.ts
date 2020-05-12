export enum DomainErrorType {
  message = "message",
  networkError = "networkError",
  fatal = "fatal",
}

export interface DomainErrorValue {
  body?: string;
  action?: string;
}

export default class DomainError {
  constructor(
    readonly type: string,
    readonly body?: string,
    readonly action?: string
  ) {}

  static message(error: string, action?: string): Error {
    if (action != null) {
      return new Error(
        `{"type": "${DomainErrorType.message}", "body": "${error}", "action": "${action}"}`
      );
    } else {
      return new Error(
        `{"type": "${DomainErrorType.message}", "body": "${error}"}`
      );
    }
  }

  static networkError(): Error {
    return new Error(`{"type": "${DomainErrorType.networkError}"}`);
  }

  static fatal(): Error {
    return new Error(`{"type": "${DomainErrorType.fatal}}"}`);
  }

  static parse(error: Error): DomainError {
    return {
      type: "message",
      body: error.message,
    };
  }
}
