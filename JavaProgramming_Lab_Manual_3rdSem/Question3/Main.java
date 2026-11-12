// Write a Java program that reads a multi-word sentence from the console and performs the following without using built-in reverse() methods for part (1):
// 1. Check if each individual word in the sentence is a Palindrome (case-insensitive).
// 2. Count the total number of vowels, consonants, digits, and special characters.
// 3. Use StringBuilder to convert the sentence into Title Case and remove duplicate consecutive spaces.

import java.util.Scanner;

class Solution {
    public boolean isPalindrome(String word) {
        String lowerCaseWord = word.toLowerCase();
        int left = 0;
        int right = lowerCaseWord.length() - 1;
        while (left < right) {
            if (lowerCaseWord.charAt(right) != lowerCaseWord.charAt(left)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    public int[] countCharacters(String sentence) {
        int vowels = 0;
        int consonants = 0;
        int digits = 0;
        int specialChars = 0;
        for (char ch : sentence.toCharArray()) {
            if (Character.isLetter(ch)) {
                char lowerCh = Character.toLowerCase(ch);
                if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                    vowels++;
                } else {
                    consonants++;
                }
            } else if (Character.isDigit(ch)) {
                digits++;
            } else if (!Character.isWhitespace(ch)) {
                specialChars++;
            }
        }
        return new int[]{vowels, consonants, digits, specialChars};
    }

    public String toTitleCase(String sentence) {
        StringBuilder titleCase = new StringBuilder();
        boolean nextTitleCase = true;
        for (char ch : sentence.toCharArray()) {
            if (Character.isSpaceChar(ch)) {
                if (!titleCase.toString().endsWith(" ")) {
                    titleCase.append(ch);
                }
            } else {
                if (nextTitleCase) {
                    titleCase.append(Character.toUpperCase(ch));
                    nextTitleCase = false;
                } else {
                    titleCase.append(ch);
                }
            }
        }
        return titleCase.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a multi-word sentence: ");
        String sentence = scanner.nextLine();
        scanner.close();

        Solution solution = new Solution();

        // Part 1: Check if each word is a palindrome
        String[] words = sentence.split("\\s+");
        System.out.println("Palindrome words:");
        for (String word : words) {
            if (solution.isPalindrome(word)) {
                System.out.println(word);
            }
        }

        // Part 2: Count characters
        int[] counts = solution.countCharacters(sentence);
        System.out.println("Character counts:");
        System.out.println("Vowels: " + counts[0]);
        System.out.println("Consonants: " + counts[1]);
        System.out.println("Digits: " + counts[2]);
        System.out.println("Special characters: " + counts[3]);

        // Part 3: Convert to title case
        System.out.println("Title case: " + solution.toTitleCase(sentence));
    }
}