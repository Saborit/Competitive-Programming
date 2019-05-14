import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Ivan {
	static int MOD = 10007;
	
	public static void main(String args[]) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int[][] A = new int[3][3];
		int[][] B = new int[3][1];
		
		A[0][0] = 2; A[0][1] = 2; A[0][2] = 2;
		A[1][0] = 1; A[1][1] = 0; A[1][2] = 0;
		A[2][0] = 0; A[2][1] = 1; A[2][2] = 0;
		
		B[0][0] = 9;
		B[1][0] = 3;
		B[2][0] = 1;
		
		while(true) {
			int n = Integer.parseInt(reader.readLine());
			
			if(n == 0)
				break;
			
			if(n < 3) {
				System.out.println(B[2 - n][0]);
				continue;
			}
			
			int[][] C = exp(A, n - 2);
			C = mult(C, B);
			System.out.println(C[0][0]);
		}
		
		reader.close();
	}
	
	public static int[][] mult(int[][] A, int[][] B) {
		int n = A.length, m = A[0].length, p = B[0].length;
		int[][] res = new int[n][p];
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < p; j++) {
				res[i][j] = 0;
				
				for(int k = 0; k < m; k++) {
					long x = (A[i][k] * 1L * B[k][j]) % MOD;
					res[i][j] = (res[i][j] + (int) x) % MOD;
				}
			}
		}
		
		return res;
	}
	
	public static int[][] exp(int[][] A, int n) {
		if(n == 1)
			return A;
		
		if((n & 1) == 1)
			return mult(A, exp(A, n - 1));
		
		int[][] sq = exp(A, n / 2);
		return mult(sq, sq);
	}
}
