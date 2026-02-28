package week14;

import  java.sql.*;
import java.util.*;
public class Tblmdata
{
    public static void main(String[] args)
    {
        Connection cn;
        Statement st;
        ResultSet rs, rs1;
        ResultSetMetaData rsmd;
        try
        {
            Scanner sc = new Scanner(System.in);
            System.out.println("------connecting database-----");
            System.out.println("Enter Database Name");
            String dbname = sc.next();
            System.out.println("Enter Password");
            String pass = sc.next();
            Class.forName("com.mysql.cj.jdbc.Driver");
            cn = DriverManager.getConnection("jdbc:mysql://localhost:3306/" + dbname, "root", pass);
            st = cn.createStatement();
            DatabaseMetaData dm = cn.getMetaData();
            rs = dm.getTables(cn.getCatalog(), "%", "%", null);
            //String s = "";
            String sql = "SELECT * FROM ", sql1 = "";
            System.out.println("-------------------------\nDatabase is " + dbname);
            System.out.println("-------------------------");
            System.out.println("Tables are");
            while (rs.next()) {
                sql1 = "";
                System.out.println("Table Name: " + rs.getString(3)+"\n");
                sql1 = sql + rs.getString(3);
                rs1 = st.executeQuery(sql1);
                rsmd = rs1.getMetaData();
                System.out.println("Columns are:");
                System.out.println("Column_Name\tColumn_Type\tSize");
                for (int i = 1; i <= rsmd.getColumnCount(); i++) {
                    System.out.println(rsmd.getColumnLabel(i) + "\t    " + rsmd.getColumnTypeName(i) + "\t\t" +rsmd.getColumnDisplaySize(i));
                }
                System.out.println("----------------------------------");
            }
            rs.close();
            cn.close();
            sc.close();
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }
}
