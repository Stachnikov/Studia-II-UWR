package grafika;

import javafx.scene.control.Button;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


public class AppWindow extends JFrame {
    Container content=this.getContentPane();
    ButtonGroup colorgroup;
    JRadioButton R,L;
    Toolbox bar;
    ColorBar colorbar;
    DrawingPanel dpanel;
    ChooseFileListener chooser;
    SafeImageListener safer;
    MoveListener mover;
    MouseListener mouser;
    PaintListener painter;
    ZoomListener zoomer;
    ColorListener colorer;
    JScrollPane scroll;
    MouseCoords movelabel;
    int zoomLvl = 1;
    int Lcolor=Color.white.getRGB();
    int Rcolor=Color.black.getRGB();

    public AppWindow(){
        super();
        setSize(500,500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        content.setLayout(new BorderLayout());
        chooser = new ChooseFileListener();
        safer = new SafeImageListener();
        mover = new MoveListener();
        mouser = new MouseListener();
        painter = new PaintListener();
        zoomer = new ZoomListener();
        colorer = new ColorListener();
        bar = new Toolbox();
        colorbar = new ColorBar();
        movelabel = new MouseCoords(".......");
        dpanel = new DrawingPanel();
        scroll = new JScrollPane(dpanel,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        R = new JRadioButton("P");
        L = new JRadioButton("L");
        colorgroup = new ButtonGroup();

        L.setSelected(true);
        colorgroup.add(L);
        colorgroup.add(R);


        //Adding listeners to buttons
        bar.FileOp.addActionListener(chooser);
        bar.FileSav.addActionListener(safer);
        bar.ZoomIN.addActionListener(zoomer);
        bar.ZoomOUT.addActionListener(zoomer);
        bar.ArrowUp.addActionListener(mover);
        bar.ArrowDown.addActionListener(mover);
        bar.ArrowLeft.addActionListener(mover);
        bar.ArrowRight.addActionListener(mover);

        dpanel.l.addMouseMotionListener(mouser);
        dpanel.l.addMouseListener(painter);


        JPanel west =new JPanel();
        west.add(colorbar);
        west.add(L);
        west.add(R);
        for (Component x: colorbar.getComponents()) {
            JButton bx = (JButton) x;
            bx.addActionListener(colorer);
        }

        content.add(bar,BorderLayout.NORTH);
        content.add(scroll,BorderLayout.CENTER);
        content.add(movelabel,BorderLayout.SOUTH);
        content.add(west,BorderLayout.WEST);



        setVisible(true);
    }


    public class ChooseFileListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JFileChooser file = new JFileChooser();
            file.setDialogType(JFileChooser.OPEN_DIALOG);
            file.setDialogTitle("Choose file to draw on");
            file.setCurrentDirectory(new File(System.getProperty("user.dir")));
            //filter the files
            FileNameExtensionFilter filter = new FileNameExtensionFilter("*.Images", "jpg","gif","png");
            file.addChoosableFileFilter(filter);
            int result = file.showOpenDialog(null);
            //if the user click on save in Jfilechooser
            if(result == JFileChooser.APPROVE_OPTION){
                File selectedFile = file.getSelectedFile();
                String path = selectedFile.getAbsolutePath();
                try {
                    BufferedImage img = ImageIO.read(new File(path));
                    dpanel.setWH(img.getWidth(),img.getHeight());
                    dpanel.setImg(img);
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
            }
            //if the user click on save in Jfilechooser


            else if(result == JFileChooser.CANCEL_OPTION){
                System.out.println("No File Select");
            }
        }
    }

    public class SafeImageListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JFileChooser file = new JFileChooser();
            file.setDialogType(JFileChooser.SAVE_DIALOG);
            file.setDialogTitle("Save image");
            file.setCurrentDirectory(new File(System.getProperty("user.dir")));
            BufferedImage bi = new BufferedImage(
                    dpanel.l.getIcon().getIconWidth(),
                    dpanel.l.getIcon().getIconHeight(),
                    BufferedImage.TYPE_INT_RGB);
            Graphics g = bi.createGraphics();
            // paint the Icon to the BufferedImage.
            dpanel.l.getIcon().paintIcon(null, g, 0,0);
            g.setColor(Color.WHITE);
            g.dispose();
            int result = file.showSaveDialog(null);


            if(result == JFileChooser.APPROVE_OPTION){
                try {
                    ImageIO.write(bi,"png",file.getSelectedFile());
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
            }

        }
    }

