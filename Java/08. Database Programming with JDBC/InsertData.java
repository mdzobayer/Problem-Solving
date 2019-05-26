import java.sql.*;

public class InsertData {
    public static void main(String [] args) {

        Connection conn = null;
        try {
            String userName = "root";
            String password = "seagoldbag";
            String url = "jdbc:mysql://localhost/test";
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            conn = DriverManager.getConnection (url, userName, password);
            Statement stmt;
            stmt = conn.createStatement();

            stmt.executeUpdate (
                        "insert into books (isbn, title, author, publisher)" +
                        " values" +
                        "('00716063', 'Java-The Complete Reference'," +
                        "'Herbert Schildt', 'Oracle Press')," +
                        "('032135668', 'Effective Java'," +
                        "'Joshua Bloch', 'Addison-Wesley')"
                                );

            conn.close();
            System.out.println("Record Added.");
        }
        catch(Exception e) {
            System.out.println("Error Inserting Data.\nError: " + e.toString());
        }
    }
}
