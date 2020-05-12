import React from "react";

import { HasChildren, Loadable } from "../shared/Props";

const FadeDiv = (props: HasChildren & Loadable) => {
  return (
    <>
      <style>{`
      @keyframes flickerAnimation {
        0%   { opacity:1; }
        50%  { opacity:0.45; }
        100% { opacity:1; }
      }
      @-o-keyframes flickerAnimation{
        0%   { opacity:1; }
        50%  { opacity:0.45; }
        100% { opacity:1; }
      }
      @-moz-keyframes flickerAnimation{
        0%   { opacity:1; }
        50%  { opacity:0.45; }
        100% { opacity:1; }
      }
      @-webkit-keyframes flickerAnimation{
        0%   { opacity:1; }
        50%  { opacity:0.45; }
        100% { opacity:1; }
      }
      .animate-flicker {
        -webkit-animation: flickerAnimation 2s infinite;
        -moz-animation: flickerAnimation 2s infinite;
        -o-animation: flickerAnimation 2s infinite;
        animation: flickerAnimation 2s infinite;
      }
    `}</style>
      <div className={props.isLoading ? "animate-flicker" : ""}>
        {props.children}
      </div>
    </>
  );
};

export { FadeDiv };