    public class MoveListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            int hori = scroll.getHorizontalScrollBar().getValue();
            int verti = scroll.getVerticalScrollBar().getValue();
            if(e.getSource() == bar.ArrowUp){
                scroll.getVerticalScrollBar().setValue(verti - 100);
            }
            else if(e.getSource() == bar.ArrowDown){
                scroll.getVerticalScrollBar().setValue(verti + 100);
            }
            else if(e.getSource() == bar.ArrowLeft){
                scroll.getHorizontalScrollBar().setValue(hori - 100);
            }
            else if(e.getSource() == bar.ArrowRight){
                scroll.getHorizontalScrollBar().setValue(hori + 100);
            }
        }
    }

    public class MouseListener implements MouseMotionListener {

        @Override
        public void mouseDragged(MouseEvent e) {

        }

        @Override
        public void mouseMoved(MouseEvent e) {
            String coords = "x = " + e.getX() + "\ny = " + e.getY();
            movelabel.change(coords);
            repaint();
        }
    }

    public class PaintListener implements java.awt.event.MouseListener {

        @Override
        public void mouseClicked(MouseEvent e) {
            int color = Color.pink.getRGB();
            if(e.getButton() == MouseEvent.BUTTON1){
                 color = Lcolor;
            }
            else if(e.getButton() == MouseEvent.BUTTON3){
                color = Rcolor;
            }
            BufferedImage img = dpanel.getImg();

                int[] imgAsIntArray = new int[img.getWidth()*img.getHeight()];
            for (int i =0; i< imgAsIntArray.length;i++) {
                imgAsIntArray[i] = color;
            }
                img.setRGB(e.getX()-((zoomLvl+1)/2),e.getY()-((zoomLvl+1)/2),zoomLvl,zoomLvl,imgAsIntArray,0,img.getWidth());
            dpanel.setImg(img);
            repaint();
        }

        @Override
        public void mousePressed(MouseEvent e) {


        }

        @Override
        public void mouseReleased(MouseEvent e) {

        }

        @Override
        public void mouseEntered(MouseEvent e) {

        }

        @Override
        public void mouseExited(MouseEvent e) {

        }
    }

    public class ZoomListener implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getSource() == bar.ZoomIN){
                if(zoomLvl<=4 && zoomLvl>=1) {
                    zoomLvl *= 2;
                    dpanel.scale(zoomLvl);
                    System.out.println("zoom: " + zoomLvl);
                }
            }else if(e.getSource() == bar.ZoomOUT){
                if(zoomLvl>=2 &&zoomLvl<=8) {
                    zoomLvl /= 2;
                    dpanel.scale(zoomLvl);
                    System.out.println("zoom: " + zoomLvl);
                }
            }
        }
    }

    public class ColorListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            Color chosencolor;

            if(e.getSource() != colorbar.ChooseColor){
                JButton button = (JButton) e.getSource();
                if(L.isSelected())
                    Lcolor = button.getBackground().getRGB();
                else
                    Rcolor = button.getBackground().getRGB();
            }
            else {
                chosencolor = JColorChooser.showDialog(null, "Choose color", null);
                if (chosencolor == null) {
                    chosencolor = Color.white;
                } else {
                    if (L.isSelected()) {
                        Lcolor = chosencolor.getRGB();
                    } else if (R.isSelected()) {
                        Rcolor = chosencolor.getRGB();
                    }
                }
            }
        }
    }

}
