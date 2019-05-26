/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package whois;

/**
 *
 * @author Zobayer
 */

import java.net.*;
import java.io.*;

public class Whois {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        Socket sock = new Socket("whois.inernic.net", 43);
        InputStream input = sock.getInputStream();
        OutputStream output = sock.getOutputStream();
        
        String strng = "www.google.com\n";
        byte buffer[] = strng.getBytes();
        
        output.write(buffer);
        int ch;
        while((ch = input.read()) != -1) {
            System.out.print((char) ch);
        }
        sock.close();
    }
    
}
