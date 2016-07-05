import java.util.*;
import java.util.regex.*;

// Parses calculator input in polish notation
public class Parser2 {
  public static Expression Parse(String s) {
    ArrayList<String> tokens = Lex(s);
    Result r = ParseFrom(tokens, 0);
    if(r.end != tokens.size())
      throw new UnsupportedOperationException("Expected EOF");
    return r.e;
  }
  
  // Splits a string of calculator input into a list of tokens without whitespace
  // e.g. splits "+ 1 2" into ["+", "1", "2"]
  private static ArrayList<String> Lex(String s) {
    ArrayList<String> tokens = new ArrayList<String>();
    
    Pattern p = Pattern.compile("-?\\d+|[-+*/^%]");
    Matcher m = p.matcher(s);
    
    while(m.find())
      tokens.add(m.group());
      
    return tokens;
  }
  
  // Parses out an expression from a list of tokens
  // e.g. if tokens was ["*", "+", "1", "2", "3"] and startFrom was 1, 
  //      returns { end = 4, e = Sum { Constant { 1 }, Constant { 2 } } }
  private static Result ParseFrom(ArrayList<String> tokens, int startFrom) {
    String s = tokens.get(startFrom);
    
    if("-+*/^%".indexOf(s) >= 0) {
      Result first = ParseFrom(tokens, startFrom+1);
      Result second = ParseFrom(tokens, first.end);

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
      return new Result(startFrom+1, new Constant(n));
    } catch (NumberFormatException ex) { }
        
    throw new UnsupportedOperationException("Unknown at: " + s + " #" + startFrom);
  }

  // Helper class that stores the result of parsing: an Expression and how many tokens until the end
  private static class Result {
    public int end;
    public Expression e;
    public Result(int end, Expression e) {
      this.end = end;
      this.e = e;
    }
  }
}
