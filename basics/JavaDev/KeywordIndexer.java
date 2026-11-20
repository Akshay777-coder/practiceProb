
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.TreeMap;

public class KeywordIndexer {

    // Input and output file names
    static String inputFile = "input.txt";
    static String outputFile = "index.txt";

    // Words we do not want in the index
    static String[] stopWords = {
        "the", "and", "for", "are", "but", "not",
        "you", "all", "can", "was", "with", "this", "that"
    };

    // Keyword -> line numbers
    static TreeMap<String, String> index = new TreeMap<String, String>();

    // Check whether a word is a valid keyword
    static boolean isKeyword(String word) {

        if (word.length() < 3) {
            return false;
        }

        for (int i = 0; i < stopWords.length; i++) {
            if (word.equals(stopWords[i])) {
                return false;
            }
        }

        return true;
    }

    // Add keyword and its line number
    static void addWord(String word, int lineNumber) {

        String lines = index.get(word);

        if (lines == null) {
            index.put(word, "" + lineNumber);
        }
        else if (!lines.equals("" + lineNumber)
                && !lines.endsWith(", " + lineNumber)) {

            index.put(word, lines + ", " + lineNumber);
        }
    }

    // Read input file and generate keyword index
    static void createIndex() throws IOException {

        BufferedReader reader =
            new BufferedReader(new FileReader(inputFile));

        String line;
        int lineNumber = 0;

        while ((line = reader.readLine()) != null) {

            lineNumber++;

            // Convert to lowercase
            line = line.toLowerCase();

            // Remove punctuation
            line = line.replaceAll("[^a-z0-9\\s]", " ");

            // Split line into words
            String[] words = line.split("\\s+");

            for (int i = 0; i < words.length; i++) {

                String word = words[i].trim();

                if (isKeyword(word)) {
                    addWord(word, lineNumber);
                }
            }
        }

        reader.close();
    }

    // Write sorted index to output file
    static void writeIndex() throws IOException {

        BufferedWriter writer =
            new BufferedWriter(new FileWriter(outputFile));

        for (String word : index.keySet()) {

            writer.write(word + " : " + index.get(word));
            writer.newLine();
        }

        writer.close();
    }

    // Main method
    public static void main(String[] args) {

        try {

            createIndex();
            writeIndex();

            System.out.println("Keyword index created successfully!");
            System.out.println("Output file: " + outputFile);

        }
        catch (IOException e) {

            System.out.println("File Error: " + e.getMessage());
        }
    }
}
