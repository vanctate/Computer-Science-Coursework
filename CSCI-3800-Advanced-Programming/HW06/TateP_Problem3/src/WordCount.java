/*
    Patrick Tate
    CSCI 3800 HW6 Problem 3
 */
import java.io.File;
import java.io.IOException;
import java.util.*;
import static java.lang.Math.toIntExact;

public class WordCount {

    // combines 2 maps and returns the result
    // if a key is already in one map, it's long value is added to the existing
    public static HashMap<String, Long> mergeMaps(HashMap<String,Long> map1, HashMap<String,Long> map2){
        // initialize the map to be returned by setting equal to map1
        HashMap<String,Long> totalMap = new HashMap<>();
        // add map1 key/values
        for(String word : map1.keySet()){
            totalMap.put(word, map1.get(word));
        }

        // add map2 key/values
        for(String word : map2.keySet()){
            if (totalMap.containsKey(word)) {
                long val = map2.get(word);
                totalMap.put(word, totalMap.get(word) + val);
            } else {
                totalMap.put(word, map2.get(word));
            }
        }

        return totalMap;
    }

    public static void main(String[] args) throws IOException {

        // measure run time
        long startTime = System.currentTimeMillis();

        // shakespeare file 1
        FileProcessor fp = new FileProcessor("shakespeare-life-54.txt");

        // hash map for shakesepare file 1
        HashMap<String, Long> wordCount1 = fp.processFile();

        // shakespeare file 2
        FileProcessor fp2 = new FileProcessor("shakespeare-life-55.txt");

        // hash map for shakesepare file 2
        HashMap<String, Long> wordCount2 = fp2.processFile();

        // shakespeare file 3
        FileProcessor fp3 = new FileProcessor("shakespeare-life-56.txt");

        // hash map for shakesepare file 3
        HashMap<String, Long> wordCount3 = fp3.processFile();

        // merge all 3 maps
        WordCount wT = new WordCount();
        HashMap<String, Long> totalMap = wT.mergeMaps(wordCount1, wordCount2);
        totalMap = wT.mergeMaps(totalMap, wordCount3);

        // print the merged map
        System.out.println("Merged map result:");
        System.out.println(totalMap);
        System.out.println();

        // figure out 50 biggest key/value pairs
        // TreeMap to store values of HashMap in an ordered key/value set
        TreeMap<Integer, String> sorted = new TreeMap<>();
        for(String word : totalMap.keySet()){
            int val = toIntExact(totalMap.get(word));
            sorted.put(val, word);
        }

        // print the 50 biggest key/value pairs
        System.out.println("50 biggest key/value pairs in map");
        int count = 1;
        for(int value : sorted.descendingKeySet()){
            System.out.println(count + ": key: " + sorted.get(value) + ", value = " + value);
            count++;
            if(count == 51){
                break;
            }
        }

        // calculate and print run time
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;
        System.out.println();
        System.out.println("total time to run (milliseconds): " + (System.currentTimeMillis() - startTime));

    }
}

