var RLP = require("rlp");
var EC = require("elliptic").ec;
const ec = new EC("secp256k1");

function generateKeyPair(ec) {
  return ec.genKeyPair();
}

function signHex(keypair, hex) {
  const UNCOMPRESSED_PUBKEY_HEADER = 37;
  const signature = keypair.sign(hex);
  return {
    v: UNCOMPRESSED_PUBKEY_HEADER + signature.recoveryParam,
    r: signature.r.toString(16),
    s: signature.s.toString(16)
  };
}

function signMessageHash(keypair, message) {
  var CryptoJS = require("crypto-js");
  var hash = CryptoJS.SHA3(message, { outputLength: 256 });
  return signHex(keypair, hash.toString(CryptoJS.enc.Hex));
}

function bufferToHex(buffer) {
  var s = "",
    h = "0123456789abcdef";
  new Uint8Array(buffer).forEach(v => {
    s += h[v >> 4] + h[v & 15];
  });
  return s;
}

var keypair = generateKeyPair(ec);
var signedMessage = signMessageHash(keypair, process.argv[2]);
var publicKeyHex = keypair.getPublic().encode("hex");

var params = [
  "0x00",
  "0x1000",
  "0x2700",
  "0x0000000000000000000000000000000000000000",
  "0x00",
  "0x7f7465737432000000000000000000000000000000000000000000000000000000600057",
  signedMessage.v,
  "0x" + signedMessage.r,
  "0x" + signedMessage.s
];

console.log("PUBLIC_KEY");
console.dir("0x" + publicKeyHex.substr(publicKeyHex.length - 40));

console.log("TRANSACTION");
console.dir("0x" + bufferToHex(RLP.encode(params)));
