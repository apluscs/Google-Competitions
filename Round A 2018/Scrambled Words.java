package kickstart;

import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class scrambleL {
  // public class Solution {
  public static int N, L;
  public static long A, B, C, D;
  public static String[] dict;
  public static char[] s;
  public static HashMap<List<Integer>, Integer> map;
  public static HashSet<Integer> lens;

  public static void main(String args[]) throws IOException {
    // Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    Scanner in = new Scanner(new FileReader("scramble.in"));
    // PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("scramble.out")));
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      L = in.nextInt();
      lens = new HashSet<>();   //all relevant lengths
      map = new HashMap<>();    //hash (in the form of List<Integer>), #words of this hash
      dict = new String[L];
      for (int i = 0; i < L; i++) {
        dict[i] = in.next();
        lens.add(dict[i].length());
        List<Integer> h = getHash(dict[i].toCharArray(), 0, dict[i].length() - 1);
        map.put(h, map.getOrDefault(h, 0) + 1);
      }
      // System.out.println(Arrays.toString(dict));
      char s1 = in.next().charAt(0);;
      char s2 = in.next().charAt(0);
      N = in.nextInt();
      s = new char[N + 1];
      A = in.nextLong();
      B = in.nextLong();
      C = in.nextLong();
      D = in.nextLong();
      genS(s1, s2);
      int res = 0;
      for (int l : lens) {
        res += slideWindow(l);
      }
      System.out.println("Case #" + t + ": " + res);
    }
    in.close();
  }

  public static int slideWindow(int len) {
    int res = 0;
    List<Integer> th = getHash(s, 0, len - 1);
    HashSet<List<Integer>> vis = new HashSet<>();
    for (int i = 1; i + len <= N + 1; i++) {
//      System.out.println(th);
      int prev = s[i - 1] - 'a';    //what you flicked off
      int curr = s[i + len - 1] - 'a';  //what you adopted
      th.set(prev + 2, th.get(prev + 2) - 1);//update th to sliding window
      th.set(curr + 2, th.get(curr + 2) + 1);
      th.set(0, s[i] - 'a');    
      th.set(1, curr);
      if (map.get(th) != null) {
        vis.add(new ArrayList(th)); //makes sure same hash code isn't counted twice
      }
    }
    for (List<Integer> v : vis) {   //for each recognized code
      res += map.get(v);    //#words of this code
    }
    return res;
  }

  public static List<Integer> getHash(char[] str, int st, int end) {
    List<Integer> res = new ArrayList<>(28);
    for (int i = 0; i < 28; i++)
      res.add(0);
    res.set(0, str[st] - 'a');  //char at front
    res.set(1, str[end] - 'a'); //char at end
    for (int i = st; i <= end; i++) {
      int c = str[i] - 'a'; //everything else is frequencies of all 26 chars
      res.set(c + 2, res.get(c + 2) + 1);
    }
    return res;
  }

  public static void genS(char s1, char s2) {
    long[] x = new long[N];
    x[0] = s1;
    x[1] = s2;
    s[0] = 'a'; //dumb char
    s[1] = s1;
    s[2] = s2;
    for (int i = 2; i < N; i++) {
      x[i] = (A * x[i - 1] + B * x[i - 2] + C) % D;
      s[i + 1] = (char) (x[i] % 26 + 'a');
    }
    // System.out.println(Arrays.toString(s));
    // System.out.println(new String(s));
  }
}
