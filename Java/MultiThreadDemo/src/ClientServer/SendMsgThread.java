/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ClientServer;

/**
 * 
 * @author Zobayer
 */
import java.net.*;
import java.io.*;


public class SendMsgThread implements Runnable {
    String name, line;
    Thread t;
    ServerSocket server;
    Socket sock;
    BufferedReader input;
    PrintStream output;

    
    SendMsgThread(String s) {
        name = s;
        if (s.equals("client")) {
            try{
                sock = new Socket("127.0.0.1", 10007);
            }
            catch(Exception e) {}
        }
        else {
            try{
                server = new ServerSocket(10007);
                System.out.println("Before Accept");
                sock = server.accept();
                System.out.println("After Accept");
            }
            catch(Exception e) {}
        }
        try {
            input = new BufferedReader( new InputStreamReader(System.in));
            output = new PrintStream(sock.getOutputStream());
        } catch (Exception ex) {
            //Logger.getLogger(ReceiveMsgThread.class.getName()).log(Level.SEVERE, null, ex);
        }
        t = new Thread(this, name);
        t.start();
    }
    
    public void run () {
        while(true) {
             System.out.println("Waiting for input");
            try {
                line = input.readLine();
            } catch (IOException ex) {
                //Logger.getLogger(ReceiveMsgThread.class.getName()).log(Level.SEVERE, null, ex);
            }
            if(line.equals("bye")) {
                output.println(line);
                break;
            }
            else {
                output.println(name + ": " + line);
                System.out.println(name + ": " + line);
            }
        }
        try {
            server.close();
            sock.close();
            input.close();
            output.close();
        }
        catch(Exception e) {};
    }
}