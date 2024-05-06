package com.example.tcpserverclient;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class ClientController {


    @FXML
    private TextField name_text_field;

    @FXML
    private TextField message_text_field;

    @FXML
    private Label md5_message;

    Client client;
    public void connect(ActionEvent event) {
        String name = name_text_field.getText() ;
        String message = message_text_field.getText();

        client = new Client(message, name);
    }

    public void convertAction (ActionEvent event) {
        String md5 = client.printMd5Message();
        System.out.println("Md5: " + md5);
        md5_message.setText(md5);

        }
}

