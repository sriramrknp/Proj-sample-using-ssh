import java.util.*;
public class input_java {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.println("Enter your name");
        String firstname = input.nextLine();

        System.out.println("Enter last name");
        String lastname = input.nextLine();

        System.out.println("Full name is: " +firstname+" "+lastname);

        input.close();
    }
}
