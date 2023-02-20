using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class DVDController
{
    private List<DVD> DVDs;

    public DVDController()
    {
        DVDs = new List<DVD>();
    }

    public void RestoreCatalog(string filePath)
    {
        string[] lines = File.ReadAllLines(filePath);
        foreach (string line in lines)
        {
            // string[] fields = line.Split(','); doesnt split input correctly
            string[] fields = line.Split(',').Select(f => f.Trim()).ToArray();

            string title = fields[0];
            string category = fields[1];
            int runningTime = int.Parse(fields[2].Replace(" Mins.", ""));
            int year = int.Parse(fields[3]);
            decimal price = decimal.Parse(fields[4]);
            DVDs.Add(new DVD(title, category, runningTime, year, price));
        }
    }

    public void SaveCatalog(string filePath)
    {
        using (StreamWriter writer = new StreamWriter(filePath))
        {
            foreach (DVD dvd in DVDs)
            {
                writer.WriteLine($"{dvd.Title}, {dvd.Category}, {dvd.RunningTime} Mins., {dvd.Year}, {dvd.Price}");
            }
        }
    }

    public void AddDVD(string title, string category, int runningTime, int year, decimal price)
    {
        DVDs.Add(new DVD(title, category, runningTime, year, price));
    }

    public void RemoveDVD(string title, string category)
    {
        DVD dvdToRemove = null;
        foreach (DVD dvd in DVDs)
        {
            if (dvd.Title == title && dvd.Category == category)
            {
                dvdToRemove = dvd;
                break;
            }
        }
        if (dvdToRemove != null)
        {
            DVDs.Remove(dvdToRemove);
        }
    }

    public void editInfo(string title, string category, int runningTime, int year, decimal price)
    {
        foreach (DVD dvd in DVDs)
        {
            if (dvd.Title == title && dvd.Category == category)
            {
                dvd.RunningTime = runningTime;
                dvd.Year = year;
                dvd.Price = price;
                break;
            }
        }
    }

    public List<DVD> DisplayByCat(string category)
    {
        List<DVD> dvdsInCategory = new List<DVD>();
        foreach (DVD dvd in DVDs)
        {
            if (dvd.Category == category)
            {
                dvdsInCategory.Add(dvd);
            }
        }
        return dvdsInCategory;
    }

    public List<DVD> DisplayByYear()
    {
        return DVDs.OrderBy(dvd => dvd.Year).ToList();
    }
}