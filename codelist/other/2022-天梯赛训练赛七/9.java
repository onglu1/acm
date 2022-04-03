import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String[] num = sc.nextLine().split(" ");
        ArrayList<Integer> a = new ArrayList<Integer>();
        for(String s : num) {
            a.add(Integer.parseInt(s));
        }
        String[] op = sc.nextLine().split(" ");
        for(int i = n - 2; i >= 0; i--) {
            int x = a.get(i);
            int y = a.get(i + 1);
            a.remove(i + 1); a.remove(i);
            if(op[i].equals("+")) a.add(x + y);
            else if(op[i].equals("-")) a.add(x - y);
            else if(op[i].equals("*")) a.add(x * y);
            else {
                if(y == 0) {
                    System.out.printf("ERROR: %d/%d\n", x, y);
                    return ;
                }
                a.add(x / y);
            }
        }
        System.out.println(a.get(0));
    }
}
