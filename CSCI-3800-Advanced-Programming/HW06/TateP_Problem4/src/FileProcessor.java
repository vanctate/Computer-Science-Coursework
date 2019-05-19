/*
    Patrick Tate
    CSCI 3800 HW6 Problem 4
 */
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Properties;
import java.util.concurrent.Callable;

public class FileProcessor implements Callable {

    String fileName = "";

    public FileProcessor(String fileName){
        this.fileName = fileName;
    }

    @Override
    public HashMap<String, Long> call() throws FileNotFoundException, IOException {

        HashMap<String, Long> wordCountMap = new HashMap<String, Long> ();

        File inFile = new File(this.fileName);

        // object to read through shakespeare text file
        BufferedReader br = new BufferedReader(new FileReader(inFile));

        String line;

        while ((line = br.readLine()) != null) {
            ArrayList<String> words = new ArrayList<>();
            String[] wordArray = line.split(" ");

            for(String word : wordArray){
                if(word.contains(".")) {
                    word = word.replace(".", "");
                }
                if(word.contains(",")) {
                    word = word.replace(",", "");
                }
                if(word.contains("?")) {
                    word = word.replace("?", "");
                }
                if(word.contains(";")) {
                    word = word.replace(";", "");
                }
                if(word.contains(":")) {
                    word = word.replace(":", "");
                }
                if(word.contains("'")) {
                    word = word.replace("'", "");
                }
                if(word.contains("\"")) {
                    word = word.replace("\"", "");
                }
                if(word.contains(" ")) {
                    word = word.replace(" ", "");
                }
                if(word.contains("\t")) {
                    word = word.replace("\t", "");
                }
                if(!word.equals("")) {
                    words.add(word);
                }
            }
            long one = 1;
            for(String w : words){
                if (!wordCountMap.containsKey(w)) {

                    wordCountMap.put(w, one);
                } else {
                    wordCountMap.put(w, wordCountMap.get(w) + one);
                }
            }
        }

        return wordCountMap;

    }


}
