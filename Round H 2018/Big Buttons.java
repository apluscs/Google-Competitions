import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class redblack {
  public static int T, N, P;
  public static List<char[]> invalid;
  public static tNode root;

  public static void main(String[] args) throws IOException {
    try (BufferedReader in = new BufferedReader(new FileReader("redblackL.in"));    //redblack for smaller input
        PrintWriter out = new PrintWriter(new File("redblack.out"));) {
      int T = Integer.parseInt(in.readLine());
      for (int t = 1; t <= T; t++) {
        StringTokenizer st = new StringTokenizer(in.readLine());
        N = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        root = new tNode();
        invalid = new ArrayList<>();
        for (int i = 0; i < P; i++) invalid.add(in.readLine().toCharArray());
        long result = solve();
        out.println("Case #" + t + ": " + result);
      }
    }
  }

  public static long solve() {
    for (char[] seq : invalid) {
      tNode curr = root;
      for (char c : seq) {
        if (curr.kids[c - 'A'] == null) 
          curr.kids[c - 'A'] = new tNode();
        curr = curr.kids[c - 'A'];
      }
      curr.end = true;
    return deduct();
  }

  public static long deduct() {
    Queue<tNode> toVis = new LinkedList<>();
    long total = (long) 1 << N; // change to long later
    toVis.add(root);
    int lev = N;
    while (!toVis.isEmpty()) {
      int size = toVis.size();  //so we reach everything on this level first
      for (int i = 0; i < size; i++) {
        tNode curr = toVis.poll();
        if (curr.end)   //highest level, so don't doubly subtract kids
          total -= (long) 1 << lev;
        else {
          if (curr.kids['B' - 'A'] != null) toVis.add(curr.kids['B' - 'A']);
          if (curr.kids['R' - 'A'] != null) toVis.add(curr.kids['R' - 'A']);
        }
      }
      lev--;
    }
    return total;
  }
  
  private static class tNode {
    boolean end = false;
    tNode[] kids = new tNode[25];
  }
}
