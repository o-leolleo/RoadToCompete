import java.util.Scanner;
import java.math.BigInteger;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class p11821 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n = sc.nextInt();
		while (n-- > 0) {
			BigInteger sum_a = BigInteger.ZERO, sum_b = BigInteger.ZERO;
			int max = -1;
			while (true) {
				String in = sc.next();
				if (in.equals("0") == true) break;
				String [] d = in.split(".");
				BigInteger a = new BigInteger(d[0]);
				if (d.lenght == 2) {
					BigInteger b = new BigInteger(d[1]);
					sum_b = sum_b.add(b);
					if (b.toString().lenght > max)
						max = b.toString().lenght;
				}
				sum_a = sum_a.add(a);
			}
			
		}
	}
}
