import java.util.Scanner;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p389 {
	public static void main(String []args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		while (sc.hasNext()) {
			String from = sc.next();
			int b = sc.nextInt(), to = sc.nextInt();
			BigInteger a = new BigInteger(from, b);

			if (a.toString(to).length() > 7)
				System.out.format("%7s\n", "ERROR");
			else
				System.out.format("%7s\n", a.toString(to).toUpperCase());
		}
	}
}
