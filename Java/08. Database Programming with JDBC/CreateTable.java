import java.sql.*;

public class CreateTable {
    public static void main(String [] args) {
        Connection conn = null;
        try {
            String userName = "root";
            String password = "seagoldbag";
            String url = "jdbc:mysql://localhost/test";
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            conn = DriverManager.getConnection(url, userName, password);

            Statement stmt;
            stmt = conn.createStatement();

            stmt.executeUpdate("drop table if exists books");
            stmt.executeUpdate(
                "create table books (" +
                "isbn char(10), title char(50)," +
                "author char(50), publisher char(50))"
                                );
            conn.close();
            System.out.println("Table is Created.");
        }
        catch(Exception e) {
            System.out.println("Error Creating Table\n. Error: " + e.toString());
        }
    }
}