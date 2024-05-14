package com.example.employeeinformation;

import javafx.beans.binding.Bindings;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;


public class employeeInformationController {
    @FXML
    private TableView<employee> table_view;

    @FXML
    private TableColumn<employee, String> fin_column;

    @FXML
    private TableColumn<employee, String> name_column;

    @FXML
    private TableColumn<employee, String> surname_column;

    @FXML
    private TableColumn<employee, String> phone_number_column;

    @FXML
    private TableColumn<employee, String> job_title_column;

    @FXML
    private TableColumn<employee, String> address_column;

    @FXML
    private TableColumn<employee, Integer> age_column;



    @FXML
    private TextField fin_text_field;

    @FXML
    private TextField name_text_field;

    @FXML
    private TextField surname_text_field;

    @FXML
    private TextField phone_text_field;

    @FXML
    private TextField job_text_field;

    @FXML
    private TextField address_text_field;

    @FXML
    private TextField age_text_field;

    @FXML
    private Label label_error;

    @FXML
    private Label label_success;

    public void initialize() {
        fin_column.setCellValueFactory(cellData -> cellData.getValue().finProperty());
        name_column.setCellValueFactory(cellData -> cellData.getValue().nameProperty());
        surname_column.setCellValueFactory(cellData -> cellData.getValue().surnameProperty());
        phone_number_column.setCellValueFactory(cellData -> cellData.getValue().phoneNumberProperty());
        job_title_column.setCellValueFactory(cellData -> cellData.getValue().jobTitleProperty());
        address_column.setCellValueFactory(cellData -> cellData.getValue().addressProperty());
        age_column.setCellValueFactory(cellData -> Bindings.createObjectBinding(() -> cellData.getValue().getAge(), cellData.getValue().ageProperty()));

        populateTableView();
    }

    private void populateTableView() {
        DatabaseConnection connection = new DatabaseConnection();
        try {
            Connection dbConnection = connection.getDatabaseConnection();

            String query = "SELECT * FROM public.\"EmployeesInformation\"";
            Statement stmt = dbConnection.createStatement();
            ResultSet rs = stmt.executeQuery(query);

            while (rs.next()) {
                table_view.getItems().add(new employee(
                        rs.getString("FIN"),
                        rs.getString("Name"),
                        rs.getString("Surname"),
                        rs.getString("Phone Number"),
                        rs.getString("Job title"),
                        rs.getString("Address"),
                        rs.getInt("Age")
                ));
            }

            rs.close();
            stmt.close();
            dbConnection.close();

        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }

    public void addButtonAction(ActionEvent e) {
        DatabaseConnection connection = new DatabaseConnection();
        if (fin_text_field.getText().isEmpty()) {
            label_error.setText("FIN cannot be empty!");
        } else {
        try {
            Connection dbConnection = connection.getDatabaseConnection();

            String query = "SELECT \"FIN\" FROM public.\"EmployeesInformation\" WHERE \"FIN\" = ?";
            PreparedStatement pstmt = dbConnection.prepareStatement(query);
            pstmt.setString(1, fin_text_field.getText());

            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                label_error.setText("FIN exists in the database!");
                pstmt.close();
                rs.close();


            } else {
                pstmt.close();
                rs.close();

                if (!name_text_field.getText().isEmpty() &&
                        !surname_text_field.getText().isEmpty() &&
                        !phone_text_field.getText().isEmpty() &&
                        !job_text_field.getText().isEmpty() &&
                        !address_text_field.getText().isEmpty() &&
                        !age_text_field.getText().isEmpty())
                {
                    try {
                        String fin = fin_text_field.getText();
                        String name = name_text_field.getText();
                        String surname = surname_text_field.getText();
                        String phone = phone_text_field.getText();
                        String job = job_text_field.getText();
                        String address = address_text_field.getText();
                        int age = Integer.parseInt(age_text_field.getText());

                        String query_2 = "INSERT INTO public.\"EmployeesInformation\" (\"FIN\", \"Name\", \"Surname\", \"Phone Number\", \"Job title\", \"Address\", \"Age\") VALUES (?, ?, ?, ?, ?, ?, ?)";
                        PreparedStatement pstmt_2 = dbConnection.prepareStatement(query_2);

                        // Set parameters for the prepared statement
                        pstmt_2.setString(1, fin);
                        pstmt_2.setString(2, name);
                        pstmt_2.setString(3, surname);
                        pstmt_2.setString(4, phone);
                        pstmt_2.setString(5, job);
                        pstmt_2.setString(6, address);
                        pstmt_2.setInt(7, age);

                        pstmt_2.executeUpdate();
                        label_success.setText("Data added successfully!");
                        pstmt_2.close();
                        populateTableView();

                        fin_text_field.setText("");
                        name_text_field.setText("");
                        surname_text_field.setText("");
                        phone_text_field.setText("");
                        job_text_field.setText("");
                        address_text_field.setText("");
                        age_text_field.setText("");
                    } catch (SQLException ex) {
                        ex.printStackTrace();
                    }

                } else label_error.setText("Fill all forms!");
            dbConnection.close();
            }

        } catch (SQLException ex) {
            ex.printStackTrace();
        }

        }
    }

