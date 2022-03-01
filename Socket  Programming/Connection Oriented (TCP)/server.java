import java.io.*;
import java.net.*;
public class server {
    public static void main(String[] args) throws Exception {
        try{
            ServerSocket ss=new ServerSocket(6666);
            Socket s=ss.accept();//establishes connection
            DataInputStream dis=new DataInputStream(s.getInputStream());
            String  str=(String)dis.readUTF();
            System.out.println("message: "+str);
            System.out.println("Connection Closed");
            ss.close();
        }catch(Exception e){System.out.println(e);}
    }
}
