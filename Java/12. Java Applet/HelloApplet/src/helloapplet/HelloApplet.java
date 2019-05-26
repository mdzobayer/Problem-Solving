/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloapplet;

import java.awt.*;
import java.applet.*;

/*
<applet code="HelloApplet" width = 400 height = 400>
</applet>
 */
public class HelloApplet extends Applet{

    public void paint(Graphics g) {
        // TODO code application logic here
        g.drawString("Hello, world!", 100, 100);
    }
}
