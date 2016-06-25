import java.util.*;
import java.util.regex.*;
public class Parser2 {
  public static Expression Parse(String s) {
    ArrayList<String> lex = Lex(s);
    Result r = Helper(lex, 0);
    if(r.end != lex.size())
      throw new UnsupportedOperationException("Expected EOF");
    return r.e;
  }
  
  private static ArrayList<String> Lex(String s) {
    ArrayList<String> lex = new ArrayList<String>();
    
    Pattern p = Pattern.compile("-?\\d+|[-+*/^%]");
    Matcher m = p.matcher(s);
    
    while(m.find())
      lex.add(m.group());
      
    return lex;
  }
  
  private static Result Helper(ArrayList<String> lex, int i) {
    String s = lex.get(i);
    
    if("-+*/^%".indexOf(s) >= 0) {
      Result first = Helper(lex, i+1);
      Result second = Helper(lex, first.end);

      Expression e;
      char c = s.charAt(0);
      switch(c) {
          case '+': e = new Sum(first.e, second.e); break;
          case '-': e = new Difference(first.e, second.e); break;
          case '*': e = new Product(first.e, second.e); break;
          case '/': e = new Quotient(first.e, second.e); break;
          case '^': e = new Power(first.e, second.e); break;
          case '%': e = new Modulo(first.e, second.e); break;
          default: throw new UnsupportedOperationException("Unknown function: " + c);
      }

      return new Result(second.end, e);
    } 
    
    try {
      int n = Integer.parseInt(s);
      return new Result(i+1, new Constant(n));
    } catch (NumberFormatException ex) { }
        
    throw new UnsupportedOperationException("Unknown at: " + lex.get(i) + " #" + i);
  }

  private static class Result {
    public int end;
    public Expression e;
    public Result(int end, Expression e) {
      this.end = end;
      this.e = e;
    }
  }
}
