import { AnyAction } from "redux";
import DomainResponse, {
  DomainResponseType,
} from "../data/domain/DomainResponse";
import { Observable, of } from "rxjs";

export enum ErrorType {
  INLINE,
  MODAL,
}

const startedAction = (actionType: string): AnyAction => {
  return {
    type: asStarted(actionType),
  };
};

function responseAction<T>(actionType: string, response: DomainResponse<T>) {
  switch (response.type) {
    case DomainResponseType.success:
      return {
        type: asSuccess(actionType),
        result: response.value(),
      };
    case DomainResponseType.error:
      return {
        type: asError(actionType),
        result: response.value(),
      };
  }
}

const asStarted = (prefix: string) => {
  return `${prefix.toUpperCase()}_STARTED`;
};

const asSuccess = (prefix: string) => {
  return `${prefix.toUpperCase()}_SUCCESS`;
};

const asError = (prefix: string) => {
  return `${prefix.toUpperCase()}_ERROR`;
};

const startLoading = (state: any) => {
  return { ...state, isLoading: true };
};

const stopLoading = (state: any) => {
  return { ...state, isLoading: false };
};

const genericErrorAction = (actionType: string): Observable<AnyAction> => {
  return of({
    type: asError(actionType),
    result: {
      error: {
        body: "Please check your internet connection and try again.",
      },
    },
  });
};

export {
  startedAction,
  responseAction,
  asStarted,
  asSuccess,
  asError,
  startLoading,
  stopLoading,
  genericErrorAction,
};
