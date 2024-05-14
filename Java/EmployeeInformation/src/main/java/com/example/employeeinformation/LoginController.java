package com.example.employeeinformation;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.chart.PieChart;
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import javafx.stage.Stage;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class LoginController {
    private Stage stage;

    public void setStage(Stage stage) {
        this.stage = stage;
    }

    @FXML
    private Label output_text_field;

    @FXML
    private TextField username_text_field;

    @FXML
    private PasswordField password_text_field;

    public void loginButtonOnAction(ActionEvent e) {
        if (username_text_field.getText().isEmpty() || password_text_field.getText().isEmpty()) {
            output_text_field.setText("Please enter your username and password");
        } else {
            DatabaseConnection connection = new DatabaseConnection();
            try {
                Connection dbConnection = connection.getDatabaseConnection();

                String username = username_text_field.getText();
                String password = password_text_field.getText();

                String query = "SELECT * FROM public.\"EmployeesLoginInformation\" WHERE username = ?";
                PreparedStatement statement = dbConnection.prepareStatement(query);
                statement.setString(1, username);
                ResultSet resultSet = statement.executeQuery();

                if (!resultSet.next()) {
                    output_text_field.setText("Username doesn't exist");
                } else {
                    String dbPassword = resultSet.getString("password");
                    if (dbPassword.equals(password)) {
                        output_text_field.setText("Login successful");
                        openEmployeeInformationWindow();

                    } else {
                        output_text_field.setText("Incorrect password");
                    }
                }

                resultSet.close();
                statement.close();
                connection.closeDatabaseConnection();

            } catch (SQLException ex) {
                output_text_field.setText("Error accessing database");
                ex.printStackTrace();
            }
        }
    }

    private void openEmployeeInformationWindow() {
        try {
            stage.close();

            FXMLLoader loader = new FXMLLoader(getClass().getResource("e_information.fxml"));
            Parent root = loader.load();
            employeeInformationController controller = loader.getController();

            Stage employeeInfoStage = new Stage();
            Scene scene = new Scene(root);
            employeeInfoStage.setScene(scene);
            employeeInfoStage.setTitle("Employee Information");
            employeeInfoStage.show();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
