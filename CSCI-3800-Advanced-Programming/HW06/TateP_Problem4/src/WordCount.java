/*
    Patrick Tate
    CSCI 3800 HW6 Problem 4
 */

import java.util.HashMap;
import java.util.concurrent.*;
import java.util.*;
import static java.lang.Math.toIntExact;

public class WordCount {

    private String[] threadAr;
    private int numOfThreads;

    private HashMap<String, Long> totalWordCount = new HashMap<String, Long>();


    public WordCount(int numThreads, String[] array){
        this.numOfThreads = numThreads;
        this.threadAr = array;

    }

    // combine two maps into one and return the result
    public static HashMap<String, Long> mergeMaps(HashMap<String,Long> map1, HashMap<String,Long> map2){

        HashMap<String,Long> totalMergeMap = new HashMap<>();
        for(String word : map1.keySet()){
            totalMergeMap.put(word, map1.get(word));
        }

        for(String word : map2.keySet()){
            if (totalMergeMap.containsKey(word)) {
                long val = map2.get(word);
                totalMergeMap.put(word, totalMergeMap.get(word) + val);
            } else {
                totalMergeMap.put(word, map2.get(word));
            }
        }
        return totalMergeMap;
    }

    // determine how many threads to run
    public static void executor(int numOfThreads, String[] arrayOfFiles) throws InterruptedException, Exception{
        new WordCount(numOfThreads, arrayOfFiles).wordCounter();
    }


    // synchronized version of the wordCounter
    // still performs same word count key/value as in non multithreaded program
    private synchronized void wordCounter() throws InterruptedException, Exception{
        // executor for each thread/file
        ExecutorService threadExecutor = Executors.newFixedThreadPool(numOfThreads);

        CompletionService<HashMap<String, Long>> cs = new ExecutorCompletionService<HashMap<String, Long>>(threadExecutor);

        int countb = 0;

        // run a callable for each thread/file
        for(int i = 0; i < numOfThreads; i++){
            countb++;
            Callable<HashMap<String ,Long>> newCallableProcess = new FileProcessor(this.threadAr[i]);
            cs.submit(newCallableProcess);
        }

        Future<HashMap<String, Long>> donezo;
        HashMap<String , Long> hashMap = null;
        ArrayList<HashMap<String , Long>> list = new ArrayList<>();

        while(countb > 0){
            donezo = cs.take();
            countb--;

            try{
                hashMap = donezo.get();
                list.add(hashMap);
            }catch (ExecutionException e){
                Throwable cause = e.getCause();
            }
        }
        // stop thread
        threadExecutor.shutdown();

        // merge the 3 maps
        totalWordCount = mergeMaps(list.get(0), list.get(1));
        totalWordCount = mergeMaps(totalWordCount, list.get(2));

        // print the total merged maps
        System.out.println(totalWordCount);

        // figure out 50 biggest key/value pairs
        // TreeMap to store values of HashMap in an ordered key/value set
        TreeMap<Integer, String> sorted = new TreeMap<>();
        for(String word : totalWordCount.keySet()){
            int val = toIntExact(totalWordCount.get(word));
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
        }// for


    }

    // run the multi threaded word counter
    public static void main(String[] args) throws InterruptedException, Exception {

        // calculate run time
        long startTime = System.currentTimeMillis();

        // variable to hold 3 text file names
        String[] fileNames = new String[] {"shakespeare-life-54.txt", "shakespeare-life-55.txt", "shakespeare-life-56.txt"};

        // 3 threads for 3 text filds
        int totalThreads = fileNames.length;
        WordCount.executor(totalThreads, fileNames);

        // calculate and print run time
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - startTime;
        System.out.println();
        System.out.println("total time to run (milliseconds): " + (System.currentTimeMillis() - startTime));

    }


}

