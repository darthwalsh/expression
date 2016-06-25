public abstract class BinaryOp implements Expression {
  public Expression e1;
  public Expression e2;
  
  public BinaryOp(Expression newE1, Expression newE2) {
    e1 = newE1;
    e2 = newE2;
  }
}