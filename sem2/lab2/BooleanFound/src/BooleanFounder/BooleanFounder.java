package BooleanFounder;

import java.io.*;
import java.util.ArrayList;
import java.util.Objects;

public class BooleanFounder {
    private final ArrayList<String> set = new ArrayList<>();
    private final String fileName;

    public BooleanFounder(String fileName) {
        this.fileName = fileName;
    }

    public void getOriginalSet() {
        String fileSet = null;


        try (BufferedReader bf = new BufferedReader(new FileReader(fileName))) {
            fileSet = bf.readLine();
        } catch (IOException ex) {
            ex.getMessage();
        }

        String temp = "";
        boolean prot = false;
        for (int i = 1; i < Objects.requireNonNull(fileSet).length() - 1; i++) {

            if (fileSet.charAt(i) == '<' || fileSet.charAt(i) == '{')
                prot = true;

            if (fileSet.charAt(i) == '>' || fileSet.charAt(i) == '}')
                prot = false;

            if (prot) {
                temp += fileSet.charAt(i);
                continue;
            }

            if (fileSet.charAt(i) != ',') {
                temp += fileSet.charAt(i);

            } else {
                temp = temp.trim();
                set.add(temp);
                temp = "";
            }
        }
        set.add(temp);


    }
}
