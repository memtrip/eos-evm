const EthereumTx = require("ethereumjs-tx").Transaction;

const values = JSON.parse(process.argv[2]);

var txParams;
if (values.length == 4) {
  txParams = {
    nonce: values[0],
    gasPrice: "0x09184e72a000",
    gasLimit: "0x132710",
    to: values[1],
    data: values[2],
    value: values[3],
  };
}

const tx = new EthereumTx(txParams);

function toHexString(byteArray) {
  return Array.prototype.map
    .call(byteArray, function (byte) {
      return ("0" + (byte & 0xff).toString(16)).slice(-2);
    })
    .join("");
}

console.dir(toHexString(tx.serialize()));
