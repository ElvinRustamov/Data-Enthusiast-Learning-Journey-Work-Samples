package com.example.employeeinformation;

import java.sql.*;

public class DatabaseConnection {
    private Connection databaseConnection;

    public Connection getDatabaseConnection() {
        String PASSWORD = "123";
        String NAME = "postgres";
        String URL = "jdbc:postgresql://localhost:5432/Employees";
//        String url = "jdbc:sqlite:C:\\Users\\maham\\Desktop\\JAVA\\Databases\\employees.db";
//        try {
//            Class.forName("org.sqlite.JDBC");

        try {
            databaseConnection = DriverManager.getConnection(URL, NAME, PASSWORD);
            System.out.println("Database connection established successfully.");
            try {
                DatabaseMetaData metaData = databaseConnection.getMetaData();
                ResultSet resultSet = metaData.getTables(null, null, "%", new String[]{"TABLE"});
                System.out.println("Tables in the database:");
                while (resultSet.next()) {
                    String tableName = resultSet.getString("TABLE_NAME");
                    System.out.println(tableName);
                }
                resultSet.close();
            } catch (SQLException e) {
                System.out.println("Error fetching table names: " + e.getMessage());
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

//            System.out.println("Database connection established successfully.");
//        } catch (ClassNotFoundException e) {
//            System.out.println("SQLite JDBC driver not found.");
//            e.printStackTrace();
//        } catch (SQLException e) {
//            System.out.println("Error establishing database connection.");
//            e.printStackTrace();
//        }
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