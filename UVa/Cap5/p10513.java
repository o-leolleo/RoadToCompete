import java.util.Scanner;
import java.math.BigInteger;

public class p10513 {
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
	 	int N = sc.nextInt(), i;
		BigInteger sum = BigInteger.ZERO, A = sc.nextInt();
		for (i = 1; i <= N; ++i)
			sum = sum.add(A.pow(i).multiply(i));
		System.out.println(sum);
	}
}
