module com.example.server {
    requires javafx.controls;
    requires javafx.fxml;

    requires com.dlsc.formsfx;

    opens com.example.server to javafx.fxml;
    exports com.example.server;
}