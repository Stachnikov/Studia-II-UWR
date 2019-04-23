package grafika;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class DrawingPanel extends JPanel {
    private BufferedImage img;
    private int orgheight;
    private int orgwidth;
    JLabel l;

    public DrawingPanel(){
        if(img == null) {
            try {
                img = ImageIO.read(new File("C:\\Users\\Dell\\Desktop\\3 SEMESTR\\Java\\Java7\\src\\grafika\\white.png"));
                orgwidth=img.getWidth();
                orgheight=img.getHeight();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        l = new JLabel(new ImageIcon(img));
        this.add(l);
    }

    public BufferedImage getImg(){
        return img;
    }

    public void setImg(BufferedImage newImg) {
        img = newImg;
        l.setIcon(new ImageIcon(img));
    }


    public void scale(int factor){
        BufferedImage before = img;
        BufferedImage after = new BufferedImage((orgwidth*factor), (orgheight*factor), BufferedImage.TYPE_INT_RGB);
        Graphics2D g = after.createGraphics();
        g.drawImage(before,0,0,orgwidth*factor,orgheight*factor,null);
        g.dispose();
        img = after;
        setImg(img);
        repaint();
    }

    public void setWH(int width,int height){
        orgheight=height;
        orgwidth=width;
    }
}
