import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNext()) {
		 	int N = sc.nextInt(), i;
			BigInteger sum = BigInteger.ZERO, A = sc.nextBigInteger();
			for (i = 1; i <= N; ++i)
				sum = sum.add(A.pow(i).multiply(BigInteger.valueOf(i)));
			System.out.println(sum);
		}
	}
}
