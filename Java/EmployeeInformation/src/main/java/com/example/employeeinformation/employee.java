package com.example.employeeinformation;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class employee {
    private final SimpleStringProperty fin;
    private final SimpleStringProperty name;
    private final SimpleStringProperty surname;
    private final SimpleStringProperty phoneNumber;
    private final SimpleStringProperty jobTitle;
    private final SimpleStringProperty address;
    private final SimpleIntegerProperty age;

    public employee(String fin, String name, String surname, String phoneNumber, String jobTitle, String address, int age) {
        this.fin = new SimpleStringProperty(fin);
        this.name = new SimpleStringProperty(name);
        this.surname = new SimpleStringProperty(surname);
        this.phoneNumber = new SimpleStringProperty(phoneNumber);
        this.jobTitle = new SimpleStringProperty(jobTitle);
        this.address = new SimpleStringProperty(address);
        this.age = new SimpleIntegerProperty(age);
    }

    public StringProperty finProperty() {
        return fin;
    }

    public StringProperty nameProperty() {
        return name;
    }

    public StringProperty surnameProperty() {
        return surname;
    }

    public StringProperty phoneNumberProperty() {
        return phoneNumber;
    }

    public StringProperty jobTitleProperty() {
        return jobTitle;
    }

    public StringProperty addressProperty() {
        return address;
    }

    public IntegerProperty ageProperty() {
        return age;
    }

    public String getFin() {
        return fin.get();
    }

    public String getName() {
        return name.get();
    }

    public String getSurname() {
        return surname.get();
    }

    public String getPhoneNumber() {
        return phoneNumber.get();
    }

    public String getJobTitle() {
        return jobTitle.get();
    }

    public String getAddress() {
        return address.get();
    }

    public int getAge() {
        return age.get();
    }
}