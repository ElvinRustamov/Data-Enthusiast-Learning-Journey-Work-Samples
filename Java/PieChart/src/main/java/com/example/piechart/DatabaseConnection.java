package com.example.piechart;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DatabaseConnection {
    private Connection databaseConnection;

    public Connection getDatabaseConnection() {
        String url = "jdbc:sqlite:C:\\Users\\maham\\Desktop\\JAVA\\Databases\\Population.db";
        try {
            Class.forName("org.sqlite.JDBC");

            databaseConnection = DriverManager.getConnection(url);

            System.out.println("Database connection established successfully.");
        } catch (ClassNotFoundException e) {
            System.out.println("SQLite JDBC driver not found.");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Error establishing database connection.");
            e.printStackTrace();
        }
        return databaseConnection;
    }

    public void closeDatabaseConnection() {
        if (databaseConnection != null) {
            try {
                databaseConnection.close();
                System.out.println("Database connection closed.");
            } catch (SQLException e) {
                System.out.println("Error closing database connection.");
                e.printStackTrace();
            }
        }
    }
}