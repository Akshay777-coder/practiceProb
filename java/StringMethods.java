public class StringMethods {
    public static void main(String[] args) {
        String name = "Harry";
        System.out.println("name: " + name);
        
        int value = name.length();
        System.out.println("length of string: " + value);
      
        String lstring = name.toLowerCase();
        System.out.println("Lower Case :" + lstring);
        
        String ustring = name.toUpperCase();
        System.out.println("Upper Case :" + ustring);

        String nonTrimmedString = "     Harry     ";
        System.out.println("nonTrimmedString: " + nonTrimmedString);

        String TrimmedString = nonTrimmedString.trim();
        System.out.println("TrimmedString: " + TrimmedString);

        System.out.println("Substring: " + name.substring(2));

        // name.substring(int start, int end) -> start is included and end is not included
        System.out.println("Substring: " + name.substring(1,4));

        System.out.println("replaced \'r\' with \'p\': " + name.replace('r','p'));
    }
}
