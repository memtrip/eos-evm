import { combineReducers } from "redux";

import { appRootReducer, AppRootState } from "./root/model/AppRootReducer";

export interface RootState {
  appRoot: AppRootState;
}

const createRootReducer = combineReducers<RootState>({
  appRoot: appRootReducer,
});

export { createRootReducer };
