import java.io.*;
import java.net.*;
import java.util.Scanner;
public class client{
    public static void main(String[] args) {
        try{
            Scanner sc = new Scanner(System.in);
            Socket s=new Socket("localhost",6666);
            DataOutputStream dout=new DataOutputStream(s.getOutputStream());
            System.out.println("Establishing Connection...");
            System.out.println("Connection Established");
            System.out.println("Enter the message to be sent:");
            String str = sc.nextLine();
            dout.writeUTF(str);
            dout.flush();
            dout.close();
            System.out.println("Connection Closed");
            s.close();
            sc.close();
        }catch(Exception e){System.out.println(e);}
    }
}