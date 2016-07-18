module Maths {
  export interface Expression {
    evaluate() : number
  }

  export class Constant implements Expression {
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

  export class Sum extends BinaryOp {
    op(x: number, y: number) : number {
      return x + y;
    }
  }

  export class Difference extends BinaryOp {
    op(x: number, y: number) : number {
      return x - y;
    }
  }

  export class Product extends BinaryOp {
    op(x: number, y: number) : number {
      return x * y;
    }
  }

  export class Quotient extends BinaryOp {
    op(x: number, y: number) : number {
      return Math.floor(x / y);
    }
  }

  export class Modulo extends BinaryOp {
    op(x: number, y: number) : number {
      return x % y;
    }
  }

  export class Power extends BinaryOp {
    op(x: number, y: number) : number {
      return Math.pow(x, y);
    }
  }
}