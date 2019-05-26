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


public class ReceiveMsgThread implements Runnable {
    String name, line;
    Thread t;
    ServerSocket server;
    Socket sock;
    BufferedReader input;
    //BufferedReader output;
    
    ReceiveMsgThread(String s) {
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
                //System.out.println("Before Accept");
                sock = server.accept();
                //System.out.println("After Accept");
            }
            catch(Exception e) {System.out.println("Problem is here 2");}
        }
        try {
            input = new BufferedReader( new InputStreamReader(sock.getInputStream()));
            //System.out.println("After Buffer Declare");
        } catch (IOException ex) {
            //Logger.getLogger(ReceiveMsgThread.class.getName()).log(Level.SEVERE, null, ex);
            //System.out.println("Problem is here");
        }
        t = new Thread(this, name);
        t.start();
    }
    
    public void run () {
        while(true) {
            try {
                //System.out.println("Waiting for msg");
                line = input.readLine();
            } catch (IOException ex) {
                //Logger.getLogger(ReceiveMsgThread.class.getName()).log(Level.SEVERE, null, ex);
            }
            if(line.equals("bye")) {
                break;
            }
            else {
                System.out.println(line);
            }
        }
        try {
            server.close();
            sock.close();
            input.close();
            //output.close();
        }
        catch(Exception e) {};
    }
}
