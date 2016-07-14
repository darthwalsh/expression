var math = require("./math.js");

function parseHelper(tokens, i) {
    var s = tokens[i];

    if ("-+*/^%".indexOf(s) >= 0) {
      var left = parseHelper(tokens, i + 1);
      var right = parseHelper(tokens, left.end);
      var func = math[s];
      if (func === undefined) { throw "op '" + s + "' is not defined"; }

      return { end: right.end, e: new func(left.e, right.e) };
    }

    return { end: i + 1, e: new math.Constant(+s) };
}

module.exports = {
  parse: function(s) {
    var regex = /-?\d+|[-+*/^%]/g;

    var tokens = [];
    var m;
    while (m = regex.exec(s)) {
      tokens.push(m[0]);
    }

    var result = parseHelper(tokens, 0);
    if (result.end !== tokens.length) {
      throw "enexpected EOF";
    }
    return result.e;
  }
};