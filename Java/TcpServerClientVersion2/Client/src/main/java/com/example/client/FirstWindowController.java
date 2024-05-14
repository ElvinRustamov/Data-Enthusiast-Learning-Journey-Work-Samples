package com.example.client;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class FirstWindowController {

    public void createNewClientAction (ActionEvent event) {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("client.fxml"));
        Parent root = null;
        try {
            root = loader.load();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        ClientController controller = loader.getController();

        Stage client = new Stage();
        Scene scene = new Scene(root);
        client.setScene(scene);
        client.setTitle("Client");
        client.show();
    }
}
