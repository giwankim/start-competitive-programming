// 2020 Dec Bronze 1, ABCs

import java.io.*;
import java.util.*;

public class Cowphabet_2021JanB1 {

    public static void main(String[] args) throws IOException {

        //BufferedReader r = new BufferedReader(new FileReader("abcs.in"));
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("herding.out")));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));



        StringTokenizer st = new StringTokenizer(r.readLine());
        // Input
        String abc = st.nextToken();
        st = new StringTokenizer(r.readLine());
        String str = st.nextToken();

        int cnt = 0;
        // Your code here
        String s1 = str.substring(0,1);
        int i1 = abc.indexOf(s1);
        cnt = 1;

        for (int i=1; i<str.length(); ++i){
          String s2 = str.substring(i,i+1);
          int i2 = abc.indexOf(s2);
          if (i2<=i1) cnt++;
          i1 = i2;
        }

        // Output
        pw.println(cnt);

        /*****/
        r.close();
        pw.close();
    }


}
