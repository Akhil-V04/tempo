import java.security.MessageDigest;
import java.util.Scanner;

public class MD5Example {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Text : ");
        String text = sc.nextLine();

        // Create MD5 MessageDigest Object
        MessageDigest md = MessageDigest.getInstance("MD5");

        // Generate Hash
        byte[] hashBytes = md.digest(text.getBytes());

        // Convert Bytes to Hexadecimal
        StringBuilder sb = new StringBuilder();
        for (byte b : hashBytes) {
            sb.append(String.format("%02x", b & 0xff));
        }

        // Display Hash Value
        System.out.println("MD5 Message Digest : " + sb.toString());
        sc.close();
    }
}
