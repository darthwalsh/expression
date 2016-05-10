public class BinaryOp implements Expression {
  public Expression e1;
  public Expression e2;
  
  public BinaryOp(Expression newE1, Expression newE2) {
    e1 = newE1;
    e2 = newE2;
  }
  
  public int Evaluate() {
    throw new UnsupportedOperationException("Can't evaluate a BinaryOp!");
  }
  
  public String Symbol() {
    throw new UnsupportedOperationException("Can't find the symbol of a BinaryOp!");
  }
  
  @Override
  public String toString() {
    return Symbol() + " " + e1.toString() + " " + e2.toString();
  }
}