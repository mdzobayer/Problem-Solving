import java.awt.*;
import java.applet.*;

/*
<applet code="HelloApplet" width = 400 height = 400>
</applet>
*/
public class HelloApplet extends Applet {
    public void paint(Graphics g) {
        g.drawString("Hello, world!", 100, 100);
    }
}
