import React from "react";

export interface HasChildren {
  children?: React.ReactNode | React.ReactNode[];
}

export interface Clickable {
  onClick: (event: any) => void;
}

export interface Disablable {
  disabled?: boolean;
}

export interface Loadable {
  isLoading: boolean;
}
