import java.util.Scanner;
import java.math.BigInteger;

public class p11879 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			BigInteger N = sc.nextBigInteger(), d;

			if (N.equals(BigInteger.ZERO) == true)
				break;

			d = N.mod(BigInteger.TEN);
			d = d.multiply(BigInteger.valueOf(5));
			N = N.divide(BigInteger.TEN);

			if (N.subtract(d).mod(BigInteger.valueOf(17)) == BigInteger.ZERO)
				System.out.println("1");
			else
				System.out.println("0");
		}
	}
}
