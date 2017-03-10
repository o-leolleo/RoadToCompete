import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.math.BigInteger;

public class p10551 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		while(true) {
			int b; b = sc.nextInt();
			if (b == 0) break;
			BigInteger p = new BigInteger(sc.next(), b),
				   m = new BigInteger(sc.next(), b);

			System.out.println(p.mod(m).toString(b));
		}
	}
}
