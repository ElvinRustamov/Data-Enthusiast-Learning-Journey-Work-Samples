package com.example.client;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import java.io.*;
import java.net.Socket;

public class ClientController {

    private Socket socket;
    private PrintWriter writer;
    private BufferedReader reader;


    @FXML
    private TextField ip_address_text_field;

    @FXML
    private TextField port_text_field;

    @FXML
    private TextField name_text_field;

    @FXML
    private TextField message_text_field;

    @FXML
    private Label output_label;

    @FXML
    private Label error_label;

    @FXML
    private Label result_label;



    public void connectButtonOnAction(ActionEvent event) {
        String ip = ip_address_text_field.getText();
        int port = Integer.parseInt(port_text_field.getText());

        if (!ip.isEmpty() || !name_text_field.getText().isEmpty() || port != 0) {
            try {
                socket = new Socket(ip, port);
                writer = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()), true);
                reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));

                result_label.setText("Connected to the server.");
                message_text_field.setDisable(false);

                receiveMd5(new Md5Callback() {
                    @Override
                    public void onMd5Received(String md5) {
                        Platform.runLater(() -> {
                            System.out.println("in callback: " + md5);
                            output_label.setText(md5);
                        });
                    }
                });

            } catch (IOException e) {
                throw new RuntimeException(e);
            }


        } else error_label.setText("Fill all the fields!");

    }

    public void convertButtonOnAction(ActionEvent event) {
        String name = name_text_field.getText();
        String message = message_text_field.getText();

        writer.println(name);
        writer.println(message);


    }

    public interface Md5Callback {
        void onMd5Received(String md5);
    }

    public void receiveMd5(Md5Callback callback) {
        new Thread(() -> {
            try {
                String m;
                while ((m = reader.readLine()) != null) {
                    callback.onMd5Received(m);
                    System.out.println("Received MD5: " + m);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }

}
