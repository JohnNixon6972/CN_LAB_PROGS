import java.io.*;
import java.net.*;
public class client{
    public static void main(String[] args) throws IOException{
        DatagramSocket client = new DatagramSocket();
        InetAddress add = InetAddress.getByName("localhost");
        String msg = "Hello Server";
        byte[] buf = msg.getBytes();
        DatagramPacket packet = new DatagramPacket(buf, buf.length,add,1234);
        client.send(packet);
        client.close();

    }
}