package com.wt.login;

import java.io.*;
import java.sql.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;

public class LoginServlet extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String n = request.getParameter("username");
        String p = request.getParameter("userpass");

        try {
            // Loading MariaDB Driver
            Class.forName("org.mariadb.jdbc.Driver");

            // Connecting to the database
            Connection conn = DriverManager.getConnection(
                    "jdbc:mariadb://localhost:3306/wt_lab", "root", "your_password");

            String sql = "SELECT * FROM user WHERE name = ? AND pass = ?";
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setString(1, n);
            stmt.setString(2, p);

            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                out.println("<html><body>");
                out.println("<h1>Login Successful!</h1>");
                out.println("<p>Welcome, " + n + "</p>");
                out.println("</body></html>");
            } else {
                out.println("<html><body>");
                out.println("<h3 style='color:red;'>Failure: Invalid Username or Password</h3>");
                // Include the login page back to try again
                RequestDispatcher rd = request.getRequestDispatcher("/index.html");
                rd.include(request, response);
                out.println("</body></html>");
            }

            conn.close();
        } catch (Exception e) {
            out.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }
}