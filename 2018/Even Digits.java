import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class evens {
//   public class Solution {
  public static int len;

  public static void main(String args[]) throws IOException {
//     Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    Scanner in = new Scanner(new FileReader("evens.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("evens.out")));
    int T = in.nextInt();
    for (int ks = 1; ks <= T; ks++) {
      len = 0;
      long a = in.nextLong();
      long res = solve(a);
      System.out.println("Case #" + ks + ": " + res);
    }
    in.close();
  }
  public static long solve(long num) {
    long temp = num;
    int[] dig = new int[18];    
    while (temp > 0) {  //parse into int[] of digits
      int f = (int) (temp % 10);
      dig[len++] = f;
      temp /= 10;
    }
    for (int j = len - 1; j != -1; j--) 
      if (dig[j] % 2 == 1) {    //first odd digit
        long down = findDown(dig.clone(), j);
        long up = findUp(dig, j);
//        System.out.println(num + ", up: " + up + ", down: " + down);
        return Math.min(up - num, num - down);
      }
    return 0;
  }

  public static long findUp(int[] dig, int j) { //closest beautiful number > num?
    dig[j]++;
    if (dig[j] == 10) { 
      dig[j] = 0;
      int i = j + 1;
      while (dig[i] == 8)   //8+intial 1 = 9, must flip to 10
        dig[i++] = 0;
      if (dig[i] % 2 == 0)  //first non-8; even + 1=odd, must increase again
        dig[i] += 2;
    }
    for (int i = 0; i < j; i++) //fill in right part with 0's
      dig[i] = 0;
    if (dig[len] != 0)
      len++;
    return toLong(dig);
  }

  public static long findDown(int[] dig, int j) {   //closest beautiful number < num?
    dig[j]--;   
    for (int i = 0; i < j; i++)
      dig[i] = 8;
    return toLong(dig);
  }
  public static long toLong(int[] dig){
    long res = 0;
    long pow = 1;
    for (int i = 0; i < len; i++) {
      res += dig[i] * pow;
      pow *= 10;
    }
    return res;
  }
}
