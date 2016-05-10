public class Test {
  public static void main(String[] args) {
    TestConstant();
    TestSum();
    
    System.out.println("Tests succeeded!");
  }
  
  static void TestConstant() {
    Constant c = new Constant(5);
    
    AreEqual(5, c.n);
    AreEqual(5, c.Evaluate());
  }
  
  static void TestSum() {
    Constant c4 = new Constant(4);
    Constant c5 = new Constant(5);

    Sum s = new Sum(c4, c5);
    
    AreEqual(c4, s.e1);
    AreEqual(c5, s.e2);
    AreEqual(9, s.Evaluate());
    
    Sum s2 = new Sum(s, c5);
    
    AreEqual(14, s2.Evaluate());
  }
  
  public static void AreEqual(Object expected, Object actual) {
    boolean failed = false;
    if(expected == null)
      failed = actual != null;
    else
      failed = !expected.equals(actual);
    if(failed)
      System.out.println("AreEqual failed! expected: " + expected + " actual: " + actual);
  }
}

