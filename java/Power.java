public class Power extends BinaryOp {
  public Power(Expression newE1, Expression newE2) {
    super(newE1, newE2);
  }
  
  public int Evaluate() {
    return (int)Math.pow(e1.Evaluate(), e2.Evaluate());
  }
}
