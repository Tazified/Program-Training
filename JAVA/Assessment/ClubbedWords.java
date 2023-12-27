/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author ashwi
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class ClubbedWords {
    public static List<String> findClubbedWords(String[] words) {
        List<String> result = new ArrayList<>();

        Set<String> wordSet = new HashSet<>(Arrays.asList(words));

        for (String word : words) {
            wordSet.remove(word); // Exclude the current word from the set
            if (isClubbedWord(word, wordSet)) {
                result.add(word);
            }
            wordSet.add(word); // Restore the current word to the set
        }

        return result;
    }

    private static boolean isClubbedWord(String word, Set<String> wordSet) {
        if (word.isEmpty()) {
            return false;
        }

        int n = word.length();

        for (int i = 1; i <= n; i++) {
            String prefix = word.substring(0, i);
            String suffix = word.substring(i);

            if (wordSet.contains(prefix) && (wordSet.contains(suffix) || isClubbedWord(suffix, wordSet))) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        String[] words = {"mat", "mate", "matbellmates", "bell", "bellmatesbell", "butterribbon", "butter", "ribbon"};
        List<String> clubbedWords = findClubbedWords(words);

        System.out.println("Input: " + Arrays.toString(words));
        System.out.println("Output: " + clubbedWords);
    }
}

