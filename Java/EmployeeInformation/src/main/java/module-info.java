module com.example.employeeinformation {
    requires javafx.controls;
    requires javafx.fxml;

    requires com.dlsc.formsfx;
    requires java.sql;

    opens com.example.employeeinformation to javafx.fxml;
    exports com.example.employeeinformation;
}