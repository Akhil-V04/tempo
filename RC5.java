import java.util.Scanner;

public class RC5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Plain Text (8 characters): ");
        String text = sc.nextLine();
        System.out.print("Enter Key: ");
        String key = sc.nextLine();

        int[] S = new int[26];
        S[0] = 0xB7E15163;

        for (int i = 1; i < 26; i++)
            S[i] = S[i - 1] + 0x9E3779B9;

        int A = 0, B = 0;
        for (int i = 0; i < 4; i++) {
            A = (A << 8) | text.charAt(i);
            B = (B << 8) | text.charAt(i + 4);
        }

        A += S[0];
        B += S[1];

        for (int i = 1; i <= 12; i++) {
            A = Integer.rotateLeft(A ^ B, B & 31) + S[2 * i];
            B = Integer.rotateLeft(B ^ A, A & 31) + S[2 * i + 1];
        }

        System.out.printf("Encrypted Text: %08X%08X%n", A, B);
        sc.close();
    }
}
