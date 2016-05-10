public class Modulo extends BinaryOp {
  public Modulo(Expression newE1, Expression newE2) {
    super(newE1, newE2);
  }
  
  public int Evaluate() {
    return e1.Evaluate() % e2.Evaluate();
  }
  
  @Override
  public String Symbol() {
    return "%";
  }
}
