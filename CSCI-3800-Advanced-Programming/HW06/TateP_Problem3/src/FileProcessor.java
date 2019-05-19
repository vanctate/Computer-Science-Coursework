/*
    Patrick Tate
    CSCI 3800 HW6 Problem 3
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.io.*;
/**
 * This class process one file returning a Map of word -> count
 *
 * Remember you need to implement this by yourself.
 * You should only use the web for reading documentation https://docs.oracle.com/javase/8/docs/api/
 *
 * Copying code from the internet, even if it an extract is not allowed and will be considered
 * plagiarism.
 */
public class FileProcessor {
    private String filename;


    public FileProcessor(String filename){
        //Object Initialization
        this.filename = filename;
    }


    /**
     * Process the file associated with the object.
     *
     * @return a Map for each word as a key and the number of occurrences of that word as its value
     */
    /*
    public Map<String,Long> processFile(){
//        Initialize your map
//        open the file
//            for every line
//                clean the line to remove . , ? ; : ' "
//                visit the String.replaceAll method.  to construct the regular expression like "\\.|,"
//                split the line to get every single word
//                for every word
//                    update the count in the map
//        return the map
    }
    */

    public HashMap<String, Long> processFile() throws IOException {
        // initialize map to store key=word, value=word frequency
        HashMap<String, Long> wordCounter = new HashMap<String, Long> ();

        // file containing shakespeare text
        File shakespeareFile = new File(this.filename);

        // object to read through shakespeare text file
        BufferedReader br = new BufferedReader(new FileReader(shakespeareFile));

        // line to hold text from file
        String line;

        // read until end of shakespeare text file
        while ((line = br.readLine()) != null) {
            // array list to hold each word in the line
            ArrayList<String> words = new ArrayList<>();
            // split the line into an array of individual words
            String[] wordArray = line.split(" ");

            // add each word from the line into the array list
            for(String word : wordArray){
                // clean the string of the characters . , ? ; : ' "

                // remove all occurances of . in the word
                if(word.contains(".")){
                    word = word.replace(".", "");
                }
                // remove all occurances of , in the word
                if(word.contains(",")){
                    word = word.replace(",", "");
                }
                // remove all occurances of ? in the word
                if(word.contains("?")){
                    word = word.replace("?", "");
                }
                // remove all occurances of ; in the word
                if(word.contains(";")){
                    word = word.replace(";", "");
                }
                // remove all occurances of : in the word
                if(word.contains(":")){
                    word = word.replace(":", "");
                }
                // remove all occurances of ' in the word
                if(word.contains("'")){
                    word = word.replace("'", "");
                }
                // remove all occurances of . in the word
                if(word.contains("\"")){
                    word = word.replace("\"", "");
                }
                // remove " " from word
                if(word.contains(" ")){
                    word = word.replace(" ", "");
                }
                // remove tab "\t" from word
                if(word.contains("\t")){
                    word = word.replace("\t", "");
                }

                // add cleaned word to the array list
                if(!word.equals("")){
                    words.add(word);
                }
            }

            // if word isn't in the hash map, add the word as the key with the value of 1
            // if word already in hash map, increment the key's value by 1
            for(String w : words){
                if (!wordCounter.containsKey(w)) {
                    long initVal = 1;
                    wordCounter.put(w, initVal);
                } else {
                    long plusOne = 1;
                    wordCounter.put(w, wordCounter.get(w) + plusOne);
                }
            }// for
        }//while

        //System.out.println(wordCounter);
        return wordCounter;
    }// function


}// class


