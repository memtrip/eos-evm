import React from "react";
import { Provider, ReactReduxContext } from "react-redux";
import { store } from "./rootStore";
import AppRootConnect from "./root/AppRootConnect";

const AppWithState = () => (
  <Provider store={store} context={ReactReduxContext}>
    <AppRootConnect />
  </Provider>
);

export { AppWithState };
