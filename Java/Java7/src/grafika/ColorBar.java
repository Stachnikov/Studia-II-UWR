package grafika;
import javax.swing.*;
import java.awt.*;

public class ColorBar extends Box {
    JButton ColorButton,ChooseColor;
    int[][] RGB = new int[][]{
            { 0, 255, 255},
            { 0, 0, 0},
            { 0, 0, 255},
            { 255, 0, 255},
            { 128, 128, 128},
            { 0, 128, 0},
            { 0, 255, 0},
            { 128, 0, 0},
            { 0, 0, 128},
            { 128, 128, 0},
            { 128, 0, 128},
            { 255, 0, 0},
            { 192, 192, 192},
            { 0, 128, 128},
            { 255, 255, 255},
            { 255, 255, 0},
    };

    ColorBar() {
        super(1);
        for (int i=0;i<16;i++) {
            ColorButton = new JButton();
            ColorButton.setBackground(new Color(RGB[i][0],RGB[i][1],RGB[i][2]));
            this.add(ColorButton);
        }
        ChooseColor = new JButton();
        ChooseColor.setIcon(new ImageIcon("C:\\Users\\Dell\\Desktop\\Icons\\color.png"));
        this.add(ChooseColor);
    }
}
