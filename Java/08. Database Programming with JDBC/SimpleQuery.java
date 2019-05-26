import java.sql.*;

public class SimpleQuery {

    public static void main(String [] args) {
        Connection conn = null;
        try {
            String userName = "root";
            String password = "seagoldbag";
            String url = "jdbc:mysql://localhost/test";
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            conn = DriverManager.getConnection(url, userName, password);
            Statement stmt;
            ResultSet rset;

            stmt = conn.createStatement();
            rset = stmt.executeQuery("select * from films");
            while(rset.next()) {
                String title = rset.getString("title");
                int year = rset.getInt("year");
                String director = rset.getString("director");
                System.out.println("Title: " + title + " Year: "
                                  + year + " Director: " + director);
            }
            /// This is very important to close the result set and connection.
            rset.close();
            conn.close();
        }
        catch (Exception e) {
            System.out.println("Error: " + e.toString());
        }
    }
}
