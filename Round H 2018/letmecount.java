package kickstart;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

// https://github.com/serhatgiydiren/google_kickstart/blob/master/let_me_count_the_ways.cpp
public class letmecount {
  public static long[] fact = new long[200001];
  public static long[] pow2 = new long[200001];
  public static final int MOD = 1000000007;// 1000000007;
  public static BigInteger MOB = new BigInteger("1000000007");
  public static int T, N, M;

  public static void main(String[] args) throws IOException {
    try (Scanner in = new Scanner(new FileReader("letmecountL.in"));
        PrintWriter out = new PrintWriter(new File("letmecount.out"));) {
      genFact();
      genPow2();
      T = in.nextInt();
      for (int t = 1; t <= T; t++) {
        N = in.nextInt();
        M = in.nextInt();
        long result = solve();
        System.out.println("Case #" + t + ": " + result);
      }
    }
  }

  public static long solve() {
    long result = 0;
    int mul = 1;
    for (int i = 0; i <= M; i++) {
      long a = (ch(2 * N - i, i) * fact[i]) % MOD; // num ways to seat i couples
      // given each arrangement, how many ways to arrange couples within them?
      long b = fact[2 * N - 2 * i]; // num ways to arrange everyone else
      long c = pow2[i]; // each pair can be flipped to double the result
      // System.out.println(a + " " + b + " " + c);
      long res = (a * b) % MOD;
      res = (res * c) % MOD;
      res = (res * ch(M, i)) % MOD;
      result += res * mul;
      mul *= -1;
      result = (result + MOD) % MOD;
    }
    return result;
  }

  public static long modInv(long a) {
    BigInteger b = new BigInteger(a + "");
    BigInteger res = b.modInverse(MOB);
    return res.longValue();
  }

  public static long ch(int n, int r) {
    if(r==0) return 1;
    long res = (fact[n] * modInv(fact[n - r])) % MOD; // division with modulo's aint' so easy!
    res = (res * modInv(fact[r])) % MOD;
    return res;
  }
  public static void genFact() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 200000; i++)
      fact[i] = ((long) fact[i - 1] * i) % MOD;
    // System.out.println(Arrays.toString(fact));
  }

  public static void genPow2() {
    pow2[0] = 1;
    for (int i = 1; i <= 200000; i++)
      pow2[i] = ((long) pow2[i - 1] << 1) % MOD;
    // System.out.println(Arrays.toString(pow2));
  }
}
