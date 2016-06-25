public class Constant implements Expression {
  public int n;
  
  public Constant(int newN) {
    n = newN;
  }
  
  public int Evaluate() {
    return n;
  }
}