/// <reference path="maths.ts" />

module Parser {
    function parseHelper(tokens: string[], i: number) : {
      end: number, 
      e : Maths.Expression 
    } {
      var s = tokens[i];

      if ("-+*/^%".indexOf(s) >= 0) {
        var left = parseHelper(tokens, i + 1);
        var right = parseHelper(tokens, left.end);

        var ops = { 
          '+': Maths.Sum,
          '-': Maths.Difference,
          '*': Maths.Product,
          '/': Maths.Quotient,
          '%': Maths.Modulo,
          '^': Maths.Power
        };
        var op = ops[s];
        if (op === undefined) { throw "op '" + s + "' is not defined"; }

        var e: Maths.Expression = new op(left.e, right.e);
        return { end: right.end, e };
      }

      return { end: i + 1, e: new Maths.Constant(+s) };
  }

  export function parse(s: string) : Maths.Expression {
      var regex = /-?\d+|[-+*/^%]/g;

      var tokens: string[] = [];
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
}