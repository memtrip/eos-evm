import { applyMiddleware, createStore } from "redux";
import { createEpicMiddleware } from "redux-observable";
import { rootEpic } from "./rootEpic";
import { createRootReducer } from "./rootReducer";
import { composeWithDevTools } from "redux-devtools-extension";

const epicMiddleware = createEpicMiddleware();

const store = createStore(
  createRootReducer,
  composeWithDevTools(applyMiddleware(epicMiddleware))
);

epicMiddleware.run(rootEpic);

export { store };
