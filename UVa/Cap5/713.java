import java.util.Scanner;
import java.math.BigInteger;

public static class Main {
	public static void Main(String [] args) {
		Scanner sc = new Scanner(System.in);
		int N; N = sc.nextInt();
		while (N-- != 0) {
			String a = sc.nextLine(), b = sc.nextLine();
			BigInteger A = new BigInteger(StringBuffer(a).reverse().toString()),
				   B = new BigInteger(StringBuffer(b).reverse().toString());
			a = A.add(B).toString();
			System.out.println(a);
		}
	}
}
