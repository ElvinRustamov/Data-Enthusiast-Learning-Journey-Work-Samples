package com.example.server;

import javafx.fxml.FXML;
import javafx.scene.control.TextArea;

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

    public ServerController() throws IOException {
        System.out.println("Server Started");
    }

    @FXML
    private TextArea text_area;


    public void clientThread() {

        new Thread(() -> {
            try {

                while (true) {
                    Socket clientSocket = serverSocket.accept();
                    System.out.println("Client connected: " + clientSocket);
                    Scanner scanner = new Scanner(clientSocket.getInputStream());

                    String name = scanner.nextLine();
                    String message = scanner.nextLine();

//                    Thread.sleep(3000);
                    String md5_message = getMD5(message);
                    PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                    out.println(md5_message);
                    System.out.println(md5_message);

                    text_area.appendText(name + ": " + message + "\n");
                    System.out.println("Client Info: " + name + ": " + message + "\n");
                    clientSocket.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }

    public void initialize(){
        clientThread();
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
