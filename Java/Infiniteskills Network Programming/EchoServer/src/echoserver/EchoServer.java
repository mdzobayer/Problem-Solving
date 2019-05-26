/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package echoserver;

/**
 *
 * @author Zobayer
 */
import java.net.*;
import java.io.*;

public class EchoServer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        ServerSocket serverSock = null;
        
        try{
            serverSock = new ServerSocket(10007);
        }
        catch(IOException ie){
            System.out.println("Can't listen on 10007");
            System.exit(1);
        }
        
        Socket clientSock = null;
        
        System.out.println("Listening for connection....");
        try {
            clientSock = serverSock.accept();
        }
        catch(IOException ie) {
            System.out.println("Accept failed.");
            System.exit(1);
        }
        System.out.println("Connection Successful");
        System.out.println("Listing for input.......");
        
        PrintWriter output = new PrintWriter(clientSock.getOutputStream(), true);
        
        BufferedReader input = new BufferedReader(new InputStreamReader(
                                    clientSock.getInputStream()));
        String inputLine;
        while((inputLine = input.readLine()) != null) {
            System.out.println("Server: " + inputLine);
            output.println(inputLine);
            if (inputLine.equals("Bye")) {
                break;
            }
        }
        output.close();
        input.close();
        clientSock.close();
        serverSock.close();
    }
    
}




