package grafika;

import javax.swing.*;

public class MouseCoords extends JLabel {

    public MouseCoords(String s){
        super(s);
    }

    public void change(String coords){
        this.setText(coords);
    }
}
