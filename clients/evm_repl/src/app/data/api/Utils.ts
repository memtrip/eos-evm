const fromHexString = (hexString: string) => {
  if (!hexString) return new Uint8Array();
  var a = [];
  for (var i = 0, len = hexString.length; i < len; i += 2) {
    a.push(parseInt(hexString.substr(i, 2), 16));
  }
  return new Uint8Array(a);
};

export { fromHexString };
