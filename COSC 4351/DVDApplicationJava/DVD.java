package dvd;
public class DVD {
    private String title;
    private String category;
    private int runningTime;
    private int year;
    private double price;

    public DVD(String title, String category, int runningTime, int year, double price) {
        this.title = title;
        this.category = category;
        this.runningTime = runningTime;
        this.year = year;
        this.price = price;
    }

    public String getTitle() {
        return title;
    }

    public String getCategory() {
        return category;
    }

    public int getRunningTime() {
        return runningTime;
    }

    public int getYear() {
        return year;
    }

    public double getPrice() {
        return price;
    }

    public void setRunningTime(int runningTime) {
        this.runningTime = runningTime;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public void setPrice(double price) {
        this.price = price;
    }
}
