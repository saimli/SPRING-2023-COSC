using System;



class DVD
{
    public string Title { get; set; }
    public string Category { get; set; }
    public int RunningTime { get; set; }
    public int Year { get; set; }
    public decimal Price { get; set; }

    public DVD(string title, string category, int runningTime, int year, decimal price)
    {
        Title = title;
        Category = category;
        RunningTime = runningTime;
        Year = year;
        Price = price;
    }
}
