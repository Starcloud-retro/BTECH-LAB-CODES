package week14;

import java.sql.*;
import java.io.*;
import java.util.*;
public class Tbltodb
{
    public static void main(String[] args)
    {
        Connection cn;
        Statement st;
        try
        {
            Class.forName("com.mysql.cj.jdbc.Driver");
            cn=DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc","root","Rishit@25");
            st=cn.createStatement();
            String sql="";
            FileInputStream fin=new FileInputStream("D:/RAJ/GCET/PROGRAMMING RELATED/2nd Year/OBJECT ORIENTED PROGRAMMING [JAVA]/GCET/src/week13/myfile.txt");
            Scanner sc=new Scanner(fin);
            String[] arrayList;
            String a="";
            int i=0;
            while(sc.hasNext())
            {
                a=sc.nextLine();
                arrayList =a.split("\t");
                sql="insert into emp values("+"'"+arrayList[0]+"','"+arrayList[1]+"')";
                st.execute(sql);
                i++;
                System.out.println(arrayList[0]+":"+arrayList[1]);
            }
            System.out.println(i+" Records are Inserted!");
            st.close();
            cn.close();
            sc.close();
        }
        catch(Exception ex)
        {
            System.out.println(ex.getMessage());
        }
    }
}
