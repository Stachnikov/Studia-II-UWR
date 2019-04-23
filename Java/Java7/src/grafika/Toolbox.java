package grafika;

import javax.swing.*;

public class Toolbox extends JToolBar {
    JButton FileOp,FileSav,ZoomIN, ZoomOUT, ArrowUp, ArrowDown, ArrowLeft, ArrowRight,LColorChoose,RColorChoose;
    String[] list_of_Buttons_names = { "fop.png","fsav.png","zi.png", "zo.png", "au.png", "ad.png", "al.png", "ar.png"};

    Toolbox() {

        int i =0;
        FileOp = createButton(FileOp,i);
        i++;
        FileSav = createButton(FileSav,i);
        i++;
        ZoomIN = createButton(ZoomIN,i);
        i++;
        ZoomOUT = createButton(ZoomOUT,i);
        i++;
        ArrowUp = createButton(ArrowUp,i);
        i++;
        ArrowDown = createButton(ArrowDown,i);
        i++;
        ArrowLeft = createButton(ArrowLeft,i);
        i++;
        ArrowRight = createButton(ArrowRight,i);
    }

    JButton createButton(JButton button, int i){
        button = new JButton();
        button.setIcon(new ImageIcon("C:\\Users\\Dell\\Desktop\\Icons\\" + list_of_Buttons_names[i]));
        this.add(button);
        return button;
    }
}
