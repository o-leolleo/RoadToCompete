import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.math.BigInteger;

public class B
{
	public static void main(String [] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		int N;
		N = sc.nextInt();
		BigInteger ans = BigInteger.ONE, tmp;
		
		while (N-- != 0) {
			tmp = sc.nextBigInteger();
			ans = ans.multiply(tmp);
		}

		System.out.println(ans.toString(10));
	}
}