    public void deleteOnAction(ActionEvent e) {
        DatabaseConnection connection = new DatabaseConnection();
        if (fin_text_field.getText().isEmpty()) {
            label_error.setText("FIN cannot be empty!");
        } else {
            try {
                Connection dbConnection = connection.getDatabaseConnection();

                String query = "SELECT \"FIN\" FROM public.\"EmployeesInformation\" WHERE \"FIN\" = ?";
                PreparedStatement pstmt = dbConnection.prepareStatement(query);
                pstmt.setString(1, fin_text_field.getText());

                ResultSet rs = pstmt.executeQuery();

                if (rs.next()) {
                    pstmt.close();
                    rs.close();
                    String fin = fin_text_field.getText();

                    String query_2 = "DELETE FROM public.\"EmployeesInformation\" WHERE \"FIN\" = ?";
                    PreparedStatement pstmt_2 = dbConnection.prepareStatement(query_2);
                    pstmt_2.setString(1, fin);

                    int rowsAffected = pstmt_2.executeUpdate();

                    if (rowsAffected > 0) {
                        label_success.setText("Row(s) deleted successfully!");
                        label_error.setText("");
                    } else {
                        label_error.setText("No row found with the provided FIN!");
                    }

                    pstmt_2.close();
                } else label_error.setText("FIN does not exist!");
                fin_text_field.setText("");
                populateTableView();
                dbConnection.close();

            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }

    public void searchOnAction(ActionEvent e) {
        DatabaseConnection connection = new DatabaseConnection();
        try {
            Connection dbConnection = connection.getDatabaseConnection();
            List<String> conditions = new ArrayList<>();
            List<Object> parameters = new ArrayList<>();

            if (!fin_text_field.getText().isEmpty()) {
                conditions.add("\"FIN\" LIKE ?");
                parameters.add("%" + fin_text_field.getText() + "%");
            }
            if (!name_text_field.getText().isEmpty()) {
                conditions.add("\"Name\" LIKE ?");
                parameters.add("%" + name_text_field.getText() + "%");
            }
            if (!surname_text_field.getText().isEmpty()) {
                conditions.add("\"Surname\" LIKE ?");
                parameters.add("%" + surname_text_field.getText() + "%");
            }
            if (!phone_text_field.getText().isEmpty()) {
                conditions.add("\"Phone Number\" LIKE ?"); // Enclose column name in backticks
                parameters.add("%" + phone_text_field.getText() + "%");
            }
            if (!job_text_field.getText().isEmpty()) {
                conditions.add("\"Job title\" LIKE ?"); // Enclose column name in backticks
                parameters.add("%" + job_text_field.getText() + "%");
            }
            if (!address_text_field.getText().isEmpty()) {
                conditions.add("\"Address\" LIKE ?");
                parameters.add("%" + address_text_field.getText() + "%");
            }
            if (!age_text_field.getText().isEmpty()) {
                conditions.add("\"Age\" = ?");
                parameters.add(Integer.parseInt(age_text_field.getText()));
            }

            String whereClause = "";
            if (!conditions.isEmpty()) {
                whereClause = " WHERE " + String.join(" AND ", conditions);
            }

            String query = "SELECT * FROM public.\"EmployeesInformation\"" + whereClause;
            PreparedStatement pstmt = dbConnection.prepareStatement(query);

            for (int i = 0; i < parameters.size(); i++) {
                pstmt.setObject(i + 1, parameters.get(i));
            }

            ResultSet rs = pstmt.executeQuery();

            table_view.getItems().clear();

            if (!rs.next()) {
                label_error.setText("No data found!");
            } else {
                do {
                    table_view.getItems().add(new employee(
                            rs.getString("FIN"),
                            rs.getString("Name"),
                            rs.getString("Surname"),
                            rs.getString("Phone Number"),
                            rs.getString("Job title"),
                            rs.getString("Address"),
                            rs.getInt("Age")
                    ));
                } while (rs.next());
            }

            rs.close();
            pstmt.close();
            dbConnection.close();

        } catch (SQLException ex) {
            ex.printStackTrace();
        } catch (NumberFormatException ex) {
            ex.printStackTrace();
        }
    }

    public void resetAction (ActionEvent e) {
        populateTableView();
    }

    public void editAction(ActionEvent e) {
        DatabaseConnection connection = new DatabaseConnection();
        if (fin_text_field.getText().isEmpty()) {
            label_error.setText("FIN cannot be empty!");
        } else {
            try {
                Connection dbConnection = connection.getDatabaseConnection();

                String name = name_text_field.getText();
                String surname = surname_text_field.getText();
                String phone = phone_text_field.getText();
                String job = job_text_field.getText();
                String address = address_text_field.getText();
                int age;
                try {
                    age = Integer.parseInt(age_text_field.getText());
                } catch (NumberFormatException ex) {
                    age = 0;
                }

                String query = "UPDATE public.\"EmployeesInformation\" SET ";
                List<String> updateFields = new ArrayList<>();
                List<Object> parameters = new ArrayList<>();

                if (!name.isEmpty()) {
                    updateFields.add("\"Name\"=?");
                    parameters.add(name);
                }
                if (!surname.isEmpty()) {
                    updateFields.add("\"Surname\"=?");
                    parameters.add(surname);
                }
                if (!phone.isEmpty()) {
                    updateFields.add("\"Phone Number\"=?");
                    parameters.add(phone);
                }
                if (!job.isEmpty()) {
                    updateFields.add("\"Job title\"=?");
                    parameters.add(job);
                }
                if (!address.isEmpty()) {
                    updateFields.add("\"Address\"=?");
                    parameters.add(address);
                }
                if (age != 0) {
                    updateFields.add("\"Age\"=?");
                    parameters.add(age);
                }

                if (!updateFields.isEmpty()) {
                    query += String.join(", ", updateFields);
                    query += " WHERE \"FIN\"=?";
                    PreparedStatement pstmt = dbConnection.prepareStatement(query);

                    int i = 1;
                    for (Object parameter : parameters) {
                        pstmt.setObject(i++, parameter);
                    }
                    pstmt.setString(i, fin_text_field.getText());

                    int rowsAffected = pstmt.executeUpdate();

                    if (rowsAffected > 0) {
                        label_success.setText("Record updated successfully!");
                        label_error.setText("");
                        fin_text_field.setText("");
                        name_text_field.setText("");
                        surname_text_field.setText("");
                        phone_text_field.setText("");
                        job_text_field.setText("");
                        address_text_field.setText("");
                        age_text_field.setText("");

                        table_view.getItems().clear();
                        populateTableView();
                    } else {
                        label_error.setText("No record found with the provided FIN!");
                    }

                    pstmt.close();
                } else {
                    label_error.setText("No fields to update!");
                }

                dbConnection.close();

            } catch (SQLException ex) {
                ex.printStackTrace();
            } catch (NumberFormatException ex) {
                ex.printStackTrace();
            }
        }
    }
}
