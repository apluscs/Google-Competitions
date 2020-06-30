// package kickstart;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

// public class training {
public class Solution {
  public static int N, P;
  public static Integer[] nums;
  public static int[] pref;

  public static void main(String args[]) throws IOException {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    // Scanner in = new Scanner(new FileReader("training.in"));
    // PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("scramble.out")));
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      N = in.nextInt();
      P = in.nextInt();
      nums = new Integer[N];
      for (int i = 0; i < N; i++) {
        nums[i] = in.nextInt();
      }
      Arrays.sort(nums, Collections.reverseOrder());
      genPrefix();
      int res = solve();
      System.out.println("Case #" + t + ": " + res);
    }
    in.close();
  }

  public static int solve() {
    int res = Integer.MAX_VALUE;
    for (int i = 0; i + P <= N; i++) {
      int def = pref[i + P - 1] - pref[i];
      int cost = (P - 1) * nums[i] - def;
      res = Math.min(res, cost);
    }
    return res;
  }

  public static void genPrefix() {
    pref = new int[N];
    pref[0] = nums[0];
    for (int i = 1; i < N; i++) {
      pref[i] = pref[i - 1] + nums[i];
    }
    // System.out.println(Arrays.toString(pref));
    // System.out.println(Arrays.toString(nums));
  }
}
