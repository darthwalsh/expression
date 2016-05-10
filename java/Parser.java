public class Parser {
  public static Expression Parse(String s) {
    Result r = Helper(s, 0);
    if(r.end != s.length())
      throw new UnsupportedOperationException("Expected EOF");
    return r.e;
  }

  private static Result Helper(String s, int begin) {
    int afterSpace;
    for(afterSpace = begin; afterSpace < s.length(); ++afterSpace)
      if(!Character.isWhitespace(s.charAt(afterSpace)))
        break;
    
    if(s.charAt(afterSpace) == '+') {
      Result first = Helper(s, afterSpace+1);
      Result second = Helper(s, first.end);

      return new Result(second.end, new Sum(first.e, second.e));
    } 
    
    int afterDigit;
    for(afterDigit = afterSpace; afterDigit < s.length(); ++afterDigit)
      if(afterDigit == afterSpace && s.charAt(afterDigit) == '-')
        continue;
      else if(!Character.isDigit(s.charAt(afterDigit)))
        break;

    String numberS = s.substring(afterSpace, afterDigit);
    if(numberS.length() > 0) {
      int n = Integer.parseInt(numberS);
      return new Result(afterDigit, new Constant(n));
    }
    
    throw new UnsupportedOperationException("Unknown at: " + s.substring(begin));
  }

  private static class Result {
    public int end;
    public Expression e;
    public Result(int end, Expression e) {
      this.end = end;
      this.e = e;
    }
  }

  public static void main(String[] args) {
    TestParse(0,  "0");
    TestParse(6,  "+ 2 4");
    TestParse(14, "+ 2 +5 7");
    TestParse(24, "++ 3 5+7 9");
    TestParse(6,  "+++0 1 2 3");
    
    TestParse(-4,  "-4");
    TestParse(2,   "+ -2 4");
    
    System.out.println("Tests Succeeded!");
  } 

  public static void TestParse(int expected, String s) {
    Expression e = Parse(s);
    Test.AreEqual(expected, e.Evaluate());
    Expression e2 = Parse(e.toString());
    Test.AreEqual(expected, e2.Evaluate());
  }
}
