import java.awt.*;
import java.applet.*;

/*
<applet code = "ImageApplet" width = 690 height = 500>
</applet>
*/

public class ImageApplet extends Applet {
    private Image anImage;

    public void init() {
        anImage = Toolkit.getDefaultToolkit().getImage("java.jpg");
    }

    public void paint(Graphics g) {
        g.setFont(new Font("TimesRoman", Font.PLAIN, 25));
        g.drawString("Bijon neh Coffee khaa", 250, 60);
        g.drawImage(anImage, 50, 70, this);
        showStatus("image loaded");
    }
}
