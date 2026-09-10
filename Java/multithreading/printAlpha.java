public class printAlpha implements Runnable {
	char[] alpha = {'A', 'B', 'C', 'D', 'E'};
	@Override
	public void run() {
		for (int i = 0; i < 5; i++) {
			System.out.println(alpha[i]);
		}
	}
}
