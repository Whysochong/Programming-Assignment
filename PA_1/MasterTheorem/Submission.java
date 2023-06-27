package MasterTheorem;
import java.util.Scanner;

public class Submission {

    static String formatTheta(String expression) {
        return "T(n) = \u0398(" + expression + ")\n";
    }

    static String formatNo(double value) {
        if (value == 0) {
            return "";
        } else if (value == 1) {
            return "n";
        } else if (value == (int) value) {
            return "n^" + (int) value;
        } else {
            return String.format("n^%.1f", value);
        }
    }

    static String formatLog(int k) {
        if (k == 0) {
            return "";
        } else if (k == 1) {
            return "log n";
        } else {
            return "log^" + k + " n"; 
        }
    }

    static String mastertheorem(int a, float b, float c, float d, int k) {
        // case 1
        if ((double) a > Math.pow(b, d)) {
            double power = Math.log(a) / Math.log(b);
            return formatTheta(formatNo(power));
        }
        // case 2
        if ((double) a == Math.pow(b, d)) {
            double power = Math.log(a) / Math.log(b);
            String result = formatNo(power);
            String logResult = formatLog(k+1);
            if (result != "") {
                result += " ";
            }
            return formatTheta(result + logResult);
        }
        // case 3
        if (d > 1 || a/b < c) {
            String formatD = formatNo(d);
            String formatlg = formatLog(k);

            if (formatD != "" && formatlg != "") {
                formatD += " ";
            }
            formatD += formatlg;
            return formatTheta(formatD);
            
        }
        return "not applicable\n";
    }
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int TC = sc.nextInt();
            sc.nextLine();
            String result = "";

            for (int i = 0; i < TC; i++) {
                String line = sc.nextLine();
                String[] input = line.split(" ");
                int a = Integer.parseInt(input[0]);
                float b = Float.parseFloat(input[1]);
                float c = Float.parseFloat(input[2]);
                float d = Float.parseFloat(input[3]);
                int k = Integer.parseInt(input[4]);

                result += mastertheorem(a, b, c, d, k);
            }
            System.out.print(result);
        } catch (NumberFormatException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
