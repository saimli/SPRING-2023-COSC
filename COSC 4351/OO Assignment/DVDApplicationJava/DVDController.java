package dvd;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Comparator;
import java.util.stream.Collectors;


public class DVDController {
    private List<DVD> DVDs;

    public DVDController() {
        DVDs = new ArrayList<>();
    }

    public void restoreCatalog(String filePath) throws IOException {
        Scanner scanner = new Scanner(new File(filePath));
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] fields = line.split(",");
            String title = fields[0].trim();
            String category = fields[1].trim();
            int runningTime = Integer.parseInt(fields[2].replace(" Mins.", "").trim());
            int year = Integer.parseInt(fields[3].trim());
            double price = Double.parseDouble(fields[4].trim());
            DVDs.add(new DVD(title, category, runningTime, year, price));
        }
        scanner.close();
    }

    public void saveCatalog(String filePath) throws IOException {
        FileWriter writer = new FileWriter(filePath);
        for (DVD dvd : DVDs) {
            writer.write(String.format("%s, %s, %d Mins., %d, %.2f\n",
                    dvd.getTitle(), dvd.getCategory(), dvd.getRunningTime(), dvd.getYear(), dvd.getPrice()));
        }
        writer.close();
    }

    public void addDVD(String title, String category, int runningTime, int year, double price) {
        DVDs.add(new DVD(title, category, runningTime, year, price));
    }

    public void removeDVD(String title, String category) {
        DVD dvdToRemove = null;
        for (DVD dvd : DVDs) {
            if (dvd.getTitle().equals(title) && dvd.getCategory().equals(category)) {
                dvdToRemove = dvd;
                break;
            }
        }
        if (dvdToRemove != null) {
            DVDs.remove(dvdToRemove);
        }
    }

    public void editInfo(String title, String category, int runningTime, int year, double price) {
        for (DVD dvd : DVDs) {
            if (dvd.getTitle().equals(title) && dvd.getCategory().equals(category)) {
                dvd.setRunningTime(runningTime);
                dvd.setYear(year);
                dvd.setPrice(price);
                break;
            }
        }
    }

    public List<DVD> displayByCat(String category) {
        List<DVD> dvdsInCategory = new ArrayList<>();
        for (DVD dvd : DVDs) {
            if (dvd.getCategory().equals(category)) {
                dvdsInCategory.add(dvd);
            }
        }
        return dvdsInCategory;
    }

    public List<DVD> displayByYear() {
    return DVDs.stream().sorted(Comparator.comparing(DVD::getYear)).collect(Collectors.toList());
}



}
