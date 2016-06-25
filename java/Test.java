import java.io.*;

public class Test {
  public static void main(String[] args) throws Exception {
    try (BufferedReader reader = new BufferedReader(new FileReader("..\\test.txt"))) {
      String line = reader.readLine();

      while (line != null) {
        String e = line;
        int ans = Integer.parseInt(reader.readLine().substring(1));
        
        AreEqual(ans, Parser2.Parse(e).Evaluate());
        System.out.println(line + " = " + ans);

        reader.readLine();
        line = reader.readLine();
      }
    }
    
    System.out.println("Tests succeeded!");
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

