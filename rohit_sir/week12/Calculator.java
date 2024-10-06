import java.util.Scanner;

class Calculator{
    private static int add(int a, int b){
        return a + b;
    }
    private static int sub(int a, int b){
        return a - b;
    }
    public static void main(String args[]){
        Scanner inp = new Scanner(System.in);

        System.out.print("Enter first number: ");
        int a = inp.nextInt();
        
        System.out.print("Enter second number: ");
        int b = inp.nextInt();

        System.out.println("\nAddition of numbers: " + add(a, b));
        System.out.println("Subtraction of numbers: " + sub(a, b));

        inp.close();
    }
}