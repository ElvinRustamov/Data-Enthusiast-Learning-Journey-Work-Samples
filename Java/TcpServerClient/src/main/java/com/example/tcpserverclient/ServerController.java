package com.example.tcpserverclient;


import javafx.application.Platform;
import javafx.beans.property.ReadOnlyStringWrapper;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextArea;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class ServerController {
    public static final int PORT_NUMBER = 12345;
    private ServerSocket serverSocket = new ServerSocket(PORT_NUMBER);

    String clientInfo = "";

    @FXML
    private TextArea text_area;

    public ServerController() throws IOException {
        System.out.println("Server Started");
    }

    public void createClientAction(ActionEvent actionEvent) {
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

        new Thread(() -> {
            try {
                while (true) {
                    Socket clientSocket = serverSocket.accept();
                    System.out.println("Client connected: " + clientSocket);
                    Scanner scanner = new Scanner(clientSocket.getInputStream());
                    String message = scanner.nextLine();
                    String name = scanner.nextLine();

                    String md5_message = getMD5(message);
                    PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                    out.println(md5_message);

                    clientInfo += name + " : " + message + "\n";
                    text_area.setText(clientInfo);



                    clientSocket.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }

    private String getMD5(String message) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            md.update(message.getBytes());
            byte[] digest = md.digest();
            StringBuilder sb = new StringBuilder();
            for (byte b : digest) {
                sb.append(String.format("%02x", b & 0xff));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }
}
