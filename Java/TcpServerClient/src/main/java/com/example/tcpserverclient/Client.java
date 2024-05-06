package com.example.tcpserverclient;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Vector;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Vector;
import java.util.concurrent.atomic.AtomicReference;

public class Client {
    private Socket socket;
    private PrintWriter writer;
    private BufferedReader reader;
    public String message = "";
    public String name = "";
    private String md5message;

    public Client(String message, String name) {
        this.message = message;
        this.name = name;

        try {
            socket = new Socket("localhost", ServerController.PORT_NUMBER);
            writer = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()), true);
            reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            System.out.println("Client connected");

            writer.println(message);
            writer.println(name);

            receiveMd5(new Md5Callback() {
                @Override
                public void onMd5Received(String md5) {
                    System.out.println("in callback: " + md5);
                    md5message = md5;
                }
            });

        } catch (IOException e) {
            throw new RuntimeException(e);
        }

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

    public String printMd5Message() {
        System.out.println("Md5 received function: " + md5message);
        return md5message;
    }
}



