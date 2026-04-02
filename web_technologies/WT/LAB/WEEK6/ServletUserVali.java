import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class FirstServlet extends HttpServlet {
public void doPost(HttpServletRequest request, HttpServletResponse response) throws
ServletException, IOException {
response.setContentType("text/html");
PrintWriter out = response.getWriter();
String n=request.getParameter("username");
String p=request.getParameter("userpass");
try {
Class.forName("com.mysql.jdbc.Driver");
Connection conn = DriverManager.getConnection(“jdbc:mysql://localhost/mydb”, “root”, “Gcet@123”);
Statement stmt = conn.createStatement();
String sql= "SELECT * FROM user WHERE name=n and pass=p";
ResultSet rs = stmt.executeQuery(sql);
if(rs.next()){
out.println("Welcome "+n);
} else{
out.println("Sorry username or password error");
RequestDispatcher rd=request.getRequestDispatcher("/index.html");
rd.include(request,response);
19
}
rs.close();
stmt.close();
conn.close();
} catch(Exception e){
e.printStackTrace();
}
out.close();
}
}