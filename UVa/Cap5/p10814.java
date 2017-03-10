import java.util.Scanner;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p10814 {
	public static void main(String [] args) {
		Scanner sc  = new Scanner(new BufferedReader (new InputStreamReader(System.in)));
		int n = sc.nextInt();
		while (n-- > 0) {
			BigInteger p = sc.nextBigInteger();
			String ch = sc.next();
			BigInteger q = sc.nextBigInteger();
			System.out.println(p.divide(p.gcd(q)) + " / " + q.divide(p.gcd(q)));
		}
	}
}
