package week14;

import java.sql.*;

public class JdbcExample
{
    static final String JDBC_DRIVER="com.mysql.cj.jdbc.Driver";
    static final String JDBC_URL="jdbc:mysql://localhost:3306/jdbc";
    static final String USER="root";
    static final String PASS="Rishit@25";
    public static void main(String args[])
    {
        Connection conn;
        Statement stmt;
        try
        {
            System.out.println("--------connecting to database--------");
            try
            {
                Class.forName(JDBC_DRIVER);
            }
            catch (ClassNotFoundException e)
            {
                System.out.println("JDBC Driver not found: " + e.getMessage());
                return; // Exit if driver not found
            }
            conn=DriverManager.getConnection(JDBC_URL,USER,PASS);
            System.out.println("creating statement--");
            stmt=conn.createStatement();
            String sql,sql1,sql2,sql3;
            sql1="INSERT INTO employee values(23,'bob','s',20)";
            int s1= stmt.executeUpdate(sql1);
            sql2="UPDATE employee SET age=18 WHERE id=3";
            int s2= stmt.executeUpdate(sql2);
            sql3="DELETE FROM employee WHERE id=24";
            int s3= stmt.executeUpdate(sql3);
            System.out.println("S1:"+s1+" S2:"+s2+" S3:"+s3+ "\n");
            //output as :S1:1 S2:0 S3:0
            sql="SELECT id,first,last,age FROM employee";
            ResultSet rs=stmt.executeQuery(sql);
            while(rs.next())
            {
                int id=rs.getInt("id");
                int age=rs.getInt("age");
                String first=rs.getString("first");
                String last=rs.getString("last");
                System.out.println("ID:"+id);
                System.out.println("Age:"+age);
                System.out.println("First:"+first);
                System.out.println("Last:"+last);
            }
            rs.close();
            stmt.close();
            conn.close();
        }
        catch(SQLException se)
        {
            se.printStackTrace();
        }
        System.out.println("Goodbye");
    }
}
