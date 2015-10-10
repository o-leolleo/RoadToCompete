import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
        static int MAX = 1000000;

        public static void main(String args[]) throws IOException {
                Scanner sc = new Scanner(System.in);

                int x, mf;

                BigInteger [] sum = new BigInteger[MAX];

                sum[0] = BigInteger.valueOf(1);
                sum[1] = BigInteger.valueOf(2);
                sum[2] = BigInteger.valueOf(3);

                for (int i = 3; i <= 100000; ++i) {
                        sum[i] = sum[i - 1].multiply(BigInteger.valueOf(2));
                        sum[i] = sum[i].subtract(sum[i - 3]);
                }

                while (true) {
                        x  = sc.nextInt();
                        mf = sc.nextInt();

                        if (x == 0 && mf == 0) break;

                        BigInteger ans = BigInteger.valueOf(x);
                        ans = ans.multiply(sum[mf]);

                        System.out.println(ans);
                }
        }
}
