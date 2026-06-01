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
        System.out.println(nonTrimmedString.trim());
    }
}
