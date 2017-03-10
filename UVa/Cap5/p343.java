import java.util.Scanner;
import java.math.BigInteger;
import java.lang.Character;

public class p343 {
	public static void main(String []args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String x = sc.next(),
			       y = sc.next();

			int a, b; a = b = 1;

			for (a = 2; a <= 36; ++a) {
				for (b = 2; b <= 36; ++b) {
					BigInteger m, n;

					try {
						m = new BigInteger(x, a);
					} catch (NumberFormatException e) {
						m = null;
					}

					try {
						n = new BigInteger(y, b);
					} catch (NumberFormatException e) {
						n = null;
					}

					if (n != null && m != null && m.equals(n) == true) break;
				}
				if (b <= 36) break;
			}

			if (a > 36) System.out.println(x + " is not equal to " + y + " in any base 2..36");
			else System.out.println(x + " (base " + a + ") = " + y + " (base " + b + ")");
		}
	}
}
