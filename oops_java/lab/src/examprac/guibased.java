package examprac;

import java.awt.*;

public class guibased extends Frame {
    guibased() {
        setLayout(null); // disable layout manager

        //Multiple-Selections [box-button]
        Checkbox cb1 = new Checkbox("Option A", false);
        Checkbox cb2 = new Checkbox("Option B", false);
        cb1.setBounds(50, 50, 100, 30); // position inside frame
        add(cb1);
        cb2.setBounds(150, 50, 100, 30); // position inside frame
        add(cb2);

        //single-selection [radio-button]
        CheckboxGroup chk = new CheckboxGroup();
        Checkbox opt1 = new Checkbox("Opt: 1", chk, false);
        Checkbox opt2 = new Checkbox("Opt: 2", chk, false);
        Checkbox opt3 = new Checkbox("Opt: 3", chk, false);

        opt1.setBounds(50, 100, 100, 30);
        opt2.setBounds(50, 150, 100, 30);
        opt3.setBounds(50, 200, 100, 30);

        add(opt1);
        add(opt2);
        add(opt3);

        //Dropdown
        Choice choice = new Choice();
        choice.setBounds(50, 280, 100, 30);
        choice.add("C");
        choice.add("Python");
        add(choice);

        setBounds(300, 400, 400, 400); // frame position + size
        setVisible(true);
    }

    public static void main(String[] args) {
        new guibased();
    }
}
