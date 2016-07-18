interface Expression {
  evaluate() : number
}

class Constant implements Expression {
  n: number;

  constructor(n: number) {
    this.n = n;
  }

  evaluate() : number {
    return this.n;
  }
}

abstract class BinaryOp implements Expression {
  left: Expression;
  right: Expression;

  constructor(left: Expression, right: Expression) {
    this.left = left;
    this.right = right;
  }

  abstract op(x: number, y: number) : number;

  evaluate() : number {
    return this.op(this.left.evaluate(), this.right.evaluate());
  }
} 

class Sum extends BinaryOp {
  op(x: number, y: number) : number {
    return x + y;
  }
}

console.log(new Sum(new Constant(1), new Constant(2)).evaluate());
