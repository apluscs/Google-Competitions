package kickstart;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class mural {
  public static int T, N, P;
  public static int[] nums;

  public static void main(String[] args) throws IOException {
    try (BufferedReader in = new BufferedReader(new FileReader("muralL.in"));
        PrintWriter out = new PrintWriter(new File("mural.out"));) {
      T = Integer.parseInt(in.readLine());
      for (int t = 1; t <= T; t++) {
        N = Integer.parseInt(in.readLine());
        String s = in.readLine();
        nums = new int[5000000];
        for (int i = 0; i < N; i++)
          nums[i] = s.charAt(i) - '0';
        int result = solve();
        out.println("Case #" + t + ": " + result);
      }
    }
  }

  public static int solve() { // Intuition: with the right strategy, Thanh can select any
                              // consecutive sequence
    // of sections of len length (try it yourself!). so we just need to try all the windows
    int len = (N + 1) / 2; // rounds up
    int sum = 0;
    for (int i = 0; i < len; i++)
      sum += nums[i];
    int result = sum;
    for (int i = 1; i + len <= N; i++) {
      sum -= nums[i - 1]; // sliding window, subtracting the front and adding the next
      sum += nums[i + len - 1];
      result = Math.max(sum, result);
    }
    return result;
  }
}
