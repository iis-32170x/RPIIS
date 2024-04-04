package BooleanFounder;

import java.io.*;
import java.util.ArrayList;
import java.util.Objects;

public class BooleanFounder {
    private final ArrayList<String> set = new ArrayList<>();
    private final String inputFileName, outputFileName;

    public BooleanFounder(String inputFileName, String outputFileName) {
        this.inputFileName = inputFileName;
        this.outputFileName = outputFileName;
    }

    public void getOriginalSet() {
        String fileSet = null;


        try (BufferedReader bf = new BufferedReader(new FileReader(inputFileName))) {
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
        temp = temp.trim();
        set.add(temp);
        if (!set.contains("")) {
            set.add(0, "");
        }
    }

    public void findBoolean() {
        ArrayList<String> resultSet = new ArrayList<>();
        ArrayList<String> temp = new ArrayList<>();

        for (String subFromSet : set) {
            if (resultSet.isEmpty())
                resultSet.add(subFromSet);
            else {
                temp.clear();
                temp.addAll(resultSet);

                for (String subFromResult : temp) {
                    if (subFromResult.isEmpty() || subFromSet.isEmpty())
                        resultSet.add(resultSet.size() - 1, subFromSet.concat(subFromResult));
                    else
                        resultSet.add(resultSet.size() - 1, subFromSet.concat(", ").concat(subFromResult));
                }
            }
        }

        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(outputFileName))) {
            bufferedWriter.flush();
            bufferedWriter.write("{");

            for (String s : resultSet) {
                bufferedWriter.write("{");
                bufferedWriter.write(s);
                bufferedWriter.write("}");

                if (resultSet.get(resultSet.size() - 1).equals(s))
                    bufferedWriter.write("}");
                else
                    bufferedWriter.write(", ");
            }
        } catch (IOException ex) {
            ex.getMessage();
        }
    }
}
