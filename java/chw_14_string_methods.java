public class chw_14_string_methods {
    public static void main(String[] args) {
        String name = "Harry";
        //String name = new String("harry");
        System.out.println(name);
        
        int value = name.length();
        System.out.println(value);
        
        String lstring = name.toLowerCase();
        System.out.println(lstring);
        
        String ustring = name.toUpperCase();
        System.out.println(ustring);
        //strings are immutable that's why we are assigning it to the new string...
        String nonTrimmedString = "    harry    ";
        System.out.println(nonTrimmedString);

        String trimmedString = nonTrimmedString.trim();
        System.out.println(trimmedString);

        System.out.println(name.substring(1));
        System.out.println(name.substring(1,4));

        System.out.println(name.replace('r','p'));
        System.out.println(name.replace("r","ier"));

        System.out.println(name.startsWith("Har"));
        System.out.println(name.endsWith("rry"));
  
        System.out.println(name.charAt(2));
        System.out.println(name.indexOf("ry"));
        
        String modifiedName = "Harryrry";
        System.out.println(modifiedName.indexOf("rry",4));
        
        System.out.println(name.equals("Harry"));
        System.out.println(name.equalsIgnoreCase("harry"));
    
        System.out.println("I am escape sequence \" doube quote");
        // \" \n \t \' \\ -> they all are escape sequences
    }
}
