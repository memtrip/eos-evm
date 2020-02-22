// https://bitcointalk.org/index.php?topic=644919.msg7205689#msg7205689
// https://stackoverflow.com/a/53480175/832397
const bigInt = require("big-integer");

function pad_with_zeroes(number, length) {
  var retval = "" + number;
  while (retval.length < length) {
    retval = "0" + retval;
  }
  return retval;
}

/**
 * Point decompress secp256k1 curve
 * @param {string} Compressed representation in hex string
 * @return {string} Uncompressed representation in hex string
 */
function decompress(comp, pIdent) {
  var signY = new Number(comp[1]) - 2;
  var x = new bigInt(comp.substring(2), 16);
  // y mod p = +-(x^3 + 7)^((p+1)/4) mod p
  var y = x
    .modPow(3, prime)
    .add(7)
    .mod(prime)
    .modPow(pIdent, prime);
  // If the parity doesn't match it's the *other* root
  if (y.mod(2).toJSNumber() !== signY) {
    // y = prime - y
    y = prime.subtract(y);
  }
  return (
    pad_with_zeroes(x.toString(16), 64) + pad_with_zeroes(y.toString(16), 64)
  );
}

// Consts for secp256k1 curve. Adjust accordingly
// https://en.bitcoin.it/wiki/Secp256k1
const prime = new bigInt(
  "fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f",
  16
);

pIdent = prime.add(1).divide(4);

console.dir(decompress(process.argv[2], pIdent));

// 630f70ad9f6e943088a4677e9ccf132cb2ae8bafd4a1538b42cd78454e037730c6e09149f4bae8e136794e950a072368a0a3926083017d8b7b6c20d3f8a6f2e6
// 04876f5fdda1d03bef724e0634dfb18c530b67078ac8c2ee0be850201658ec83c4297c87de32981f6b8a83892a5d18a1fa034b0ed17193347aed2ca66fbe04e1e8
