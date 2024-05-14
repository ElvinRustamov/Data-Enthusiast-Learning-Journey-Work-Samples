package com.example.piechart;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.chart.PieChart;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Arc;
import javafx.scene.shape.ArcType;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;

import java.net.DatagramPacket;
import java.net.URL;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ResourceBundle;

public class pieChartController implements Initializable {

    @FXML
    private ComboBox<Integer> year_combobox;

    @FXML
    private ComboBox<String> category_combobox;

    @FXML
    private Label label_error;

    @FXML
    private Pane custom_pie_chart_pane;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        for (int year = 2000; year <= 2023; year++) {
            year_combobox.getItems().add(year);
        }

        category_combobox.getItems().addAll("Population (Urban Places and Rural Places)", "Marriage and Divorce", "Birth and Death");
    }

    public void submit_buttonOnAction(ActionEvent e) throws SQLException {
        String table_name;
        String category_name;
        String year;

        category_name = category_combobox.getValue();
        year = String.valueOf(year_combobox.getValue());

        if (category_name.contains("Birth")) {
            table_name = "populationBirthAndDeath";
        } else if (category_name.contains("Marriage")) {
            table_name = "populationMarriageAndDivorce";
        } else {
            table_name = "populationPerYear";
        }

        DatabaseConnection connection = new DatabaseConnection();
        Connection dbConnection = connection.getDatabaseConnection();

        String query = "SELECT * FROM " + table_name + " WHERE year = ?";
        PreparedStatement statement = dbConnection.prepareStatement(query);
        statement.setString(1, year);
        ResultSet resultSet = statement.executeQuery();

        ObservableList<PieChart.Data> pieChartData = FXCollections.observableArrayList();

        int totalPopulation = 0;
        boolean hasData = false;

        while (resultSet.next()) {
            hasData = true;
            for (int i = 2; i <= resultSet.getMetaData().getColumnCount(); i++) {
                if (!resultSet.getMetaData().getColumnName(i).equals("year")) {
                    double population = resultSet.getDouble(i);
                    pieChartData.add(new PieChart.Data(resultSet.getMetaData().getColumnName(i), population));
                    totalPopulation += population;
                }
            }
        }

        if (!hasData) {
            label_error.setText("No information found for the selected year and category.");
        } else {
            label_error.setText("");
            custom_pie_chart_pane.getChildren().clear();

            double startAngle = 0;
            for (PieChart.Data data : pieChartData) {
                double percentage = (data.getPieValue() / totalPopulation) * 100;
                data.setName(data.getName() + " (" + String.format("%.2f", percentage) + "%)");

                javafx.scene.shape.Arc arc = new javafx.scene.shape.Arc();
                arc.setCenterX(custom_pie_chart_pane.getWidth() / 2);
                arc.setCenterY(custom_pie_chart_pane.getHeight() / 2);
                arc.setRadiusX(Math.min(custom_pie_chart_pane.getWidth(), custom_pie_chart_pane.getHeight()) * 0.4);
                arc.setRadiusY(Math.min(custom_pie_chart_pane.getWidth(), custom_pie_chart_pane.getHeight()) * 0.4);
                arc.setStartAngle(startAngle);
                arc.setLength((data.getPieValue() / totalPopulation) * 360);
                arc.setType(javafx.scene.shape.ArcType.ROUND);
                arc.setFill(Color.rgb((int)(Math.random()*256), (int)(Math.random()*256), (int)(Math.random()*256)));

                Text label = new Text(data.getName());
                label.setFill(Color.BLACK);

                double labelAngle = startAngle + ((data.getPieValue() / totalPopulation) * 360) / 2;
                double labelRadius = Math.min(custom_pie_chart_pane.getWidth(), custom_pie_chart_pane.getHeight()) * 0.4;
                double labelX = arc.getCenterX() + labelRadius * Math.cos(Math.toRadians(labelAngle));
                double labelY = arc.getCenterY() + labelRadius * Math.sin(Math.toRadians(labelAngle));

                if (labelX < custom_pie_chart_pane.getWidth() / 2) {
                    labelX -= label.getLayoutBounds().getWidth();
                }
                if (labelY > custom_pie_chart_pane.getHeight() / 2) {
                    labelY += label.getLayoutBounds().getHeight() / 2;
                }

                label.setLayoutX(labelX);
                label.setLayoutY(labelY);

                startAngle += (data.getPieValue() / totalPopulation) * 360;

                custom_pie_chart_pane.getChildren().addAll(arc, label);
            }
        }

        connection.closeDatabaseConnection();
    }
}