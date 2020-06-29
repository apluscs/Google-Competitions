//package kickstart;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

//public class guess {
   public class Solution {
  public static int N, A,B;

  public static void main(String args[]) throws IOException {
     Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
//    Scanner in = new Scanner(new FileReader("guess.in"));
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      A=in.nextInt()+1;
      B = in.nextInt();
      in.nextInt();
      solve(in);
    }
    in.close();
  }
  public static void solve(Scanner in) { // index of smallest val greater than c
    while(true){
      int res = (A+B)/2;
      System.out.println(res);
      String f=in.next();
      if(f.equals("TOO_SMALL")) A=res+1;
      else if(f.equals("TOO_BIG")) B=res-1;
      else return;
    }
  }


}