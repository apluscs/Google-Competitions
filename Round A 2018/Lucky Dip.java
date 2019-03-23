package kickstart;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class lucky {
//   public class Solution {
  public static int N, K;
  public static int[] vals;

  public static void main(String args[]) throws IOException {
//     Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    Scanner in = new Scanner(new FileReader("lucky.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lucky.out")));
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      N = in.nextInt();
      K = in.nextInt();
      vals = new int[N];
      for (int i = 0; i < N; i++)
        vals[i] = in.nextInt();
      Arrays.sort(vals);
      double res = solve();
      System.out.println("Case #" + t + ": " + String.format("%.6f", res));
    }
    in.close();
  }

  public static double solve() {
    double[] exp = new double[K + 1];   //exp[i]=expected value if i redips left
    exp[0] = sum(0, N)/N;
    for (int k = 1; k <= K; k++) {
      int ind = binSearch(exp[k - 1]);
      exp[k] = sum(ind, N) + ind * exp[k - 1];  //take everything above ind, redip if less
      exp[k] /= N;
    }
//    System.out.println(Arrays.toString(exp));
    return exp[K];
  }

  public static int binSearch(double c) {   //index of smallest val greater than c
    int low = 0, high = N - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (vals[mid] < c)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return low;
  }

  public static double sum(int a, int b) {
    double res = 0;
    for (int i = a; i < b; i++) 
      res += vals[i];
    return res;
  }

}
