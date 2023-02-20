//SAIM ALI
//SPRING 2021 C# OO ASSIGNMENT

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Comparator;
import java.util.stream.Collectors;

import dvd.DVD;
import dvd.DVDController;


public class Main{
public static void main(String[] args) {
    DVDController catalog = new DVDController();

    // Restore catalog from file
    try {
        catalog.restoreCatalog("Catalog.txt");
    } catch (IOException e) {
        System.err.println("Error restoring catalog from file: " + e.getMessage());
    }

    // Add a new DVD
    catalog.addDVD("A new Movie", "Horror", 90, 1993, 19.30);

    // Remove a DVD
    // catalog.removeDVD();

    // Edit DVD information
    // catalog.editInfo();

    // Display catalog sorted by year
    System.out.println("Catalog sorted by year:");
    List<DVD> sortedDVDs = catalog.displayByYear();
    for (DVD dvd : sortedDVDs) {
        System.out.println(dvd.getTitle() + " (" + dvd.getYear() + ")");
    }
    System.out.println();

    // Display DVDs by category
    System.out.println("DVDs in Drama category:");
    List<DVD> dramaDVDs = catalog.displayByCat("Drama");
    for (DVD dvd : dramaDVDs) {
        System.out.println(dvd.getTitle() + " (" + dvd.getYear() + ")");
    }

    // Save catalog to file
    try {
        catalog.saveCatalog("Catalog.txt");
    } catch (IOException e) {
        System.err.println("Error saving catalog to file: " + e.getMessage());
    }
  
}
}