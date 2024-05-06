module com.example.tcpserverclient {
    requires javafx.controls;
    requires javafx.fxml;

    requires com.dlsc.formsfx;

    opens com.example.tcpserverclient to javafx.fxml;
    exports com.example.tcpserverclient;
}